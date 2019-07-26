#pragma once
#include <QWidget>

namespace Ui {
class MainWidget;
}
namespace plugin {
namespace edit {
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void addFile(const QString &fileName);
    void saveAllFile();
    void saveCurrentFile();

private:
    Ui::MainWidget *ui;
};
}
}
