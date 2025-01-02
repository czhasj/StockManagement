#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
//操作数据库相关的头文件
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QtDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void connectMYSQLDBFunc();

private:
    Ui::MainWidget *ui;
};
#endif // MAINWIDGET_H
