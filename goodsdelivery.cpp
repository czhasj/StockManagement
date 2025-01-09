#include "goodsdelivery.h"
#include "ui_goodsdelivery.h"

GoodsDelivery::GoodsDelivery(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GoodsDelivery)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() & ~ Qt::WindowMaximizeButtonHint);
    setFixedSize(800,495);

    InitComboBoxFunc();
}

GoodsDelivery::~GoodsDelivery()
{
    delete ui;
}

void GoodsDelivery::InitComboBoxFunc()
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

void GoodsDelivery::on_pushButton_Outputgoods_clicked()
{
    QString strComboxId = ui->comboBox_Id->currentText();

    // 检查出库数量是否为空
    if (ui->lineEdit_Amount->text().isEmpty()) {
        QMessageBox::critical(this, "提示", "商品出库数量不能为空，请重新检查！");
        ui->lineEdit_Amount->setFocus();
        return;
    }

    // 查询商品库存信息
    QSqlQuery sqlQuery;
    QString strQuery = QString("SELECT * FROM commoditydatatable WHERE StockId = %1").arg(strComboxId);

    if (!sqlQuery.exec(strQuery)) {
        QMessageBox::critical(this, "提示",
                              QString("查询商品信息失败！\n错误信息：%1").arg(sqlQuery.lastError().text()));
        return;
    }
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
    // if (!sqlQuery.next()) {
    //     QMessageBox::critical(this, "提示", "未找到对应的商品信息，请检查商品编号！");
    //     return;
    // }

    // 获取当前库存数量,因为"SELECT StockAmount"所以value(0)
    int preAmount = strAmount.toInt();
    int outputAmount = ui->lineEdit_Amount->text().toInt();

    // 校验库存是否充足
    if (preAmount < outputAmount) {
        QMessageBox::critical(this, "提示", "库存不足，无法完成出库操作！");
        return;
    }

    // 计算出库后的库存
    int newAmount = preAmount - outputAmount;

    // 获取当前时间
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    // 更新库存和出库时间 注意：DeliveryTime = '%2'
    QString strUpdate = QString(
                            "UPDATE commoditydatatable SET StockAmount = %1, DeliveryTime = '%2' WHERE StockId = %3")
                            .arg(newAmount).arg(currentTime).arg(strComboxId);

    QString sql = "INSERT INTO deliverytimeTable "
                  "(StockID, StockName, StockAmount, StockUnitPrice, Supplier, "
                  "Director, DeliveryTime, Remarks) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
    query.prepare(sql);

    // 绑定参数
    query.addBindValue(strID);
    query.addBindValue(strName);
    query.addBindValue(outputAmount);
    query.addBindValue(strUnitPrice);
    query.addBindValue(strSupplier);
    query.addBindValue(strDirector);
    query.addBindValue(currentTime);
    query.addBindValue(strRemarks);
    if (sqlQuery.exec(strUpdate) && query.exec()) {
        emit gdupdate(); // 触发更新信号
        QMessageBox::information(this, "提示", "恭喜，商品出库成功！");
    } else {
        QMessageBox::critical(this, "提示",
                              QString("商品出库失败！\n错误信息：%1").arg(sqlQuery.lastError().text()));
    }
}


void GoodsDelivery::on_pushButton_Exit_clicked()
{
    close();
}

void GoodsDelivery::setComboBox(QString ID)
{
    ui->comboBox_Id->setCurrentText(ID);
}

