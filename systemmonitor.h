#ifndef SYSTEMMONITOR_H
#define SYSTEMMONITOR_H

#include <QObject>

class SystemMonitor : public QObject
{
    Q_OBJECT
public:
    explicit SystemMonitor(QObject *parent = 0);

signals:

public slots:
};

#endif // SYSTEMMONITOR_H