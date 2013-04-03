APP_NAME = DrinkItApp

CONFIG += qt warn_on cascades10

INCLUDEPATH += ../src ${QNX_TARGET}/usr/include/qt4/QtSql
DEPENDPATH += ../src ${QNX_TARGET}/usr/include/qt4/QtSql

QT += sql

LIBS += -lbbdata
LIBS += -lcurl
LIBS += -lnfc
LIBS += -lbbsystem
LIBS += -lQtNfcSubset
LIBS += -lnfc_bps

include(config.pri)
