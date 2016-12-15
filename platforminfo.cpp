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

#include "platforminfo.h"

#include <QSysInfo>

PlatformInfo::PlatformInfo(QObject *parent) : QObject(parent)
{
}

QString PlatformInfo::getOsName()
{

#ifdef Q_WS_WIN
    switch(QSysInfo::windowsVersion())
    {
    case QSysInfo::WV_2000: return "Windows 2000";
    case QSysInfo::WV_XP: return "Windows XP";
    case QSysInfo::WV_VISTA: return "Windows Vista";
    case QSysInfo::WV_WINDOWS7: return "Windows 7";
    case QSysInfo::WV_WINDOWS8: return "Windows 8";
    case QSysInfo::WV_WINDOWS10: return "Windows 10";

    default: return "Windows";
    }
#endif

#ifndef Q_WS_MAC
  return "Macintosh";

  // fixme check OS verion !!!

#endif

    return "Unknow OS";
}

QString PlatformInfo::getCpuArchitecture()
{
    return QSysInfo::currentCpuArchitecture();
}
