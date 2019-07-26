#include "iwidget.h"

IWidget::IWidget(QObject *parent)
{
}

QMainWindow *IWidget::mainWidget()
{
    return nullptr;
}

QWidget *IWidget::centralWidget()
{
    return nullptr;
}

QWidget *IWidget::widget()
{
    return nullptr;
}

BottomAreaWidget *IWidget::bottomAreaWidget()
{
    return nullptr;
}

QWidget *IWidget::rightAreaWidget()
{
    return nullptr;
}

QPixmap IWidget::icon()
{
    return QPixmap();
}

QString IWidget::title()
{
    return QString();
}

BottomAreaWidget::BottomAreaWidget(QWidget *parent)
    : QWidget(parent)
{
}
