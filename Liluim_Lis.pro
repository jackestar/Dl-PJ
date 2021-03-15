QT       += core gui testlib network
TARGET = Liluim_Lis
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += \
					lrelease \
					c++17 \
					staticlib \
					static	\
					embed_translations

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#QMAKE_CXXFLAGS_RELEASE += -o3

DEFINES += QT_DEPRECATED_WARNINGS
RESOURCES += style.qrc

RC_FILE = resource.rc

TRANSLATIONS += \
		DL-JS_lis_esp.ts \
		DL-JS_lis_eng.ts

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    PreconfQT.hpp \
		mainwindow.hpp \
		LangStrings.hpp \
		Win/Run.hpp \
		Win/Update.hpp

FORMS += \
    mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
