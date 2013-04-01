APP_NAME = DrinkItApp

CONFIG += qt warn_on cascades10


LIBS += -lbbdata
LIBS += -lcurl
LIBS += -lnfc
LIBS += -lbbsystem
LIBS += -lQtNfcSubset

include(config.pri)
