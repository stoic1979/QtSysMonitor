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

#ifndef QFILELOGGER_H
#define QFILELOGGER_H

#include <QString>
#include <QFile>

namespace logger {

enum LogLevel{
    DEBUG,
    INFO,
    WARNING,
    CRITICAL,
    ERROR
};



/**
 * @brief The QFileLogger class
 *
 * Class for logging logs of various levels - debug, info etc in log file.
 *
 * This logger is desinged to be a singleton for an application.
 */
class QFileLogger {
public:
    static QFileLogger* CreateLogger(QString filepath, LogLevel level);
    static QFileLogger* Instance();


    void Debug(const char* msg);
    void Info(const char* msg);
    void Warning(const char* msg);
    void Critical(const char* msg);
    void Error(const char* msg);


private:
    QFileLogger(QString filepath, LogLevel level);
    void AddLog(const char* msg);

private:
    QString     filepath;
    QFile       file;
    LogLevel    level;

};

} // namespace logger

#endif // QFILELOGGER_H
