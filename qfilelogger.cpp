#include <QDebug>

#include "qfilelogger.h"

static QFileLogger* instance;

QFileLogger::QFileLogger(QString filepath) : filepath(filepath),  file(filepath)
{
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << "[QFileLogger] :: failed to open log file";
    }
}


QFileLogger* QFileLogger::createLogger(QString filepath) {
    if(!instance) {
        instance = new QFileLogger(filepath);
    }

    return instance;
}
