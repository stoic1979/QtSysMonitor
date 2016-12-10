#include <QDebug>
#include <QTextStream>

#include "qfilelogger.h"

static QFileLogger* instance;

QFileLogger::QFileLogger(QString filepath) : filepath(filepath),  file(filepath)
{
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << "[QFileLogger] :: failed to open log file";
    }
}

QFileLogger* QFileLogger::Instance() {
    return instance;
}

QFileLogger* QFileLogger::CreateLogger(QString filepath) {
    if(!instance) {
        instance = new QFileLogger(filepath);
    }

    return instance;
}


void QFileLogger::Debug(const char* msg) {

    QTextStream out(&file);

    out << msg << "\r\n";
}
