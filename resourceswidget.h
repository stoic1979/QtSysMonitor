#ifndef RESOURCESWIDGET_H
#define RESOURCESWIDGET_H

#include <QWidget>
#include <QTableWidget>

#include "systemutil.h"

class ResourcesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ResourcesWidget(QTableWidget *wid, QWidget *parent = 0);
    ~ResourcesWidget();

private:
    SystemUtil   *utilities;
    QTableWidget *widget;

signals:
    void refreshData();

public slots:
    void populateUi();
    void deleteAllocatedItems();
    void refreshTimer();
};

#endif // RESOURCESWIDGET_H
