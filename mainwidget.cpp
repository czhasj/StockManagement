#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "warehousing.h"
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    //设置主窗口背景颜色
    QPalette plt;
    plt.setColor(QPalette::Window,QColor(180,220,130));
    this->setPalette(plt);
    connectMYSQLDBFunc();
    //禁止窗口最大化按钮
    // setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);
    //禁止用户拖拉窗口改变大小
    // setFixedSize(this->width(),this->height());
    // setFixedSize(2000,1500);

    resize(2600,1607);



    // TableWidgetListDataFunc();
    InitTableWidgetFunc();


}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::connectMYSQLDBFunc()
{
    //在控制面板windows工具中配置ODBC数据源后
    //一开始使用ODBC有乱码，后来改用QMYSQL就成功了
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("stockdatabase");
    db.setUserName("root");
    db.setPassword("123456");
    bool bok = db.open();
    if(!bok)/*{
        QMessageBox::information(this,"提示","MySQL数据库连接成功！");
    }else */{
        QMessageBox::critical(this,"提示","MySQL数据库连接失败！");
    }
    return;
}

void MainWidget::TableWidgetListDataFunc()
{
    //编号 名称 数量 单价 供应商家 负责人 入库时间 出库时间 备注

    //设置表格控件200行9列
    ui->tableWidget_ListData->setColumnCount(9);
    ui->tableWidget_ListData->setRowCount(200);
    //设置表格控件字体
    ui->tableWidget_ListData->setFont(QFont("宋体",13));
    //设置表格控件的标题（表头）
    QStringList headlist{"编号","名称","数量","单价","供应商家","负责人","入库时间","出库时间","备注"};
    ui->tableWidget_ListData->setHorizontalHeaderLabels(headlist);

}

void MainWidget::InitTableWidgetFunc()
{
    //先清除表格控件数据
    ui->tableWidget_ListData->clear();

    TableWidgetListDataFunc();

    ui->tableWidget_ListData->setColumnWidth(0,80);
    ui->tableWidget_ListData->setColumnWidth(1,250);
    ui->tableWidget_ListData->setColumnWidth(2,100);
    ui->tableWidget_ListData->setColumnWidth(3,130);
    ui->tableWidget_ListData->setColumnWidth(4,400);
    ui->tableWidget_ListData->setColumnWidth(5,120);
    ui->tableWidget_ListData->setColumnWidth(6,500);
    ui->tableWidget_ListData->setColumnWidth(7,500);
    ui->tableWidget_ListData->setColumnWidth(8,380);

    QSqlQuery sqlquery;
    QString str = QString("select * from commoditydatatable");
    sqlquery.exec(str);
    int i = 0;
    while (sqlquery.next()) {

        QString strId = sqlquery.value(0).toString();
        QString strName = sqlquery.value(1).toString();
        QString strAmoumt = sqlquery.value(2).toString();
        QString strUnitPrice = sqlquery.value(3).toString();
        QString strSupplier = sqlquery.value(4).toString();
        QString strDirector = sqlquery.value(5).toString();
        QString strWareHouseTime = sqlquery.value(6).toString();
        QString strDeliveryTime = sqlquery.value(7).toString();
        QString strRemarks = sqlquery.value(8).toString();
        ui->tableWidget_ListData->setItem(i,0,new QTableWidgetItem(strId));
        ui->tableWidget_ListData->setItem(i,1,new QTableWidgetItem(strName));
        ui->tableWidget_ListData->setItem(i,2,new QTableWidgetItem(strAmoumt));
        ui->tableWidget_ListData->setItem(i,3,new QTableWidgetItem(strUnitPrice));
        ui->tableWidget_ListData->setItem(i,4,new QTableWidgetItem(strSupplier));
        ui->tableWidget_ListData->setItem(i,5,new QTableWidgetItem(strDirector));
        ui->tableWidget_ListData->setItem(i,6,new QTableWidgetItem(strWareHouseTime));
        ui->tableWidget_ListData->setItem(i,7,new QTableWidgetItem(strDeliveryTime));
        ui->tableWidget_ListData->setItem(i,8,new QTableWidgetItem(strRemarks));

        i++;
    }
}

void MainWidget::on_pushButton_DataSearch_clicked()
{
    // //表格初始化
    // InitTableWidgetFunc();

    //先清除表格控件数据
    ui->tableWidget_ListData->clear();
    TableWidgetListDataFunc();
    QSqlQuery sqlquery;
    QString strid = "stockId =";
    strid += ui->lineEdit_GoodsNumber->text();
    QString str = QString("select * from commoditydatatable where %1").arg(strid);
    sqlquery.exec(str);
    int i = 0;
    while (sqlquery.next()) {

        QString strId = sqlquery.value(0).toString();
        QString strName = sqlquery.value(1).toString();
        QString strAmoumt = sqlquery.value(2).toString();
        QString strUnitPrice = sqlquery.value(3).toString();
        QString strSupplier = sqlquery.value(4).toString();
        QString strDirector = sqlquery.value(5).toString();
        QString strWareHouseTime = sqlquery.value(6).toString();
        QString strDeliveryTime = sqlquery.value(7).toString();
        QString strRemarks = sqlquery.value(8).toString();
        ui->tableWidget_ListData->setItem(i,0,new QTableWidgetItem(strId));
        ui->tableWidget_ListData->setItem(i,1,new QTableWidgetItem(strName));
        ui->tableWidget_ListData->setItem(i,2,new QTableWidgetItem(strAmoumt));
        ui->tableWidget_ListData->setItem(i,3,new QTableWidgetItem(strUnitPrice));
        ui->tableWidget_ListData->setItem(i,4,new QTableWidgetItem(strSupplier));
        ui->tableWidget_ListData->setItem(i,5,new QTableWidgetItem(strDirector));
        ui->tableWidget_ListData->setItem(i,6,new QTableWidgetItem(strWareHouseTime));
        ui->tableWidget_ListData->setItem(i,7,new QTableWidgetItem(strDeliveryTime));
        ui->tableWidget_ListData->setItem(i,8,new QTableWidgetItem(strRemarks));
        i++;
    }
}

//新增商品

void MainWidget::on_pushButton_AddGoods_clicked()
{
    AddComodity *addlg = new AddComodity();
    addlg->show();
    connect(addlg,&AddComodity::addupdate,this,&MainWidget::InitTableWidgetFunc);
}

//删除商品
void MainWidget::on_pushButton_DeleteGoods_clicked()
{
    int iclick = QMessageBox::warning(this,"警告","警告：删除操作是根据商品编号进行删除，请确认是否安全？",
                                      QMessageBox::Yes | QMessageBox::No);
    if(iclick == QMessageBox::Yes){
        int iRow = ui->tableWidget_ListData->currentRow();

        QString strvalue = ui->tableWidget_ListData->model()->index(iRow,0).data().toString();

        QSqlQuery sqlQuery;
        QString strid = strvalue;
        if(strid.isEmpty()){
            QMessageBox::warning(this,"错误","提示：请选择要删除的商品编号，请重新检查？");
            return;
        }

        QString strsql = QString("delete from commoditydatatable where StockId = %1").arg(strid);
        // QMessageBox::information(this,"提示",QString("%1").arg(strid));
        if(sqlQuery.exec(strsql)){
            InitTableWidgetFunc();
            QMessageBox::information(this,"提示","删除商品记录成功！");
        }else {
            QMessageBox::information(this,"提示","删除商品记录失败！");
        }
    }else {
        return;
    }
}

//商品入库

void MainWidget::on_pushButton_GoodsWereHouse_clicked()
{
    Warehousing * gwdlg = new Warehousing();
    gwdlg->show();
    connect(gwdlg,&Warehousing::gwupdate,this,&MainWidget::InitTableWidgetFunc);
    connect(this,&MainWidget::updataId,gwdlg,&Warehousing::setComboBox);
    if(ui->tableWidget_ListData->currentRow() != -1){
        int row = ui->tableWidget_ListData->currentRow();
        QTableWidgetItem *item = ui->tableWidget_ListData->item(row, 0);
        if (item) {
            QString strId = item->text();
            emit updataId(strId);
        }
    }
}

//商品出库

void MainWidget::on_pushButton_GoodsDelivery_clicked()
{
    GoodsDelivery * gddlg = new GoodsDelivery();
    gddlg->show();
    connect(gddlg,&GoodsDelivery::gdupdate,this,&MainWidget::InitTableWidgetFunc);
    connect(this,&MainWidget::updataId,gddlg,&GoodsDelivery::setComboBox);
    if(ui->tableWidget_ListData->currentRow() != -1){
        int row = ui->tableWidget_ListData->currentRow();
        QTableWidgetItem *item = ui->tableWidget_ListData->item(row, 0);
        if (item) {
            QString strId = item->text();
            emit updataId(strId);
        }
    }
}

//导出数据

//导出表格控件数据，直接生成Excel文件保存
#include "waitexportexcel.h"
void MainWidget::on_pushButton_LoadData_clicked()
{
    //尝试多线程，COM 操作需要在主线程中执行，因此将所有与 COM 相关的操作放回主线程。
    // ExportExcelWorker *worker = new ExportExcelWorker(this,ui->tableWidget_ListData);
    // connect(worker,&ExportExcelWorker::finished,this,[=](){
    //     QMessageBox::information(this,"提示","Excel文件导出成功！");
    // });
    // connect(worker,&ExportExcelWorker::error,this,[=](const QString &message){
    //     QMessageBox::warning(this,"错误",message);
    // });
    // connect(worker,&ExportExcelWorker::finished,worker,&ExportExcelWorker::deleteLater);
    // worker->start();


        // 保存文件扩展名为：.xls

        QDateTime time;
        QString strTemp;

        // 1：获取当前系统当时作为文件名称进行保存
        time=QDateTime::currentDateTime();
        strTemp=time.toString("yyyy-MM-dd-hhmmss");
        // QMessageBox::information(this,"测试",strTemp);

        // 2：应用文件对话框来保存要导出文件名称(设置保存的文件名称)及数据信息
        QString strFileName=QFileDialog::getSaveFileName(this,tr("Excel Files"),QString("./%1%2.xls").arg(strTemp).arg("_kcgl"),tr("Excel Files(*.xls)"));
        // QMessageBox::information(this,"测试",strFileName);
        WaitExportExcel *wait = new WaitExportExcel();
        wait->show();
        connect(this,&MainWidget::updataPrecent,wait,&WaitExportExcel::changeProgressBar);
        // 3：处理工作簿
        if(strFileName!=NULL)
        {
            QAxObject *excel=new QAxObject;
            if(excel->setControl("Excel.Application"));
            {
                excel->dynamicCall("SetVisible (bool Visible)",false);
                excel->setProperty("DisplayAlerts",false);

                QAxObject *workbooks=excel->querySubObject("WorkBooks"); // 获得工作簿集合
                workbooks->dynamicCall("Add"); // 创建一个工作簿
                QAxObject *workbook=excel->querySubObject("ActiveWorkBook"); // 获得当前工作簿
                QAxObject *worksheet=workbook->querySubObject("Worksheets(int)",1);
                QAxObject *cell;
                double sum = ui->tableWidget_ListData->columnCount() + ui->tableWidget_ListData->columnCount() * ui->tableWidget_ListData->rowCount();
                double num = 0;
                // 1：添加Excel文件表头数据
                for(int i=1;i<=ui->tableWidget_ListData->columnCount();i++)
                {
                    cell=worksheet->querySubObject("Cells(int,int)",1,i);
                    cell->setProperty("RowHeight",25);
                    cell->dynamicCall("SetValue(const QString&)",ui->tableWidget_ListData->horizontalHeaderItem(i-1)->data(0).toString());
                    num ++;
                    emit updataPrecent(num/sum);
                }

                // 2：将表格数据保存到Excel文件当中
                for (int j = 2; j <= ui->tableWidget_ListData->rowCount() + 1; ++j) {
                    for (int k = 1; k <= ui->tableWidget_ListData->columnCount(); ++k) {
                        // 获取 QTableWidget 中的单元格数据，注意检查是否为空
                        QTableWidgetItem *item = ui->tableWidget_ListData->item(j - 2, k - 1);

                        if (item != nullptr) {
                            cell = worksheet->querySubObject("Cells(int,int)", j, k);  // Excel 行列从 1 开始
                            cell->dynamicCall("SetValue(const QString&)", item->text() + "\t");
                        } else {
                            // 如果单元格为空，可以选择填充空字符串或者其他标记
                            cell = worksheet->querySubObject("Cells(int,int)", j, k);
                            cell->dynamicCall("SetValue(const QString&)", "");
                        }
                        num++;
                        emit updataPrecent(num/sum);
                    }
                }
                // 3：将刚才创建的Excel文件直接保存到指定的目录下
                workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(strFileName)); // 保存到strFileName
                workbook->dynamicCall("Close()");
                excel->dynamicCall("Quit()");
                delete excel;
                excel=NULL;
                wait->close();
                QMessageBox::information(this,"提示","导出Excel文件成功！");
            }
        }
}

//数据汇总

void MainWidget::on_pushButton_DataSummary_clicked()
{
    DataSum* dsdlg = new DataSum();
    dsdlg->show();
}


void MainWidget::on_pushButton_Main_clicked()
{
    InitTableWidgetFunc();
}

