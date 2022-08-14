QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 c11

#TARGET = SmartCalc

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creditwindow.cpp \
    graphwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    polka_calculation.c \
    polka_main.c \
    polka_queue.c \
    polka_stack.c \
    qcustomplot.cpp \

HEADERS += \
    calc.h \
    config.h \
    config.h.in \
    creditwindow.h \
    graphwindow.h \
    mainwindow.h \
    qcustomplot.h \

FORMS += \
    creditwindow.ui \
    graphwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc

macx:ICON = img/icon.icns
