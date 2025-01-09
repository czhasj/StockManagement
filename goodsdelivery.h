#ifndef GOODSDELIVERY_H
#define GOODSDELIVERY_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QtDebug>
#include <QMessageBox>
namespace Ui {
class GoodsDelivery;
}

class GoodsDelivery : public QWidget
{
    Q_OBJECT

public:
    explicit GoodsDelivery(QWidget *parent = nullptr);
    ~GoodsDelivery();

    void InitComboBoxFunc();

private:
    Ui::GoodsDelivery *ui;
signals:
    void gdupdate();
private slots:
    void on_pushButton_Outputgoods_clicked();
    void on_pushButton_Exit_clicked();

public slots:
    void  setComboBox(QString ID);
};

#endif // GOODSDELIVERY_H
