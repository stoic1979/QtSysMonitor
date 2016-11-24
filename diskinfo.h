#ifndef DISKINFO_H
#define DISKINFO_H

#include <QObject>

/**
 * @brief The DiskInfo class
 *
 * Class for getting information for disks/partitions on system,
 * their total disk size, used/free space etc.
 */
class DiskInfo : public QObject
{
    Q_OBJECT
public:
    explicit DiskInfo(QObject *parent = 0);

    /**
     * @brief getDisksInfo
     * Function gets latest information about all disks
     *
     * Note:-
     * ------
     * Qt will be using platform specific source codes for
     * Linux, Mac, Windows to obtain this informaiton.
     */
    void getDisksInfo();

signals:

public slots:
};

#endif // DISKINFO_H
