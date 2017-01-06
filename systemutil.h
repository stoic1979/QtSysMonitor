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
 * Organization: Weavebytes Infotech Pvt Ltd
 * ---------------------------------------------------------------------------
 */


#ifndef SYSTEMUTIL_H
#define SYSTEMUTIL_H

#include "process.h"
#include "disk.h"
#include "networksocket.h"
#include "defs.h"
#include "batteryinfo.h"

#include <QObject>
#include <QProcess>
#include <QList>

/**
 * @brief The SystemUtil class
 * This class handles backend of getting data
 */
class SystemUtil : public QObject
{

    Q_OBJECT

    QProcess     *mTopProcess;      // Qprocess mTopProcess handle the subprocess 'top'
    QProcess     *mNetstatProcess;  // QProcess mNetstatProcess handle the subprocess 'netstat'
    QString       mProcess;         // The path of subprocess 'top'
    QStringList   mEnv;             // Sets necessary TERM environment variable required for top command
    QStringList   mArguments;       // Arguments list to handle processes properly
    QString       mOutputString;    // To store the output produced by the commands
    QStringList   mOutputList;      // To store the split values of output

    int findHeaderRow();
    int findNetstatHeaderRow();

public:
    explicit SystemUtil(QObject *parent = 0);
    ~SystemUtil();

    /**
     * @brief getProcessesList
     * @param processList        - contains list of Processes
     * @return exit_status
     *
     * Execute top process to analyze the current system status
     * and populate the processList with Process objects
     */
    int getProcessesList(QList<Process> *processList);

    /**
     * @brief getDiskList
     * @param diskList           - contains list of Disks
     * @return exit_status
     *
     * Analyze the details of disks that are mounted on the system
     * and poplutes the diskList with Disk object
     */
    int getDiskList(QList<Disk> *diskList);

    /**
     * @brief getSocketList
     * @param socketList         - contains list of Sockets
     * @return exit_status
     *
     * Execute netstat process to analyze the current system status
     * and populate the socketList with NetworkSocket objects
     */
    int getSocketList(QList<NetworkSocket> *socketList);

    /**
     * @brief parseProcesses
     * @param processList
     * @return exit_status
     *
     * takes the output of top command, split it and store it in Process data structure
     * appends the process to processList
     */
    int parseProcesses(QList<Process> *processList);

    /**
     * @brief parseSockets
     * @param socketList
     * @return exit_status
     *
     * takes the output of netstat command, split it and store it in NetworkSocket data structure
     * appends the process to socketList
     */
    int parseSockets(QList<NetworkSocket> *socketList);

    /**
     * @brief showBatteryDetails
     *
     * Shows the battery details.
     */
    void showBatteryDetails();


signals:

public slots:

};

#endif // SYSTEMUTIL_H
