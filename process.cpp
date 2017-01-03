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


#include "process.h"

/**
 * @brief Process::Process
 * Data structure to store the required process information
 */
Process::Process() {}

/**
 * @brief Process::Process
 * @param processId        PID of process
 * @param processName      Name of process
 * @param cpuUsage         CPU usage by process
 * @param memoryUsage      Memory usage by process
 * @param user             User that has invoked the process
 */
Process::Process(quint64 processId,
                 QString processName,
                 float cpuUsage,
                 double memoryUsage,
                 QString user)

{

    mProcessId   = processId;
    mProcessName = processName;
    mCpuUsage    = cpuUsage;
    mMemoryUsage = memoryUsage;
    mUser        = user;

}

/**
 * @brief Process::showInfo
 * Shows the process details
 */
void Process::showInfo() const{

    qDebug() << "----------------[ PROCESS ]----------------" ;
    qDebug() << "Process No  . . . . . : " << mProcessId ;
    qDebug() << "User . . . . . . . . .: " << mUser ;
    qDebug() << "Process Name . . . . .: " << mProcessName ;
    qDebug() << "Process CPU Usage  . .: " << mCpuUsage << " % ";
    qDebug() << "Process Memory Usage .: " << mMemoryUsage << " KiB ";
    qDebug() << "-------------------------------------------" ;

}

/**
 * @brief Process::getProcessId
 * @return mProcessId
 */
quint64 Process::getProcessId() const{
    return this->mProcessId;
}

/**
 * @brief Process::getProcessName
 * @return mProcessName
 */
QString Process::getProcessName() const{
    return this->mProcessName;
}

/**
 * @brief Process::getCpuUsage
 * @return mCpuUsage
 */
float Process::getCpuUsage() const{
    return this->mCpuUsage;
}

/**
 * @brief Process::getMemoryUsage
 * @return mMemoryUsage
 */
double Process::getMemoryUsage() const{
    return this->mMemoryUsage;
}

/**
 * @brief Process::getUser
 * @return mUser
 */
QString Process::getUser() const{
    return this->mUser;
}

/**
 * @brief Process::setProcessId
 * @param val
 * sets mProcessId to val
 */
void Process::setProcessId( quint64 val ){
    this->mProcessId = val ;
}

/**
 * @brief Process::setProcessName
 * @param str
 * sets mProcessName to val
 */
void Process::setProcessName( QString str ){
    this->mProcessName = str ;
}

/**
 * @brief Process::setCpuUsage
 * @param val
 * sets mCpuUsage to val
 */
void Process::setCpuUsage( float val ){
    this->mCpuUsage = val ;
}

/**
 * @brief Process::setMemoryUsage
 * @param val
 * sets mMemoryUsage to val
 */
void Process::setMemoryUsage( double val){
    this->mMemoryUsage = val ;
}

/**
 * @brief Process::setUser
 * @param str
 * sets mUser to str
 */
void Process::setUser( QString str ){
    this->mUser = str ;
}
