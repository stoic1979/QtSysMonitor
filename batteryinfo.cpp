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

#include "batteryinfo.h"

/**
 * @brief BatteryInfo::BatteryInfo
 */
BatteryInfo::BatteryInfo(){

}

/**
 * @brief BatteryInfo::setName
 * @param val
 */
void BatteryInfo::setName(QString val){
	mName = val ;
}

/**
 * @brief BatteryInfo::setStatus
 * @param val
 */
void BatteryInfo::setStatus(QString val){
	mStatus = val ;
}

/**
 * @brief BatteryInfo::setSupplyPresent
 * @param val
 */
void BatteryInfo::setSupplyPresent(int val){
	mSupplyPresent = val ;
}

/**
 * @brief BatteryInfo::setSupplyTechnology
 * @param val
 */
void BatteryInfo::setSupplyTechnology(QString val){
	mSupplyTechnology = val ;
}

/**
 * @brief BatteryInfo::setSupplyCycleCount
 * @param val
 */
void BatteryInfo::setSupplyCycleCount(quint64 val){
	mSupplyCycleCount = val ;
}

/**
 * @brief BatteryInfo::setSupplyVoltageMinDesign
 * @param val
 */
void BatteryInfo::setSupplyVoltageMinDesign(quint64 val){
	mSupplyVoltageMinDesign = val ;
}

/**
 * @brief BatteryInfo::setSupplyVoltageNow
 * @param val
 */
void BatteryInfo::setSupplyVoltageNow(quint64 val){
	mSupplyVoltageNow = val ;
}

/**
 * @brief BatteryInfo::setSupplyCurrentNow
 * @param val
 */
void BatteryInfo::setSupplyCurrentNow(quint64 val){
	mSupplyCurrentNow = val ;
}

/**
 * @brief BatteryInfo::setSupplyChargeFullDesign
 * @param val
 */
void BatteryInfo::setSupplyChargeFullDesign(quint64 val){
	mSupplyChargeFullDesign = val ;
}

/**
 * @brief BatteryInfo::setSupplyChargeFull
 * @param val
 */
void BatteryInfo::setSupplyChargeFull(quint64 val){
	mSupplyChargeFull = val ;
}

/**
 * @brief BatteryInfo::setSupplyChargeNow
 * @param val
 */
void BatteryInfo::setSupplyChargeNow(quint64 val){
	mSupplyChargeNow = val ;
}

/**
 * @brief BatteryInfo::setSupplyCapacity
 * @param val
 */
void BatteryInfo::setSupplyCapacity(quint64 val){
	mSupplyCapacity = val ;
}

/**
 * @brief BatteryInfo::setSupplyCapacityLevel
 * @param val
 */
void BatteryInfo::setSupplyCapacityLevel(QString val){
	mSupplyCapacityLevel = val ;
}

/**
 * @brief BatteryInfo::setSupplyModelName
 * @param val
 */
void BatteryInfo::setSupplyModelName(QString val){
	mSupplyModelName = val ;
}

/**
 * @brief BatteryInfo::setSupplyManufacturer
 * @param val
 */
void BatteryInfo::setSupplyManufacturer(QString val){
	mSupplyManufacturer = val ;
}

/**
 * @brief BatteryInfo::getName
 * @return
 */
QString BatteryInfo::getName () const{
	return this->mName;
}

/**
 * @brief BatteryInfo::getStatus
 * @return
 */
QString BatteryInfo::getStatus () const{
	return this->mStatus;
}

/**
 * @brief BatteryInfo::getSupplyPresent
 * @return
 */
int BatteryInfo::getSupplyPresent () const{
	return this->mSupplyPresent;
}

/**
 * @brief BatteryInfo::getSupplyTechnology
 * @return
 */
QString BatteryInfo::getSupplyTechnology () const{
	return this->mSupplyTechnology;
}

/**
 * @brief BatteryInfo::getSupplyCycleCount
 * @return
 */
quint64 BatteryInfo::getSupplyCycleCount () const{
	return this->mSupplyCycleCount;
}

/**
 * @brief BatteryInfo::getSupplyVoltageMinDesign
 * @return
 */
quint64 BatteryInfo::getSupplyVoltageMinDesign () const{
	return this->mSupplyVoltageMinDesign;
}

/**
 * @brief BatteryInfo::getSupplyVoltageNow
 * @return
 */
quint64 BatteryInfo::getSupplyVoltageNow () const{
	return this->mSupplyVoltageNow;
}

/**
 * @brief BatteryInfo::getSupplyCurrentNow
 * @return
 */
quint64 BatteryInfo::getSupplyCurrentNow () const{
	return this->mSupplyCurrentNow;
}

/**
 * @brief BatteryInfo::getSupplyChargeFullDesign
 * @return
 */
quint64 BatteryInfo::getSupplyChargeFullDesign () const{
	return this->mSupplyChargeFullDesign;
}

/**
 * @brief BatteryInfo::getSupplyChargeFull
 * @return
 */
quint64 BatteryInfo::getSupplyChargeFull () const{
	return this->mSupplyChargeFull;
}

/**
 * @brief BatteryInfo::getSupplyChargeNow
 * @return
 */
quint64 BatteryInfo::getSupplyChargeNow () const{
	return this->mSupplyChargeNow;
}

/**
 * @brief BatteryInfo::getSupplyCapacity
 * @return
 */
quint64 BatteryInfo::getSupplyCapacity () const{
	return this->mSupplyCapacity;
}

/**
 * @brief BatteryInfo::getSupplyCapacityLevel
 * @return
 */
QString BatteryInfo::getSupplyCapacityLevel () const{
	return this->mSupplyCapacityLevel;
}

/**
 * @brief BatteryInfo::getSupplyModelName
 * @return
 */
QString BatteryInfo::getSupplyModelName () const{
	return this->mSupplyModelName;
}

/**
 * @brief BatteryInfo::getSupplyManufacturer
 * @return
 */
QString BatteryInfo::getSupplyManufacturer () const{
	return this->mSupplyManufacturer;
}

/**
 * @brief BatteryInfo::showInfo
 */
void BatteryInfo::showInfo(){
    qDebug() << "------------------Battery Info -------------------";
    qDebug() << "POWER_SUPPLY_NAME. . . . . . . . : " << getName();
    qDebug() << "POWER_SUPPLY_STATUS. . . . . . . : " << getStatus();
    qDebug() << "POWER_SUPPLY_PRESENT . . . . . . : " << getSupplyPresent();
    qDebug() << "POWER_SUPPLY_TECHNOLOGY. . . . . : " << getSupplyTechnology();
    qDebug() << "POWER_SUPPLY_CYCLE_COUNT . . . . : " << getSupplyCycleCount();
    qDebug() << "POWER_SUPPLY_VOLTAGE_MIN_DESIGN. : " << getSupplyVoltageMinDesign();
    qDebug() << "POWER_SUPPLY_VOLTAGE_NOW . . . . : " << getSupplyVoltageNow();
    qDebug() << "POWER_SUPPLY_CURRENT_NOW . . . . : " << getSupplyCurrentNow();
    qDebug() << "POWER_SUPPLY_CHARGE_FULL_DESIGN. : " << getSupplyChargeFullDesign();
    qDebug() << "POWER_SUPPLY_CHARGE_FULL . . . . : " << getSupplyChargeFull();
    qDebug() << "POWER_SUPPLY_CHARGE_NOW  . . . . : " << getSupplyChargeNow();
    qDebug() << "POWER_SUPPLY_CAPACITY. . . . . . : " << getSupplyCapacity();
    qDebug() << "POWER_SUPPLY_CAPACITY_LEVEL. . . : " << getSupplyCapacityLevel();
    qDebug() << "POWER_SUPPLY_MODEL_NAME. . . . . : " << getSupplyModelName();
    qDebug() << "POWER_SUPPLY_MANUFACTURER. . . . : " << getSupplyManufacturer();
    qDebug() << "--------------------------------------------------";
}

