QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Processor.cpp \
    Store.cpp \
    Util.cpp \
    main.cpp \
    mainwindow.cpp \
    qbasedialog.cpp \
    qnextdialog.cpp \
    qstartdialog.cpp \
    qtreadwork.cpp

HEADERS += \
    Processor.h \
    Store.h \
    Util.h \
    mainwindow.h \
    qbasedialog.h \
    qnextdialog.h \
    qstartdialog.h \
    qtreadwork.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
