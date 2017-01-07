#ifndef DISKWIDGET_H
#define DISKWIDGET_H

#include "systemutil.h"
#include <QHBoxLayout>

class DiskWidget
{
public:
    explicit DiskWidget(SystemUtil *util, QHBoxLayout *lay);
    void addPieChart();

private:
    SystemUtil   *utilities;
    QHBoxLayout  *layout;
};

#endif // DISKWIDGET_H
