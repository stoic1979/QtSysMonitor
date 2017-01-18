#include "resourceswidget.h"

ResourcesWidget::ResourcesWidget(QTableWidget *wid, QWidget *parent) :
    QWidget(parent),
    widget(wid)
{
    connect(this, SIGNAL(refreshData()), this, SLOT(deleteAllocatedItems()));
    connect(this, SIGNAL(refreshData()), this, SLOT(populateUi()));
}

ResourcesWidget::~ResourcesWidget(){
    deleteAllocatedItems();
}

void ResourcesWidget::populateUi(){

    utilities = new SystemUtil();
    QList<NetworkSocket> socketList;

    int returnStatus = utilities->getSocketList(&socketList);

    if(returnStatus == ST_SUCCESS){
        qDebug() << "Successfully retrieved disk list. . . ";
    }else {
        qDebug() << "Problem retrieving disk list . . . . .";
    }

    widget->setRowCount(socketList.size());

    QTableWidgetItem  *protocolType;
    QTableWidgetItem  *receiveQ;
    QTableWidgetItem  *sendQ;
    QTableWidgetItem  *localAddress;
    QTableWidgetItem  *foreignAddress;
    QTableWidgetItem  *state;
    QTableWidgetItem  *pID;
    QTableWidgetItem  *programName;

    for(int i = 0 ; i < socketList.size(); i++){
        protocolType   = new QTableWidgetItem(QString(socketList.at(i).getProtocolType()));

        receiveQ       = new QTableWidgetItem(QString("%1 B").arg
                                            (QString::number(socketList.at(i).getReceiveQ())));
        sendQ          = new QTableWidgetItem(QString("%1 B").arg
                                            (QString::number(socketList.at(i).getSendQ())));
        localAddress   = new QTableWidgetItem(QString(socketList.at(i).getLocalAddress()));

        foreignAddress = new QTableWidgetItem(QString(socketList.at(i).getForeignAddress()));

        state          = new QTableWidgetItem(QString(socketList.at(i).getState()));

        pID            = new QTableWidgetItem(QString("%1").arg
                                              (QString::number(socketList.at(i).getPID())));
        programName    = new QTableWidgetItem(QString(socketList.at(i).getProgramName()));



        protocolType->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        receiveQ->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        sendQ->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        localAddress->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        foreignAddress->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        state->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        pID->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        programName->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        widget->setItem(i, 0, protocolType);
        widget->setItem(i, 1, receiveQ);
        widget->setItem(i, 2, sendQ);
        widget->setItem(i, 3, localAddress);
        widget->setItem(i, 4, foreignAddress);
        widget->setItem(i, 5, state);
        widget->setItem(i, 6, pID);
        widget->setItem(i, 7, programName);

    }

    widget->setCurrentCell(0,0);

}

void ResourcesWidget::deleteAllocatedItems(){

    for(int i = 0; i < widget->rowCount(); i++){
        for(int j = 0 ;j < widget->columnCount(); j++){
            widget->setCurrentCell(i, j);
            delete widget->currentItem();
        }
    }

}

void ResourcesWidget::refreshTimer(){
    emit refreshData();
}
