#ifndef IWIDGET_H
#define IWIDGET_H

#include "pluginmanager_global.h"
#include <QMainWindow>
#include <QPixmap>

class PLUGINMANAGER_EXPORT BottomAreaWidget : public QWidget
{
    Q_OBJECT
public:
    BottomAreaWidget(QWidget *parent = nullptr);

signals:
    void hideRequested();
};
class PLUGINMANAGER_EXPORT IWidget : public QObject
{
public:
    enum WidgetType { MainWidget, BottomWidget, CommonWidget, RightWidget, CentralWidget };
    IWidget(QObject *parent = nullptr);
    virtual bool inheritWidget() = 0;
    virtual QMainWindow *mainWidget();
    virtual QWidget *centralWidget();
    virtual QWidget *widget();
    virtual BottomAreaWidget *bottomAreaWidget();
    virtual QWidget *rightAreaWidget();
    virtual QPixmap icon();
    virtual QString title();
};

#endif // IWIDGET_H
