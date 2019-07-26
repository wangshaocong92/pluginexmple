#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "coreplugin_global.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}
namespace plugin {
namespace core {
class PluginManager;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PluginManager *manager;
};
}
}

#endif // MAINWINDOW_H
