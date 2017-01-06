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

#include "processwidget.h"

ProcessWidget::ProcessWidget(QTableWidget *wid, QPushButton *btn, QWidget *parent) :
    QWidget(parent),
    widget(wid),
    refreshButton(btn)
{
    connect(refreshButton, SIGNAL(clicked(bool)), this, SLOT(deleteAllocatedItems()));
    connect(refreshButton, SIGNAL(clicked(bool)), this, SLOT(populateUi()));

}

ProcessWidget::~ProcessWidget(){
    deleteAllocatedItems();
}

void ProcessWidget::populateUi(){

    SystemUtil util;
    QList<Process> processList;
    int returnCode = util.getProcessesList(&processList);

    if(returnCode == ST_SUCCESS){
        qDebug() << "Successfully retrieved process list. . . ";
    }else {
        qDebug() << "Problem retrieving process list . . . . .";
    }

    widget->setRowCount(processList.size());

    QTableWidgetItem *pidItem;
    QTableWidgetItem *pNameItem;
    QTableWidgetItem *pUserItem;
    QTableWidgetItem *pCpuUsageItem;
    QTableWidgetItem *pMemUsageItem;

    for(int i = 0;i < processList.size(); i++ ){

        pidItem       = new QTableWidgetItem(QString::number
                                             (processList.at(i).getProcessId()));
        pNameItem     = new QTableWidgetItem(QString
                                             (processList.at(i).getProcessName()));
        pUserItem     = new QTableWidgetItem(QString
                                             (processList.at(i).getUser()));
        pCpuUsageItem = new QTableWidgetItem(QString("%1 %").
                                             arg(QString::number(processList.at(i).getCpuUsage(),'f',2)));
        pMemUsageItem = new QTableWidgetItem(QString("%1 KiB").
                                             arg(QString::number(processList.at(i).getMemoryUsage(),'f',2)));

        pidItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        pUserItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        pCpuUsageItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        pMemUsageItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        widget->setItem(i,0,pidItem);
        widget->setItem(i,1,pNameItem);
        widget->setItem(i,2,pUserItem);
        widget->setItem(i,3,pCpuUsageItem);
        widget->setItem(i,4,pMemUsageItem);
    }
    widget->setCurrentCell(0,0);

}

void ProcessWidget::deleteAllocatedItems(){

    for(int i = 0; i < widget->rowCount(); i++){
        for(int j = 0 ;j < widget->columnCount(); j++){
            widget->setCurrentCell(i, j);
            delete widget->currentItem();
        }
    }

}
