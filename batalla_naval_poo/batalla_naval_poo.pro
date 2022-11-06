QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    barco.cpp \
    batallanaval.cpp \
    crucero.cpp \
    destructor.cpp \
    dialog.cpp \
    lancha.cpp \
    main.cpp \
    mainwindow.cpp \
    portaaviones.cpp \
    submarino.cpp \
    tablero.cpp

HEADERS += \
    barco.h \
    batallanaval.h \
    crucero.h \
    destructor.h \
    dialog.h \
    lancha.h \
    mainwindow.h \
    portaaviones.h \
    submarino.h \
    tablero.h

FORMS += \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    graficos.qrc
