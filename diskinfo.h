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

signals:

public slots:
};

#endif // DISKINFO_H
