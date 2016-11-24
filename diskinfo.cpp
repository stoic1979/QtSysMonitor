#include "diskinfo.h"

#include <QDebug>

DiskInfo::DiskInfo(QObject *parent) : QObject(parent)
{
    // pass
}

/**
 * @brief DiskInfo::getDisksInfo
 *
 * Function will fetch disks info
 * and emit signal with disks info
 */
void DiskInfo::getDisksInfo() {

    qDebug() << "[DiskInfo] getting disks' info...";

    // ToDo: emit signal with disks info
}
