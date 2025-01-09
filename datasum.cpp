#include "datasum.h"
#include "ui_datasum.h"

DataSum::DataSum(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DataSum)
{
    ui->setupUi(this);
    // setWindowFlags(windowFlags() & ~ Qt::WindowMaximizeButtonHint);
    // setFixedSize(1000,700);
    resize(1600,989);
    TableWidgetListDataFunc();
}

DataSum::~DataSum()
{
    delete ui;
}

void DataSum::TableWidgetListDataFunc()
{
    ui->tableWidget_ListData->setColumnCount(10);
    ui->tableWidget_ListData->setRowCount(200);

    ui->tableWidget_ListData->setFont(QFont("宋体",12));
    // QStringList list = QStringList()<<"商品编号"<<"商品名称"<<"商品数量"<<"商品单价"<<"商品总价"<<"供应商家"<<"负责人"<<"入库时间"<<"出库时间"<<"备注";
    // ui->tableWidget_ListData->setHorizontalHeaderLabels(list);

}

void DataSum::on_pushButton_DataSum_clicked()
{

    ui->tableWidget_ListData->clear();

    QStringList list = QStringList()<<"商品编号"<<"商品名称"<<"商品数量"<<"商品单价"<<"商品总价"<<"供应商家"<<"负责人"<<"入库时间"<<"出库时间"<<"备注";
    ui->tableWidget_ListData->setHorizontalHeaderLabels(list);


    ui->tableWidget_ListData->setColumnWidth(0,80);
    ui->tableWidget_ListData->setColumnWidth(1,250);
    ui->tableWidget_ListData->setColumnWidth(2,100);
    ui->tableWidget_ListData->setColumnWidth(3,130);
    ui->tableWidget_ListData->setColumnWidth(4,300);
    ui->tableWidget_ListData->setColumnWidth(5,400);
    ui->tableWidget_ListData->setColumnWidth(6,120);
    ui->tableWidget_ListData->setColumnWidth(7,500);
    ui->tableWidget_ListData->setColumnWidth(8,500);
    ui->tableWidget_ListData->setColumnWidth(9,380);

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

        double amount = strAmoumt.toDouble();
        double unitPrice = strUnitPrice.toDouble();

        ui->tableWidget_ListData->setItem(i,0,new QTableWidgetItem(strId));
        ui->tableWidget_ListData->setItem(i,1,new QTableWidgetItem(strName));
        ui->tableWidget_ListData->setItem(i,2,new QTableWidgetItem(strAmoumt));
        ui->tableWidget_ListData->setItem(i,3,new QTableWidgetItem(strUnitPrice));
        ui->tableWidget_ListData->setItem(i,4,new QTableWidgetItem(QString("%1").arg(amount * unitPrice)));
        ui->tableWidget_ListData->setItem(i,5,new QTableWidgetItem(strSupplier));
        ui->tableWidget_ListData->setItem(i,6,new QTableWidgetItem(strDirector));
        ui->tableWidget_ListData->setItem(i,7,new QTableWidgetItem(strWareHouseTime));
        ui->tableWidget_ListData->setItem(i,8,new QTableWidgetItem(strDeliveryTime));
        ui->tableWidget_ListData->setItem(i,9,new QTableWidgetItem(strRemarks));

        i++;
    }
}


void DataSum::on_pushButton_InputData_clicked()
{
    ui->tableWidget_ListData->clear();

    ui->tableWidget_ListData->setColumnCount(9);
    QStringList list = QStringList()<<"商品编号"<<"商品名称"<<"商品数量"<<"商品单价"<<"商品总价"<<"供应商家"<<"负责人"<<"入库时间"<<"备注";
    ui->tableWidget_ListData->setHorizontalHeaderLabels(list);

    ui->tableWidget_ListData->setColumnWidth(0,80);
    ui->tableWidget_ListData->setColumnWidth(1,250);
    ui->tableWidget_ListData->setColumnWidth(2,100);
    ui->tableWidget_ListData->setColumnWidth(3,130);
    ui->tableWidget_ListData->setColumnWidth(4,300);
    ui->tableWidget_ListData->setColumnWidth(5,400);
    ui->tableWidget_ListData->setColumnWidth(6,120);
    ui->tableWidget_ListData->setColumnWidth(7,500);

    QSqlQuery sqlquery;
    QString str = QString("select * from warehoustable");
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
        QString strRemarks = sqlquery.value(7).toString();

        double amount = strAmoumt.toDouble();
        double unitPrice = strUnitPrice.toDouble();

        ui->tableWidget_ListData->setItem(i,0,new QTableWidgetItem(strId));
        ui->tableWidget_ListData->setItem(i,1,new QTableWidgetItem(strName));
        ui->tableWidget_ListData->setItem(i,2,new QTableWidgetItem(strAmoumt));
        ui->tableWidget_ListData->setItem(i,3,new QTableWidgetItem(strUnitPrice));
        ui->tableWidget_ListData->setItem(i,4,new QTableWidgetItem(QString("%1").arg(amount * unitPrice)));
        ui->tableWidget_ListData->setItem(i,5,new QTableWidgetItem(strSupplier));
        ui->tableWidget_ListData->setItem(i,6,new QTableWidgetItem(strDirector));
        ui->tableWidget_ListData->setItem(i,7,new QTableWidgetItem(strWareHouseTime));
        ui->tableWidget_ListData->setItem(i,8,new QTableWidgetItem(strRemarks));

        i++;
    }
}


void DataSum::on_pushButton_OutputData_clicked()
{
    ui->tableWidget_ListData->clear();

    ui->tableWidget_ListData->setColumnCount(9);
    QStringList list = QStringList()<<"商品编号"<<"商品名称"<<"商品数量"<<"商品单价"<<"商品总价"<<"供应商家"<<"负责人"<<"出库时间"<<"备注";
    ui->tableWidget_ListData->setHorizontalHeaderLabels(list);

    ui->tableWidget_ListData->setColumnWidth(0,80);
    ui->tableWidget_ListData->setColumnWidth(1,250);
    ui->tableWidget_ListData->setColumnWidth(2,100);
    ui->tableWidget_ListData->setColumnWidth(3,130);
    ui->tableWidget_ListData->setColumnWidth(4,300);
    ui->tableWidget_ListData->setColumnWidth(5,400);
    ui->tableWidget_ListData->setColumnWidth(6,120);
    ui->tableWidget_ListData->setColumnWidth(7,500);

    QSqlQuery sqlquery;
    QString str = QString("select * from deliverytimeTable");
    sqlquery.exec(str);
    int i = 0;
    while (sqlquery.next()) {

        QString strId = sqlquery.value(0).toString();
        QString strName = sqlquery.value(1).toString();
        QString strAmoumt = sqlquery.value(2).toString();
        QString strUnitPrice = sqlquery.value(3).toString();
        QString strSupplier = sqlquery.value(4).toString();
        QString strDirector = sqlquery.value(5).toString();
        QString strDeliveryTime = sqlquery.value(6).toString();
        QString strRemarks = sqlquery.value(7).toString();

        double amount = strAmoumt.toDouble();
        double unitPrice = strUnitPrice.toDouble();

        ui->tableWidget_ListData->setItem(i,0,new QTableWidgetItem(strId));
        ui->tableWidget_ListData->setItem(i,1,new QTableWidgetItem(strName));
        ui->tableWidget_ListData->setItem(i,2,new QTableWidgetItem(strAmoumt));
        ui->tableWidget_ListData->setItem(i,3,new QTableWidgetItem(strUnitPrice));
        ui->tableWidget_ListData->setItem(i,4,new QTableWidgetItem(QString("%1").arg(amount * unitPrice)));
        ui->tableWidget_ListData->setItem(i,5,new QTableWidgetItem(strSupplier));
        ui->tableWidget_ListData->setItem(i,6,new QTableWidgetItem(strDirector));
        ui->tableWidget_ListData->setItem(i,7,new QTableWidgetItem(strDeliveryTime));
        ui->tableWidget_ListData->setItem(i,8,new QTableWidgetItem(strRemarks));

        i++;
    }
}


void DataSum::on_pushButton_DataBack_clicked()
{
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

            // 1：添加Excel文件表头数据
            for(int i=1;i<=ui->tableWidget_ListData->columnCount();i++)
            {
                cell=worksheet->querySubObject("Cells(int,int)",1,i);
                cell->setProperty("RowHeight",25);
                cell->dynamicCall("SetValue(const QString&)",ui->tableWidget_ListData->horizontalHeaderItem(i-1)->data(0).toString());
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
                }
            }
            // 3：将刚才创建的Excel文件直接保存到指定的目录下
            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(strFileName)); // 保存到strFileName
            workbook->dynamicCall("Close()");
            excel->dynamicCall("Quit()");
            delete excel;
            excel=NULL;
        }
    }
}

