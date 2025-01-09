#ifndef ADDCOMODITY_H
#define ADDCOMODITY_H

#include <QWidget>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QtDebug>
#include <QMessageBox>

namespace Ui {
class AddComodity;
}

class AddComodity : public QWidget
{
    Q_OBJECT

public:
    explicit AddComodity(QWidget *parent = nullptr);
    ~AddComodity();

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_add_clicked();

private:
    Ui::AddComodity *ui;
signals:
    void addupdate();
};

#endif // ADDCOMODITY_H
