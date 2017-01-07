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
#include "qfilelogger.h"
#include "platforminfo.h"

#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <QtCharts>

using namespace QtCharts;
using namespace logger;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Qt System Monitor");
    setFixedSize(width(), height());

    createMenus();

//    // donut chart
//    addDonutChart();

    QFileLogger::CreateLogger(QString("logs.txt"), DEBUG);
    QFileLogger::Instance()->Debug("debug");
    QFileLogger::Instance()->Info("info");
    QFileLogger::Instance()->Warning("warning");
    QFileLogger::Instance()->Critical("critical");
    QFileLogger::Instance()->Error("error");

    showPlatformInfo();
    util         = new SystemUtil();
    widProcesses = new ProcessWidget(util, ui->tableWidget, ui->refreshButton);
    widProcesses->populateUi();
    widFileSystem = new DiskWidget(util, ui->hlFileSystems);
}

MainWindow::~MainWindow()
{
    delete widProcesses;
    delete util;
    delete ui;
}

void MainWindow::showPlatformInfo()
{
    PlatformInfo pInfo;

    // OS
    ui->lblOsName->setText(pInfo.getOsName());
    ui->lblOsIcon->setPixmap(QPixmap(":/images/linux.png"));

    qDebug() << "CPU Architecure: " << pInfo.getCpuArchitecture();

    // CPU
    ui->lblCpuArch->setText(pInfo.getCpuArchitecture());
    ui->lblCpuIcon->setPixmap(QPixmap(":/images/cpu.png"));


    // RAM
    SystemMonitor sm;
    qDebug() << "RAM: " << sm.getMemorySize();

    ui->lblRam->setText(sm.getMemorySizeStr());
    ui->lblRamIcon->setPixmap(QPixmap(":/images/ram.png"));
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
    editMenu->addAction("Settings", this, SLOT(showSettings()));


    QMenu *const helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(tr("&About..."), this, SLOT(about()));
    helpMenu->addSeparator();


}
void MainWindow::showSettings() {
    dlgSettings.show();
}

void MainWindow::about() {
    dlgAbout.show();
}

void MainWindow::open() {

}

void MainWindow::save() {
}

void MainWindow::addDonutChart() {
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.35);
    series->append("Protein 4.2%", 4.2);
    QPieSlice *slice = series->append("Fat 15.6%", 15.6);
    slice->setExploded();
    slice->setLabelVisible();
    series->append("Other 23.8%", 23.8);
    series->append("Carbs 56.4%", 56.4);

    QChartView *chartView = new QChartView();
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->chart()->setTitle("Donut with a lemon glaze (100g)");
    chartView->chart()->addSeries(series);
    chartView->chart()->legend()->setAlignment(Qt::AlignBottom);
    chartView->chart()->setTheme(QChart::ChartThemeBlueCerulean);
    chartView->chart()->legend()->setFont(QFont("Arial", 7));

    ui->hlFileSystems->addWidget(chartView);
}
