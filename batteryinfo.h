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
#ifndef BATTERYINFO_H
#define BATTERYINFO_H

#include <QDebug>

class BatteryInfo {

	private:
		QString mName;
		QString mStatus;
        int     mSupplyPresent;
		QString mSupplyTechnology;
		quint64 mSupplyCycleCount;
		quint64 mSupplyVoltageMinDesign;
		quint64 mSupplyVoltageNow;
		quint64 mSupplyCurrentNow;
		quint64 mSupplyChargeFullDesign;
		quint64 mSupplyChargeFull;
		quint64 mSupplyChargeNow;
		quint64 mSupplyCapacity;
		QString mSupplyCapacityLevel;
		QString mSupplyModelName;
		QString mSupplyManufacturer;

	public:
		explicit BatteryInfo();

		void setName(QString val);
		void setStatus(QString val);
		void setSupplyPresent(int val);
		void setSupplyTechnology(QString val);
		void setSupplyCycleCount(quint64 val);
		void setSupplyVoltageMinDesign(quint64 val);
		void setSupplyVoltageNow(quint64 val);
		void setSupplyCurrentNow(quint64 val);
		void setSupplyChargeFullDesign(quint64 val);
		void setSupplyChargeFull(quint64 val);
		void setSupplyChargeNow(quint64 val);
		void setSupplyCapacity(quint64 val);
		void setSupplyCapacityLevel(QString val);
		void setSupplyModelName(QString val);
		void setSupplyManufacturer(QString val);

		QString getName () const;
		QString getStatus () const;
		int getSupplyPresent () const;
		QString getSupplyTechnology () const;
		quint64 getSupplyCycleCount () const;
		quint64 getSupplyVoltageMinDesign () const;
		quint64 getSupplyVoltageNow () const;
		quint64 getSupplyCurrentNow () const;
		quint64 getSupplyChargeFullDesign () const;
		quint64 getSupplyChargeFull () const;
		quint64 getSupplyChargeNow () const;
		quint64 getSupplyCapacity () const;
		QString getSupplyCapacityLevel () const;
		QString getSupplyModelName () const;
		QString getSupplyManufacturer () const;

        void showInfo();

};

#endif //BATTERYINFO_H
