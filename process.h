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


#ifndef PROCESS_H
#define PROCESS_H

#include <QString>
#include <QDebug>

/**
 * @brief The Process class
 * This class acts as data sturcture to store the individual process details
 */
class Process
{
    quint64 mProcessId;
    QString mProcessName;
    float   mCpuUsage;
    double  mMemoryUsage;
    QString mUser;

public:
    /**
     * @brief Process
     * Default constructor
     */
    explicit Process();

    /**
     * @brief Process      Parameterized constructor
     * @param processId    PID of process
     * @param processName  Name of process
     * @param cpuUsage     CPU usage by process
     * @param memoryUsage  Memory usage by process
     * @param user         User that has invoked the process
     */
    explicit Process(quint64 processId,
                     QString processName,
                     float cpuUsage,
                     double memoryUsage,
                     QString user);
    /**
     * @brief showInfo
     * Shows the details of process
     */
    void showInfo() const;

    /**
     * @brief getProcessId
     * @return mProcessId
     */
    quint64 getProcessId() const;

    /**
     * @brief getProcessName
     * @return mProcessName
     */
    QString getProcessName() const;

    /**
     * @brief getCpuUsage
     * @return mCpuUsage
     */
    float   getCpuUsage() const;

    /**
     * @brief getMemoryUsage
     * @return mMemoryUsage
     */
    double  getMemoryUsage() const;

    /**
     * @brief getUser
     * @return mUser
     */
    QString getUser() const;

    /**
     * @brief setProcessId
     * @param val
     */
    void setProcessId(quint64 val);

    /**
     * @brief setProcessName
     * @param str
     */
    void setProcessName(QString str);

    /**
     * @brief setCpuUsage
     * @param val
     */
    void setCpuUsage(float val);

    /**
     * @brief setMemoryUsage
     * @param val
     */
    void setMemoryUsage(double val);

    /**
     * @brief setUser
     * @param str
     */
    void setUser(QString str);

};

#endif // PROCESS_H
