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
