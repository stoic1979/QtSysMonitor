#include "systemutil.h"
#include <QDebug>

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
    mDfProcess       =  new QProcess(parent);

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
    delete mDfProcess;
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

    /**************************************************************************/
    /**************************************************************************/
    // This is necessary because top command can produce different
    // output in different platforms .
    /**************************************************************************/

    //---------------------------------------------------------//
    // headerRowIndex stores the value of index of header row,
    // so that we know where actual data starts.(from next line)
    //---------------------------------------------------------//
    int headerRowIndex = findHeaderRow();

    QString headerRow = mOutputList.at(headerRowIndex);
    QStringList splittedHeaderRow = headerRow.split(' ',QString::SkipEmptyParts );

    //---------------------------------------------------------//
    // Variables to store the indexes of headings so that actual
    // required data can be retrieved .
    //---------------------------------------------------------//
    int indexId, indexUser, indexCpu, indexMemory;

    for(int i = 0 ; i < splittedHeaderRow.size() ; i++){
        QString val = splittedHeaderRow.at(i);
        if(val.toUpper() == "PID"){
            indexId = i;
        }else if(val.toUpper() == "USER"){
            indexUser = i;
        }else if(val.toUpper() == "%CPU"){
            indexCpu = i;
        }else if(val.toUpper() == "RES"){
            indexMemory = i;
        }
    }
    /**************************************************************************/
    /**************************************************************************/

    Process p;
    //---------------------------------------------------------//
    // headerRowIndex contains the headings and hence the
    // first row with required data will be at headerRowIndex+1
    // contains the first process in the list
    //---------------------------------------------------------//
    for(int  i = headerRowIndex+1 ; i < mOutputList.size() ; i++ ){

        QString str = mOutputList.at( i ) ;

        //---------------------------------------------------------//
        // splits one process string on the basis of whitespaces.
        //---------------------------------------------------------//
        QStringList splittedString = str.split( QRegExp("\\s"), QString::SkipEmptyParts );

        //------------------------------------------------------------------//
        //splits the numerical value of memory from string on the basis of m
        //------------------------------------------------------------------//
        QStringList memValue = splittedString[ indexMemory ]
                .split( QRegExp("m"), QString::SkipEmptyParts );

        QString pName   = splittedString.last() ;
        QString user    = splittedString[ indexUser ] ;
        quint64 pID     = splittedString[ indexId ].toLongLong();
        float cpuUsage  = splittedString[ indexCpu ].toDouble();
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

    mProcess = "df";

    //---------------------------------------------------------//
    // -T        for file system type
    //---------------------------------------------------------//
    mArguments.clear();
    mArguments << "-T" ;

    mDfProcess -> start( mProcess , mArguments );

    //---------------------------------------------------------//
    // to check whether mDfProcess has started or not
    //---------------------------------------------------------//
    if( !mDfProcess->waitForStarted() ) {
        qDebug() << "ERROR : " << mDfProcess->error();
    }

    mDfProcess->waitForFinished() ;

    return parseDisks(diskList);
}

/**
 * @brief SystemUtil::parseDisks
 * @param diskList
 * @return exit_status
 *
 * takes the output of df command, split it and store it in Disk value object
 * appends the disk to diskList
 */
int SystemUtil::parseDisks(QList<Disk> *diskList){

    mOutputString.clear();
    mOutputString = QString(mDfProcess->readAll());

    mOutputList.clear();
    mOutputList = mOutputString.split(QRegExp("\n"), QString::SkipEmptyParts);

    //---------------------------------------------------------//
    // No need to find the index of header row this time because
    // the arguments forces the output of command to have header
    // row in first row mOutputList.
    //---------------------------------------------------------//
    QString headerRow = mOutputList.at(0);

    QStringList splittedHeaderRow = headerRow.split(QRegExp("\\s"), QString::SkipEmptyParts);

    int indexName, indexRootPath, indexAvailable, indexTotal, indexFileSystem, indexDevice;

    for(int i = 0; i < splittedHeaderRow.size();i++){
        bool mountOn = false;
        QString val = splittedHeaderRow.at(i);
        val = val.toUpper();

        if(val == QString("TYPE")){
            if(!mountOn){
                indexFileSystem = i;
            }else {
                indexFileSystem = i-1;
            }
        }else if(val == QString("1K-BLOCKS")) {
            if(!mountOn){
                indexTotal = i;
            }else{
                indexTotal = i - 1;
            }
        }else if(val == QString("AVAILABLE")) {
            if(!mountOn){
                indexAvailable = i;
            }else {
                indexAvailable = i - 1;
            }
        }else if(val == QString("FILESYSTEM")) {
            if(!mountOn){
                indexDevice = i;
            }else{
                indexDevice = i - 1;
            }
        }else if(val == QString("MOUNT")){
            indexRootPath = i;
            mountOn = true;
        }
    }
    indexName = indexRootPath;

    Disk d;

    for(int i = 1; i < mOutputList.size(); i++){

        QString singleRow = mOutputList.at(i);
        QStringList splittedSingleRow = singleRow.split(QRegExp("\\s"), QString::SkipEmptyParts);

        quint64 total = splittedSingleRow.at(indexTotal).toLongLong();
        quint64 available = splittedSingleRow.at(indexAvailable).toLongLong();

        d.setName(splittedSingleRow.at( indexName ));
        d.setRootPath(splittedSingleRow.at( indexRootPath ));
        d.setAvailableBytes(available);
        d.setTotalBytes(total);
        d.setDevice(splittedSingleRow.at( indexDevice ));
        d.setFileSystemType(splittedSingleRow.at( indexFileSystem));

        diskList->append(d);

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

    /**************************************************************************/
    /**************************************************************************/
    // This is necessary because netstat command can produce different
    // output in different platforms .
    /**************************************************************************/

    //---------------------------------------------------------//
    // headerRowIndex stores the value of index of header row,
    // so that we know where actual data starts.(from next line)
    //---------------------------------------------------------//
    int headerRowIndex = findNetstatHeaderRow();

    QString headerRow = mOutputList.at(headerRowIndex);
    QStringList splittedHeaderRow = headerRow.split(' ',QString::SkipEmptyParts );

    //---------------------------------------------------------//
    // Variables to store the indexes of headings so that actual
    // required data can be retrieved .
    //---------------------------------------------------------//
    int indexProto, indexReceive, indexSend, indexLAddress, indexFAddress, indexState;

    //---------------------------------------------------------//
    // To determine whether local address and foreign address
    // have appeared or not, because they both appear as "foreign" and "address"
    // as two different strings
    //---------------------------------------------------------//
    bool flagLAddress = false;
    bool flagFAddress = false;
    for(int i = 0 ; i < splittedHeaderRow.size() ; i++){
        QString val = splittedHeaderRow.at(i);
        if(val.toUpper() == "PROTO"){

            if(!flagFAddress && !flagLAddress){
                indexProto = i;
            }else{
                if(flagFAddress && flagLAddress){
                    indexProto = i - 2;
                }else if(flagLAddress || flagFAddress){
                    indexProto = i - 1;
                }
            }

        }else if(val.toUpper() == "RECV-Q"){

            if(!flagFAddress && !flagLAddress){
                indexReceive = i;
            }else{
                if(flagFAddress && flagLAddress){
                    indexReceive = i - 2;
                }else if(flagLAddress || flagFAddress){
                    indexReceive = i - 1;
                }
            }

        }else if(val.toUpper() == "SEND-Q"){

            if(!flagFAddress && !flagLAddress){
                indexSend = i;
            }else{
                if(flagFAddress && flagLAddress){
                    indexSend = i - 2;
                }else if(flagLAddress || flagFAddress){
                    indexSend = i - 1;
                }
            }

        }else if(val.toUpper() == "LOCAL"){
            flagLAddress = true;

            if(!flagFAddress && !flagLAddress){
                indexLAddress = i;
            }else{
                if(flagFAddress && flagLAddress){
                    indexFAddress = i - 2;
                }else if(flagLAddress || flagFAddress){
                    indexLAddress = i - 1;
                }
            }

        }else if(val.toUpper() == "FOREIGN"){
            flagFAddress = true;

            if(!flagFAddress && !flagLAddress){
                indexFAddress = i;
            }else{
                if(flagFAddress && flagLAddress){
                    indexFAddress = i - 2;
                }else if(flagLAddress || flagFAddress){
                    indexFAddress = i - 1;
                }
            }

        }else if(val.toUpper() == "STATE"){

            if(!flagFAddress && !flagLAddress){
                indexState = i;
            }else{
                if(flagFAddress && flagLAddress){
                    indexState = i - 2;
                }else if(flagLAddress || flagFAddress){
                    indexState = i - 1;
                }
            }

        }
    }
    /**************************************************************************/
    /**************************************************************************/


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

        QString  ProtocolType   = splittedString.at(indexProto);
        quint64  ReceiveQ       = splittedString.at(indexReceive).toLongLong();
        quint64  SendQ          = splittedString.at(indexSend).toLongLong();
        QString  LocalAddress   = splittedString.at(indexLAddress);
        QString  ForeignAddress = splittedString.at(indexFAddress);

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
            State = splittedString.at(indexState);
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

            PID         = splittedLastColumn.at(0).toLongLong();
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
        case 2: b.setSupplyPresent(splittedString.at(1).toLongLong());
            break;
        case 3: b.setSupplyTechnology(splittedString.at(1));
            break;
        case 4: b.setSupplyCycleCount(splittedString.at(1).toLongLong());
            break;
        case 5: b.setSupplyVoltageMinDesign(splittedString.at(1).toLongLong());
            break;
        case 6: b.setSupplyVoltageNow(splittedString.at(1).toLongLong());
            break;
        case 7: b.setSupplyCurrentNow(splittedString.at(1).toLongLong());
            break;
        case 8: b.setSupplyChargeFullDesign(splittedString.at(1).toLongLong());
            break;
        case 9: b.setSupplyChargeFull(splittedString.at(1).toLongLong());
            break;
        case 10: b.setSupplyChargeNow(splittedString.at(1).toLongLong());
            break;
        case 11: b.setSupplyCapacity(splittedString.at(1).toLongLong());
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

/**
 * @brief SystemUtil::findHeaderRow
 * @return index of header row
 * This functions helps to find out the first header row index
 * after which required data will be present for the top process output.
 */
int SystemUtil::findHeaderRow(){

    int iterator = 0;
    while(iterator < mOutputList.size()){

        QString singleRow = mOutputList.at(iterator);
        QStringList splittedSingleRow = singleRow.split(QRegExp("\\s"),QString::SkipEmptyParts);

        QString firstMember = splittedSingleRow.at(0);
        firstMember = firstMember.toUpper();
        if(firstMember == "PID"){
            return iterator;
        }
        iterator+=1;
    }
}

/**
 * @brief SystemUtil::findNetstatHeaderRow
 * @return
 * This functions helps to find out the first header row index
 * after which required data will be present for the netstat process output
 */
int SystemUtil::findNetstatHeaderRow(){

    int iterator = 0;
    while(iterator < mOutputList.size()){

        QString singleRow = mOutputList.at(iterator);
        QStringList splittedSingleRow = singleRow.split(QRegExp("\\s"),QString::SkipEmptyParts);

        QString firstMember = splittedSingleRow.at(0);
        firstMember = firstMember.toUpper();
        if(firstMember == "PROTO"){
            return iterator;
        }
        iterator+=1;
    }
}
