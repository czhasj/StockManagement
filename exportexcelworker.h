#ifndef EXPORTEXCELWORKER_H
#define EXPORTEXCELWORKER_H

#include <QThread>
#include <QFileDialog>
#include <QAxObject>
#include <QDesktopServices>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>
#include <QDebug>
#include <QTableWidget>
class ExportExcelWorker : public QThread
{
    Q_OBJECT
public:
    explicit ExportExcelWorker(QWidget *parent = nullptr,QTableWidget *tableWidget = nullptr);
    void run() override;

signals:
    void finished();
    void error(const QString &message);
private:
    QWidget *parent;
    QTableWidget *tableWidget;
};

#endif // EXPORTEXCELWORKER_H
