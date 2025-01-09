#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "addcomodity.h"
#include "warehousing.h"
#include "goodsdelivery.h"
#include <QFileDialog>
#include <QAxObject>
#include <QDesktopServices>
#include "exportexcelworker.h"
#include "datasum.h"
//操作数据库相关的头文件
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QtDebug>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include <QDateTime>

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

    void TableWidgetListDataFunc();

    void InitTableWidgetFunc();

private slots:
    void on_pushButton_DataSearch_clicked();

    void on_pushButton_AddGoods_clicked();

    void on_pushButton_DeleteGoods_clicked();

    void on_pushButton_GoodsWereHouse_clicked();

    void on_pushButton_GoodsDelivery_clicked();

    void on_pushButton_LoadData_clicked();

    void on_pushButton_DataSummary_clicked();

    void on_pushButton_Main_clicked();

private:
    Ui::MainWidget *ui;
signals:
    void updataId(QString ID);
};
#endif // MAINWIDGET_H
