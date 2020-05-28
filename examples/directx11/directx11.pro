ADS_OUT_ROOT = $${OUT_PWD}/../..

QT += core gui widgets

TARGET = DirectXExample
DESTDIR = $${ADS_OUT_ROOT}/lib
TEMPLATE = app
CONFIG += c++14
CONFIG += debug_and_release
adsBuildStatic {
    DEFINES += ADS_STATIC
}

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        QDirect3D11Widget.cpp \
        main.cpp \
        MainWindow.cpp

HEADERS += \
        MainWindow.h \
        QDirect3D11Widget.h

FORMS += \
        MainWindow.ui
        

LIBS += -L$${ADS_OUT_ROOT}/lib

# Dependency: AdvancedDockingSystem (shared)
CONFIG(debug, debug|release){
    win32 {
        LIBS += -lqtadvanceddockingd
    }
    else:mac {
        LIBS += -lqtadvanceddocking_debug
    }
    else {
        LIBS += -lqtadvanceddocking
    }
}
else{
    LIBS += -lqtadvanceddocking
}

INCLUDEPATH += ../../src
DEPENDPATH += ../../src    

