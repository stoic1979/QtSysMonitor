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

#ifndef SYSINFOFACTORY_H
#define SYSINFOFACTORY_H

#include "batteryinfo.h"
#include "diskinfo.h"
#include "platforminfo.h"

/**
 * Abstract Factory for creating various system info objects/elements
 * depending upon the features and type of platform/OS - Linux, Windows, Mac
 */
class SysInfoFactory {

public:
    virtual BatteryInfo*  createBatteryInfo()  = 0;
    virtual DiskInfo*     createDiskInfo()     = 0;
    virtual PlatformInfo* createPlatformInfo() = 0;

};

#endif // SYSINFOFACTORY_H
