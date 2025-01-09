#ifndef WAREHOUSING_H
#define WAREHOUSING_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>

namespace Ui {
class Warehousing;
}

class Warehousing : public QWidget
{
    Q_OBJECT

public:
    explicit Warehousing(QWidget *parent = nullptr);
    ~Warehousing();

    void InitComboBoxFunc();

private slots:
    void on_pushButton_Inputgoods_clicked();

    void on_pushButton_Exit_clicked();

private:
    Ui::Warehousing *ui;

signals:
    void gwupdate();
public slots:
    void  setComboBox(QString ID);
};

#endif // WAREHOUSING_H
