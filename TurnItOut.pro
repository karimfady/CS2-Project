QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    br.cpp \
    cor.cpp \
    createaccount.cpp \
    fl.cpp \
    hm.cpp \
    main.cpp \
    pl.cpp \
    plagiarismpage.cpp \
    rbk.cpp \
    turnitout.cpp

HEADERS += \
    br.h \
    cor.h \
    createaccount.h \
    fl.h \
    hm.h \
    pl.h \
    plagiarismpage.h \
    rbk.h \
    turnitout.h

FORMS += \
    createaccount.ui \
    plagiarismpage.ui \
    turnitout.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
