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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "settingsdialog.h"
#include "aboutdialog.h"
#include "processwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void changeEvent(QEvent* e);

private slots:
    void open();
    void save();
    void about();
    void showSettings();

private:
    void createMenus();
    void addPieChart();
    void addDonutChart();

    void showPlatformInfo();

private:
    Ui::MainWindow     *ui;
    AboutDialog         dlgAbout;
    SettingsDialog      dlgSettings;
    ProcessWidget      *widProcesses;
};

#endif // MAINWINDOW_H
