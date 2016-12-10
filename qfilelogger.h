#ifndef QFILELOGGER_H
#define QFILELOGGER_H

#include <QString>
#include <QFile>

/**
 * @brief The QFileLogger class
 *
 * Class for logging logs of various levels - debug, info etc in log file.
 *
 * This logger is desinged to be a singleton for an application.
 */
class QFileLogger {
public:
    static QFileLogger* CreateLogger(QString filepath);
    QFileLogger* Instance();

    void Debug(const char* msg);


private:
    QFileLogger(QString filepath);

private:
    QString     filepath;
    QFile       file;


};

#endif // QFILELOGGER_H
