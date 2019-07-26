#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pluginmanager/pluginmanager.h"
using namespace plugin;
using namespace core;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , manager(new PluginManager)
{
    ui->setupUi(this);
    connect(ui->actionAbout_Plugin, &QAction::triggered, [=]() { manager->show(); });
}

MainWindow::~MainWindow()
{
    delete ui;
}
