#include "addcomodity.h"
#include "ui_addcomodity.h"

AddComodity::AddComodity(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddComodity)
{
    ui->setupUi(this);

    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);

    // setFixedSize(this->width(),this->height());
    setFixedSize(1000,618);

    //光标定位
    ui->lineEdit_Id->setFocus();

}

AddComodity::~AddComodity()
{
    delete ui;
}

void AddComodity::on_pushButton_exit_clicked()
{
    this->close();
}


void AddComodity::on_pushButton_add_clicked()
{
    QSqlQuery sqlquery;
    QString strId,strName,strAmount,strUnitPrice,strSupplier,strDirector,strInputTime,strOutputTime,strRemarks;
    strId = ui->lineEdit_Id->text();
    strName = ui->lineEdit_Name->text();
    strAmount = ui->lineEdit_Amount->text();
    strUnitPrice = ui->lineEdit_UnitPrice->text();
    strSupplier = ui->lineEdit_Supplier->text();
    strDirector = ui->lineEdit_Director->text();
    strRemarks = ui->textEdit_Remarks->toPlainText();

    QDateTime datetime = QDateTime::currentDateTime();
    QString strnowinputtime = datetime.toString("yyyy-MM-dd HH:mm:ss");

    strInputTime = strnowinputtime;
    // strOutputTime = strnowinputtime;
    // QString sql = QString("insert into commoditydatatable "
    //             "(StockID,StockName,StockAmount,StockUnitPrice,Supplier,"
    //             "Director,WareHousTime,DeliveryTime,Remarks) values('%1',"
    //             "'%2','%3','%4','%5','%6','%7','%8','%9')").arg(strId).arg(strName)
    //             .arg(strAmount).arg(strUnitPrice).arg(strSupplier).arg(strDirector)
    //             .arg(strInputTime).arg(strOutputTime).arg(strRemarks);
    // if(sqlquery.exec(sql)){
    //     QMessageBox::information(this,"Tips","恭喜，商品记录插入成功？");
    // }else {
    //     QMessageBox::information(this,"Tips","商品记录插入失败~~~");
    // }
    // 使用参数化查询，防止SQL注入
    QString sql = "INSERT INTO commoditydatatable "
                  "(StockID, StockName, StockAmount, StockUnitPrice, Supplier, "
                  "Director, WareHousTime, DeliveryTime, Remarks) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";

    QSqlQuery query;
    query.prepare(sql);

    // 绑定参数
    query.addBindValue(strId);
    query.addBindValue(strName);
    query.addBindValue(strAmount);
    query.addBindValue(strUnitPrice);
    query.addBindValue(strSupplier);
    query.addBindValue(strDirector);
    query.addBindValue(strInputTime);
    query.addBindValue(strOutputTime);
    query.addBindValue(strRemarks);

    // 执行查询
    if(query.exec()) {
        emit addupdate();
        QMessageBox::information(this, "Tips", "恭喜，商品记录插入成功！");
    } else {
        QMessageBox::information(this, "Tips", "商品记录插入失败~~~");
    }
}

