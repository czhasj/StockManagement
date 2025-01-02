#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    connectMYSQLDBFunc();
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::connectMYSQLDBFunc()
{
    //在控制面板windows工具中配置ODBC数据源后
    //这里与ODBC数据源一致
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("stockdb");
    db.setPassword("123456");

    bool bok = db.open();
    if(!bok)/*{
        QMessageBox::information(this,"提示","MySQL数据库连接成功！");
    }else */{
        QMessageBox::critical(this,"提示","MySQL数据库连接失败！");
    }
    return;
}
