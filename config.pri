# Auto-generated by IDE. All changes by user will be lost!
# Created at 2/26/13 1:21 AM

BASEDIR = $$_PRO_FILE_PWD_

INCLUDEPATH +=  \
    $$BASEDIR/src

SOURCES +=  \
    $$BASEDIR/src/DrinkItApp.cpp \
    $$BASEDIR/src/main.cpp

HEADERS +=  \
    $$BASEDIR/src/DrinkItApp.hpp

CONFIG += precompile_header
PRECOMPILED_HEADER = $$BASEDIR/precompiled.h

lupdate_inclusion {
    SOURCES += \
        $$BASEDIR/../assets/*.qml
}

TRANSLATIONS = \
    $${TARGET}.ts

