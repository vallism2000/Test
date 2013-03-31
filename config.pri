# Auto-generated by IDE. All changes by user will be lost!
# Created at 30/03/13 1:31 PM

BASEDIR = $$_PRO_FILE_PWD_

INCLUDEPATH +=  \
    $$BASEDIR/src/events \
    $$BASEDIR/src/drinkObjects \
    $$BASEDIR/src/eventListeners \
    $$BASEDIR/src/dataLayer \
    $$BASEDIR/src

SOURCES +=  \
    $$BASEDIR/src/BBMShare.cpp \
    $$BASEDIR/src/CoreEventBus.cpp \
    $$BASEDIR/src/DrinkItApp.cpp \
    $$BASEDIR/src/FacebookShare.cpp \
    $$BASEDIR/src/NFCShare.cpp \
    $$BASEDIR/src/ShareComponent.cpp \
    $$BASEDIR/src/ShareEventBus.cpp \
    $$BASEDIR/src/SharePage.cpp \
    $$BASEDIR/src/TwitterShare.cpp \
    $$BASEDIR/src/UIEventHandler.cpp \
    $$BASEDIR/src/dataLayer/DataMgr.cpp \
    $$BASEDIR/src/dataLayer/FileMgr.cpp \
    $$BASEDIR/src/drinkObjects/DrinkIngredient.cpp \
    $$BASEDIR/src/drinkObjects/DrinkRecipe.cpp \
    $$BASEDIR/src/eventListeners/IEventListener.cpp \
    $$BASEDIR/src/eventListeners/ShareEventListener.cpp \
    $$BASEDIR/src/events/IEvent.cpp \
    $$BASEDIR/src/events/AddRecipeEvent.cpp \
    $$BASEDIR/src/events/ModifyRecipeEvent.cpp \
    $$BASEDIR/src/events/RemoveRecipeEvent.cpp \
    $$BASEDIR/src/events/GetAllRecipesEvent.cpp \
    $$BASEDIR/src/events/GetAllRecipesResultEvent.cpp \
    $$BASEDIR/src/events/GetRecipeEvent.cpp \
    $$BASEDIR/src/events/GetRecipeResultEvent.cpp \
    $$BASEDIR/src/events/IngredientListEvent.cpp \
    $$BASEDIR/src/events/IngredientListRequestEvent.cpp \
    $$BASEDIR/src/events/IngredientListResultEvent.cpp \
    $$BASEDIR/src/events/NFCReceivedRecipeEvent.cpp \
    $$BASEDIR/src/events/ShareRecipeEvent.cpp \
    $$BASEDIR/src/events/ShareResponseStatusEvent.cpp \
    $$BASEDIR/src/events/UIRecipeEvent.cpp \
    $$BASEDIR/src/events/UIRecipeListEvent.cpp \
    $$BASEDIR/src/events/UIShareEvent.cpp \
    $$BASEDIR/src/main.cpp

HEADERS +=  \
    $$BASEDIR/src/BBMShare.hpp \
    $$BASEDIR/src/CoreEventBus.hpp \
    $$BASEDIR/src/DrinkItApp.hpp \
    $$BASEDIR/src/FacebookShare.hpp \
    $$BASEDIR/src/NFCShare.hpp \
    $$BASEDIR/src/ShareComponent.hpp \
    $$BASEDIR/src/ShareEventBus.hpp \
    $$BASEDIR/src/SharePage.hpp \
    $$BASEDIR/src/TwitterShare.hpp \
    $$BASEDIR/src/UIEventHandler.hpp \
    $$BASEDIR/src/dataLayer/DataMgr.hpp \
    $$BASEDIR/src/dataLayer/FileMgr.hpp \
    $$BASEDIR/src/drinkObjects/DrinkIngredient.hpp \
    $$BASEDIR/src/drinkObjects/DrinkRecipe.hpp \
    $$BASEDIR/src/eventListeners/IEventListener.hpp \
    $$BASEDIR/src/eventListeners/ShareEventListener.hpp \
    $$BASEDIR/src/events/IEvent.hpp \
    $$BASEDIR/src/events/AddRecipeEvent.hpp \
    $$BASEDIR/src/events/ModifyRecipeEvent.hpp \
    $$BASEDIR/src/events/RemoveRecipeEvent.hpp \
    $$BASEDIR/src/events/GetAllRecipesEvent.hpp \
    $$BASEDIR/src/events/GetAllRecipesResultEvent.hpp \
    $$BASEDIR/src/events/GetRecipeEvent.hpp \
    $$BASEDIR/src/events/GetRecipeResultEvent.hpp \
    $$BASEDIR/src/events/IngredientListEvent.hpp \
    $$BASEDIR/src/events/IngredientListRequestEvent.hpp \
    $$BASEDIR/src/events/IngredientListResultEvent.hpp \
    $$BASEDIR/src/events/NFCReceivedRecipeEvent.hpp \
    $$BASEDIR/src/events/ShareRecipeEvent.hpp \
    $$BASEDIR/src/events/ShareResponseStatusEvent.hpp \
    $$BASEDIR/src/events/UIRecipeEvent.hpp \
    $$BASEDIR/src/events/UIRecipeListEvent.hpp \
    $$BASEDIR/src/events/UIShareEvent.hpp

CONFIG += precompile_header
PRECOMPILED_HEADER = $$BASEDIR/precompiled.h

lupdate_inclusion {
    SOURCES += \
        $$BASEDIR/../assets/*.qml
}

TRANSLATIONS = \
    $${TARGET}.ts

