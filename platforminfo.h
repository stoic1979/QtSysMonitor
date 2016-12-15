#ifndef PLATFORMINFO_H
#define PLATFORMINFO_H

#include <QObject>

class PlatformInfo : public QObject
{
    Q_OBJECT
public:
    explicit PlatformInfo(QObject *parent = 0);

    QString getOsName();
    QString getCpuArchitecture();

signals:

public slots:
};

#endif // PLATFORMINFO_H
