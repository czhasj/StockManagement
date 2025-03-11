#include "waitexportexcel.h"
#include "ui_waitexportexcel.h"

WaitExportExcel::WaitExportExcel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WaitExportExcel)
{
    ui->setupUi(this);
    resize(1000,618);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
}

WaitExportExcel::~WaitExportExcel()
{
    delete ui;
}

void WaitExportExcel::changeProgressBar(double precent)
{
    int num = precent*100/1;
    ui->progressBar->setValue(num);
}
