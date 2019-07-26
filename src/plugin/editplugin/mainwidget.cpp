#include "mainwidget.h"
#include "ui_mainwidget.h"
using namespace plugin;
using namespace edit;
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::addFile(const QString &fileName)
{
}

void MainWidget::saveAllFile()
{
}

void MainWidget::saveCurrentFile()
{
}
