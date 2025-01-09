#include "waitexportexcel.h"
#include "ui_waitexportexcel.h"

WaitExportExcel::WaitExportExcel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WaitExportExcel)
{
    ui->setupUi(this);
}

WaitExportExcel::~WaitExportExcel()
{
    delete ui;
}
