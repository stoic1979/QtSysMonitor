#include "systemutil.h"
#include <QDebug>
#include <QStorageInfo>

/**
 * @brief SystemUtil::SystemUtil
 * @param parent
 * Constructor to initialize variables
 */
SystemUtil::SystemUtil( QObject *parent )
    : QObject( parent )
{

    mTopProcess      =  new QProcess(parent);
    mNetstatProcess  =  new QProcess(parent);

    mEnv             =  QProcess::systemEnvironment();
    //---------------------------------------------------------//
    // Note:-
    // top command requires the value of  TERM environment variable
    // for execution of the process
    //
    // top command contains maximum 512 characters in single row and
    // hence we need to redefine COLUMNS environment variable also
    //
    //---------------------------------------------------------//
    mEnv << "TERM=vt100" << "COLUMNS=512";

    mTopProcess -> setEnvironment( mEnv );

}


/**
 * @brief SystemUtil::~SystemUtil
 * Destructor
 */
SystemUtil::~SystemUtil(){
    delete mTopProcess;
    delete mNetstatProcess;
}

/**
 * @brief SystemUtil::getProcessesList
 * @param processList        - contains list of Processes
 * @return exit_status
 *
 * Execute top process to analyze the current system status
 * and populate the processList with Process objects
 */
int SystemUtil::getProcessesList(QList<Process> *processList){

    qDebug() <<"Getting Process List . . . . . . . . . ";

    mProcess = "top";

    //---------------------------------------------------------//
    // -b        for batch output
    // -n        for number of iterations
    //---------------------------------------------------------//
    mArguments.clear();
    mArguments << "-b" << "-n" << "1" ;

    mTopProcess -> start( mProcess , mArguments );

    //---------------------------------------------------------//
    // to check whether mTopProcess has started or not
    //---------------------------------------------------------//
    if( !mTopProcess->waitForStarted() ) {
        qDebug() << "ERROR : " << mTopProcess->error();
    }

    mTopProcess->waitForFinished() ;

    return parseProcesses(processList);

}

/**
 * @brief SystemUtil::parseProcesses
 * @param processList
 * @return exit_status
 *
 * takes the output of top command, split it and store it in Process data structure
 * appends the process to processList
 */
int SystemUtil::parseProcesses(QList<Process> *processList){

    mOutputString.clear();
    mOutputString = QString( mTopProcess -> readAll() );

    mOutputList.clear();
    mOutputList = mOutputString.split('\n' , QString::SkipEmptyParts );

    Process p;
    //---------------------------------------------------------//
    // loop start from 9 because mOutputList.at( 9 )
    // contains the first process in the list
    //---------------------------------------------------------//
    for(int  i = 9 ; i < mOutputList.size() ; i++ ){

        QString str = mOutputList.at( i ) ;

        //---------------------------------------------------------//
        // splits one process string on the basis of whitespaces.
        //---------------------------------------------------------//
        QStringList splittedString = str.split( QRegExp("\\s"), QString::SkipEmptyParts );

        //------------------------------------------------------------------//
        //splits the numerical value of memory from string on the basis of m
        //------------------------------------------------------------------//
        QStringList memValue = splittedString[ 5 ].split( QRegExp("m"), QString::SkipEmptyParts );

        QString pName   = splittedString.last() ;
        QString user    = splittedString[ 1 ] ;
        quint64 pID     = splittedString[ 0 ].toLong();
        float cpuUsage  = splittedString[ 6 ].toDouble();
        double memUsage = memValue[0].toDouble();

        p.setProcessId(pID);
        p.setCpuUsage(cpuUsage);
        p.setMemoryUsage(memUsage);
        p.setProcessName(pName);
        p.setUser(user);

        processList->append( p );

    }

    return ST_SUCCESS;

}

/**
 * @brief SystemUtil::getDiskList
 * @param diskList           - contains list of Disks
 * @return exit_status
 *
 * Analyze the details of disks that are mounted on the system
 * and poplutes the diskList with Disk object
 */
int SystemUtil::getDiskList(QList<Disk> *diskList){

    qDebug() <<"Getting Disk List . . . . . . . . . ";

    Disk d;
    foreach ( const QStorageInfo &disk, QStorageInfo::mountedVolumes()) {
        if( disk.isValid() && disk.isReady() ){
            if( !disk.isReadOnly() ){

                d.setName(disk.displayName());
                d.setRootPath(disk.rootPath());
                d.setAvailableBytes(disk.bytesAvailable());
                d.setTotalBytes(disk.bytesTotal());
                d.setFileSystemType(disk.fileSystemType());
                d.setDevice(disk.device());

                diskList->append(d);

            }
        }
    }

    return ST_SUCCESS;
}


int SystemUtil::getSocketList(QList<NetworkSocket> *socketList){

    qDebug() <<"Getting Socket List . . . . . . . . . ";

    mProcess = "netstat";

    mArguments.clear();
    mArguments << "-a" << "-p" << "--inet";

    mNetstatProcess->start(mProcess, mArguments);

    //---------------------------------------------------------//
    // to check whether mNetstatProcess has started or not
    //---------------------------------------------------------//
    if( !mNetstatProcess->waitForStarted() ) {
        qDebug() << "ERROR : " << mNetstatProcess->error();
    }

    mNetstatProcess->waitForFinished();

    return parseSockets(socketList);
}


/**
 * @brief SystemUtil::parseSockets
 * @param socketList
 * @return exit_status
 *
 * takes the output of netstat command, split it and store it in NetworkSocket data structure
 * appends the process to socketList
 */
int SystemUtil::parseSockets(QList<NetworkSocket> *socketList){

    mOutputString.clear();
    mOutputString = QString( mNetstatProcess -> readAll() );

    mOutputList.clear();
    mOutputList = mOutputString.split('\n' , QString::SkipEmptyParts );

    NetworkSocket s;

    //---------------------------------------------------------//
    // loop start from 2 because mOutputList.at( 2 )
    // contains the first socket information in the list
    //---------------------------------------------------------//
    for(int i = 2; i < mOutputList.size(); i++) {


        QString str = mOutputList.at( i ) ;

        //---------------------------------------------------------//
        // splits one socket string on the basis of whitespaces.
        //---------------------------------------------------------//
        QStringList splittedString = str.split( QRegExp("\\s"), QString::SkipEmptyParts );

        QString  ProtocolType   = splittedString.at(0);
        quint64  ReceiveQ       = splittedString.at(1).toLong();
        quint64  SendQ          = splittedString.at(2).toLong();
        QString  LocalAddress   = splittedString.at(3);
        QString  ForeignAddress = splittedString.at(4);

        QString  State;
        quint64  PID;
        QString  ProgramName;

        //------------------------------------------------------------//
        // Size of splittedString should be 7
        // if it is not 7, then it means that one column value is missing
        // and that column in state columns
        //------------------------------------------------------------//
        if(splittedString.size() < 7) {
            State = "";
        } else {
            State = splittedString.at(5);
        }

        //------------------------------------------------------------//
        // If splittedString.last value is equal to "-"
        // this implies that no program is using it
        //------------------------------------------------------------//
        if(splittedString.last() == "-") {
            PID         = 0L;
            ProgramName = "";
        } else {
            QString     lastColumnValue     = splittedString.last();
            QStringList splittedLastColumn  = lastColumnValue.split(QRegExp("/"));

            PID         = splittedLastColumn.at(0).toLong();
            ProgramName = splittedLastColumn.at(1);
        }

        s.setProtocolType( ProtocolType);
        s.setReceiveQ( ReceiveQ);
        s.setSendQ( SendQ);
        s.setLocalAddress( LocalAddress);
        s.setForeignAddress( ForeignAddress);
        s.setState( State);
        s.setPID( PID);
        s.setProgramName( ProgramName);

        socketList->append(s);

    }

    return ST_SUCCESS;
}

/**
 * @brief SystemUtil::showBatteryDetails
 *
 * Shows the battery details.
 * Reads from the file "/sys/class/power_supply/BAT0/uevent"
 */
void SystemUtil::showBatteryDetails() {

    QFile batteryDetail(QString("/sys/class/power_supply/BAT0/uevent"));
    batteryDetail.open(QIODevice::ReadOnly);

    QString str(batteryDetail.readAll());
    QStringList strList = str.split('\n',QString::SkipEmptyParts);
    BatteryInfo b;

    for( int i = 0 ; i < strList.size() ; i++ ){
        QString str = strList.at( i );
        QStringList splittedString = str.split('=');

        switch (i) {
        case 0: b.setName(splittedString.at(1));
            break;
        case 1: b.setStatus(splittedString.at(1));
            break;
        case 2: b.setSupplyPresent(splittedString.at(1).toLong());
            break;
        case 3: b.setSupplyTechnology(splittedString.at(1));
            break;
        case 4: b.setSupplyCycleCount(splittedString.at(1).toLong());
            break;
        case 5: b.setSupplyVoltageMinDesign(splittedString.at(1).toLong());
            break;
        case 6: b.setSupplyVoltageNow(splittedString.at(1).toLong());
            break;
        case 7: b.setSupplyCurrentNow(splittedString.at(1).toLong());
            break;
        case 8: b.setSupplyChargeFullDesign(splittedString.at(1).toLong());
            break;
        case 9: b.setSupplyChargeFull(splittedString.at(1).toLong());
            break;
        case 10: b.setSupplyChargeNow(splittedString.at(1).toLong());
            break;
        case 11: b.setSupplyCapacity(splittedString.at(1).toLong());
            break;
        case 12: b.setSupplyCapacityLevel(splittedString.at(1));
            break;
        case 13: b.setSupplyModelName(splittedString.at(1));
            break;
        case 14: b.setSupplyManufacturer(splittedString.at(1));
        default:
            break;
        }
    }

    b.showInfo();


}
