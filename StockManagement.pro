QT       += core gui

QT +=sql

QT += axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += utf8_source
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcomodity.cpp \
    datasum.cpp \
    exportexcelworker.cpp \
    goodsdelivery.cpp \
    main.cpp \
    mainwidget.cpp \
    waitexportexcel.cpp \
    warehousing.cpp

HEADERS += \
    addcomodity.h \
    datasum.h \
    exportexcelworker.h \
    goodsdelivery.h \
    mainwidget.h \
    waitexportexcel.h \
    warehousing.h

FORMS += \
    addcomodity.ui \
    datasum.ui \
    goodsdelivery.ui \
    mainwidget.ui \
    waitexportexcel.ui \
    warehousing.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
