#ifndef WAITEXPORTEXCEL_H
#define WAITEXPORTEXCEL_H

#include <QWidget>

namespace Ui {
class WaitExportExcel;
}

class WaitExportExcel : public QWidget
{
    Q_OBJECT

public:
    explicit WaitExportExcel(QWidget *parent = nullptr);
    ~WaitExportExcel();

private:
    Ui::WaitExportExcel *ui;
public slots:
    void changeProgressBar(double precent);
};

#endif // WAITEXPORTEXCEL_H
