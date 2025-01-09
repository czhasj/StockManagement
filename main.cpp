#include "mainwidget.h"

#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // 适配高 DPI 屏幕
    w.show();
    return a.exec();
}
