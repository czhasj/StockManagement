#ifndef DATASUM_H
#define DATASUM_H

#include <QWidget>

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

#include <QMessageBox>

#include <QFileDialog>
#include <QAxObject>
#include <QDesktopServices>
#include <QDateTime>
namespace Ui {
class DataSum;
}

class DataSum : public QWidget
{
    Q_OBJECT

public:
    explicit DataSum(QWidget *parent = nullptr);
    ~DataSum();

    void TableWidgetListDataFunc();

private slots:
    void on_pushButton_DataSum_clicked();

    void on_pushButton_InputData_clicked();

    void on_pushButton_OutputData_clicked();

    void on_pushButton_DataBack_clicked();

private:
    Ui::DataSum *ui;
};

#endif // DATASUM_H
