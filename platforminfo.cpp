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
