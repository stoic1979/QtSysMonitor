#include "diskinfo.h"

#include <QDebug>

DiskInfo::DiskInfo(QObject *parent) : QObject(parent)
{

}


void DiskInfo::getDisksInfo() {

    qDebug() << "[DiskInfo] getting disks' info...";
}
