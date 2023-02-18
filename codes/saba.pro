QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets charts

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    assurance.cpp \
    bancaire.cpp \
    boursier.cpp \
    hab.cpp \
    immo.cpp \
    last.cpp \
    main.cpp \
    mainwindow.cpp \
    pc.cpp \
    velo.cpp

HEADERS += \
    assurance.h \
    bancaire.h \
    boursier.h \
    hab.h \
    immo.h \
    last.h \
    mainwindow.h \
    pc.h \
    velo.h

FORMS += \
    assurance.ui \
    bancaire.ui \
    boursier.ui \
    hab.ui \
    immo.ui \
    last.ui \
    mainwindow.ui \
    pc.ui \
    velo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc
