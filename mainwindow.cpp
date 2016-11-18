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

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "systemmonitor.h"

#include <QMessageBox>
#include <QDebug>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createMenus();

    SystemMonitor sm;
    qDebug() << "RAM: " << sm.getMemorySize();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent* e)
{
    switch (e->type())
    {
        case QEvent::LanguageChange:
            this->ui->retranslateUi(this);
            break;
        case QEvent::WindowStateChange:
            {
                if (this->windowState() & Qt::WindowMinimized)
                {
                    //if (Preferences::instance().minimizeToTray())
                    //{
                        QTimer::singleShot(250, this, SLOT(hide()));
                    //}
                }

                break;
            }
        default:
            break;
    }

    QMainWindow::changeEvent(e);
}

void MainWindow::createMenus()
{

    QMenu *const fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(tr("&Open..."), this, SLOT(open()), QKeySequence::Open);
    fileMenu->addAction("&Save As...", this, SLOT(save()));
    fileMenu->addSeparator();
    fileMenu->addAction(tr("E&xit"),this, SLOT(close()), QKeySequence::Quit);

    QMenu *const editMenu = menuBar()->addMenu(tr("&Edit"));



    QMenu *const helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(tr("&About..."), this, SLOT(about()));
    helpMenu->addSeparator();


}

void MainWindow::about() {
    QMessageBox msgBox;
    msgBox.setText("QtSystemMonitor - Under R&D By Weavebytes");
    msgBox.exec();
}

void MainWindow::open() {

}

void MainWindow::save() {

}
