#include "exportexcelworker.h"
#include <QThread>

ExportExcelWorker::ExportExcelWorker(QWidget *parent,QTableWidget * tableWidget)
    : QThread(parent),parent(parent),tableWidget(tableWidget)
{}

void ExportExcelWorker::run()
{
        // 保存文件扩展名为：.xls
        QDateTime time;
        QString strTemp;

        // 1：获取当前系统当时作为文件名称进行保存
        time=QDateTime::currentDateTime();
        strTemp=time.toString("yyyy-MM-dd-hhmmss");
        // QMessageBox::information(this,"测试",strTemp);

        // 2：应用文件对话框来保存要导出文件名称(设置保存的文件名称)及数据信息
        QString strFileName=QFileDialog::getSaveFileName(parent,tr("Excel Files"),QString("./%1%2.xls").arg(strTemp).arg("_kcgl"),tr("Excel Files(*.xls)"));
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
                for(int i=1;i<=tableWidget->columnCount();i++)
                {
                    cell=worksheet->querySubObject("Cells(int,int)",1,i);
                    cell->setProperty("RowHeight",25);
                    cell->dynamicCall("SetValue(const QString&)",tableWidget->horizontalHeaderItem(i-1)->data(0).toString());
                }

                // 2：将表格数据保存到Excel文件当中
                for (int j = 2; j <= tableWidget->rowCount() + 1; ++j) {
                    for (int k = 1; k <= tableWidget->columnCount(); ++k) {
                        // 获取 QTableWidget 中的单元格数据，注意检查是否为空
                        QTableWidgetItem *item = tableWidget->item(j - 2, k - 1);

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
                qDebug()<< 2;
                // 3：将刚才创建的Excel文件直接保存到指定的目录下
                workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(strFileName)); // 保存到strFileName
                workbook->dynamicCall("Close()");
                excel->dynamicCall("Quit()");
                delete excel;
                excel=NULL;
            }
        }
}
