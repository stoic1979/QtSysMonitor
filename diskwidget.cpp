#include "diskwidget.h"

#include <QtCharts>

using namespace QtCharts;

DiskWidget::DiskWidget(SystemUtil *util, QHBoxLayout *lay):
    utilities(util),
    layout(lay)
{
    addPieChart();
}

void DiskWidget::addPieChart(){

    QList<Disk> diskList;
    int returnCode = utilities->getDiskList(&diskList);


    QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
    QBarSet *set;

    for(int i = 0; i < diskList.size(); i++){
        set = new QBarSet(diskList.at(i).getName());
        *set << diskList.at(i).getAvailableBytes();
        series->append(set);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignLeft);

    QChartView *chartView = new QChartView(chart);


    layout->addWidget(chartView);
}

