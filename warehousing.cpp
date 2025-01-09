#include "warehousing.h"
#include "ui_warehousing.h"

Warehousing::Warehousing(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Warehousing)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~ Qt::WindowMaximizeButtonHint);
    setFixedSize(800,495);

    InitComboBoxFunc();

}

Warehousing::~Warehousing()
{
    delete ui;
}

void Warehousing::InitComboBoxFunc()
{
    int i = 0;
    QSqlQuery sqlQuery;
    sqlQuery.exec("SELECT * FROM commoditydatatable");

    QString strId;

    while (sqlQuery.next()) {
        strId = sqlQuery.value(0).toString();
        ui->comboBox_Id->insertItem(i,strId);
        i++;
    }
}

void Warehousing::on_pushButton_Inputgoods_clicked()
{
    QString strComboxId = ui->comboBox_Id->currentText();
    if(ui->lineEdit_Amount->text().isEmpty()){
        QMessageBox::critical(this,"提示","商品入库数量不能为空，请重新检查？");
        ui->lineEdit_Amount->setFocus();
        return;
    }
    QSqlQuery sqlQuery;
    QString strid = "StockId = ";
    strid += strComboxId;
    QString str = QString("select * from commoditydatatable where %1").arg(strid);
    sqlQuery.exec(str);
    QSqlQuery query;
    QString strID,strName,strAmount,strUnitPrice,strSupplier,strDirector,strRemarks;
    while (sqlQuery.next()) {
        strID = sqlQuery.value(0).toString();
        strName = sqlQuery.value(1).toString();
        strAmount = sqlQuery.value(2).toString();
        strUnitPrice = sqlQuery.value(3).toString();
        strSupplier = sqlQuery.value(4).toString();
        strDirector = sqlQuery.value(5).toString();
        strRemarks = sqlQuery.value(8).toString();
    }
    int preAmount = strAmount.toInt();
    int addAmount = ui->lineEdit_Amount->text().toInt();
    int sum = preAmount + addAmount;
    QString strSum = QString::number(sum);

    QString strtime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    QString strdb = QString("update commoditydatatable set StockAmount = %1, WareHousTime = '%2' where %3").arg(strSum).arg(strtime).arg(strid);

    QString sql = "INSERT INTO warehoustable "
                  "(StockID, StockName, StockAmount, StockUnitPrice, Supplier, "
                  "Director, WareHousTime, Remarks) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
    query.prepare(sql);

    // 绑定参数
    query.addBindValue(strID);
    query.addBindValue(strName);
    query.addBindValue(addAmount);
    query.addBindValue(strUnitPrice);
    query.addBindValue(strSupplier);
    query.addBindValue(strDirector);
    query.addBindValue(strtime);
    query.addBindValue(strRemarks);

    if(query.exec() && sqlQuery.exec(strdb)){
        emit gwupdate();
        QMessageBox::information(this,"提示","恭喜，商品入库成功！");
    }else {
        QMessageBox::critical(this,"提示","对不起，商品入库失败，请重新检查");
    }
}


void Warehousing::on_pushButton_Exit_clicked()
{
    close();
}

void Warehousing::setComboBox(QString ID)
{
    ui->comboBox_Id->setCurrentText(ID);
}

