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

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include "systemutil.h"

/**
 * @brief The ProcessWidget class
 *
 * Description:
 *
 * This class shows the list of processes running on the system
 */
class ProcessWidget : public QWidget {
    Q_OBJECT

public:
    explicit ProcessWidget(QTableWidget *wid,QPushButton *btn, QWidget *parent = 0);
    ~ProcessWidget();


private:
    QTableWidget  *widget;
    QPushButton   *refreshButton;

public slots:
    void populateUi();
    void deleteAllocatedItems();

};

#endif // USERINTERFACE_H
