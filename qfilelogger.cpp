/*
 * -----------------------------------
 * QtSysMonitor
 * -----------------------------------
 *
 * This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * ---------------------------------------------------------------------------
 * Started By: Navjot Singh <weavebytes@gmail.com> in November 2016
 *
 * Organization:Weavebytes Infotech Pvt Ltd
 * ---------------------------------------------------------------------------
 */

#include <QDebug>
#include <QTextStream>
#include <QDateTime>

#include "qfilelogger.h"

using namespace logger;

static QFileLogger* instance;

QFileLogger::QFileLogger(QString filepath, LogLevel level):
    filepath(filepath),
    file(filepath),
    level(level)
{
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << "[QFileLogger] :: failed to open log file";
    }
}

QFileLogger* QFileLogger::Instance() {
    return instance;
}

QFileLogger* QFileLogger::CreateLogger(QString filepath, LogLevel level) {
    if(!instance) {
        instance = new QFileLogger(filepath, level);
    }

    return instance;
}

void QFileLogger::AddLog(const char* msg) {

    QTextStream out(&file);
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss.zzz") << msg << "\r\n";
}


void QFileLogger::Debug(const char* msg) {
    if(level <= DEBUG) {
         AddLog(QString(" [DEBUG] %1").arg(msg).toLatin1() );
    }
}

void QFileLogger::Info(const char* msg) {
    if(level <= INFO) {
         AddLog(QString(" [INFO] %1").arg(msg).toLatin1() );
    }
}

void QFileLogger::Warning(const char* msg) {
    if(level <= WARNING) {
         AddLog(QString(" [WARNING] %1").arg(msg).toLatin1() );
    }
}

void QFileLogger::Critical(const char* msg) {
    if(level <= CRITICAL) {
         AddLog(QString(" [CRITICAL] %1").arg(msg).toLatin1() );
    }
}

void QFileLogger::Error(const char* msg) {
    if(level <= ERROR) {
         AddLog(QString(" [ERROR] %1").arg(msg).toLatin1() );
    }
}
