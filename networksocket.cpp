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

#include "networksocket.h"

#include <QDebug>

NetworkSocket::NetworkSocket() {}

NetworkSocket::NetworkSocket(QString protocolType,
                             quint64 receiveQ,
                             quint64 sendQ,
                             QString localAddress,
                             QString foreignAddress,
                             QString state,
                             quint64 pID,
                             QString programName)
{

    mProtocolType    =  protocolType;
    mReceiveQ        =  receiveQ;
    mSendQ           =  sendQ;
    mLocalAddress    =  localAddress;
    mForeignAddress  =  foreignAddress;
    mState           =  state;
    mPID             =  pID;
    mProgramName     =  programName;
}

void NetworkSocket::showInfo() const {

    qDebug() << "-------------------[ SOCKET ]---------------------";
    qDebug() << " Protocol type . . : " << getProtocolType();
    qDebug() << " ReceiveQ. . . . . : " << getReceiveQ()<< " bytes";
    qDebug() << " SendQ . . . . . . : " << getSendQ() << " bytes";
    qDebug() << " Local Address . . : " << getLocalAddress() << " bytes";
    qDebug() << " Foreign Address . : " << getForeignAddress();
    qDebug() << " State . . . . . . : " << getState();
    qDebug() << " PID . . . . . . . : " << getPID();
    qDebug() << " Program Name. . . : " << getProgramName();
    qDebug() << "--------------------------------------------------";
}


/**----------------------------- Getter Functions ----------------------------------------**/
QString  NetworkSocket::getProtocolType() const{
    return this->mProtocolType;
}

quint64  NetworkSocket::getReceiveQ() const{
    return this->mReceiveQ;
}

quint64  NetworkSocket::getSendQ() const{
    return this->mSendQ;
}

QString  NetworkSocket::getLocalAddress() const{
    return this->mLocalAddress;
}

QString  NetworkSocket::getForeignAddress() const{
    return this->mForeignAddress;
}

QString  NetworkSocket::getState() const{
    return this->mState;
}

quint64  NetworkSocket::getPID() const{
    return this->mPID;
}

QString  NetworkSocket::getProgramName() const{
    return this->mProgramName;
}

/**--------------------------------- Setter Functions -----------------------------**/

void NetworkSocket::setProtocolType(QString protocol) {
    mProtocolType = protocol;
}

void NetworkSocket::setReceiveQ(quint64 receiveQ) {
    mReceiveQ = receiveQ;
}

void NetworkSocket::setSendQ(quint64 sendQ) {
    mSendQ = sendQ;
}

void NetworkSocket::setLocalAddress(QString localAddress) {
    mLocalAddress = localAddress;
}

void NetworkSocket::setForeignAddress(QString foreignAddress) {
    mForeignAddress = foreignAddress;
}

void NetworkSocket::setState(QString state) {
    mState = state;
}

void NetworkSocket::setPID(quint64 pID) {
    mPID = pID;
}

void NetworkSocket::setProgramName(QString programName) {
    mProgramName = programName;
}

/**--------------------------------------------------------------------------------------**/
