QT       += core gui testlib network #winextras
TARGET= DL-JS
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += \
					lrelease \
					c++17 \
					staticlib \
					static	\
					embed_translations
#					embed_manifest_exe

#QMAKE_CXXFLAGS_RELEASE += -o3

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
RESOURCES += qdarkstyle/style.qrc \
						Icons.qrc

#RC_ICONS = icon.ico

#win32:VERSION = 0.5.006
#else:VERSION = 0.5.006
#VERSION_PE_HEADER = 0.5.006
#QMAKE_TARGET_COPYRIGHT = Jackestar 2020
#QMAKE_TARGET_COMPANY = Jackestar
#QMAKE_TARGET_DESCRIPTION = DL-JS MediaDowloader Jackestar 2020
#QMAKE_TARGET_PRODUCT = DL-JS Lis
#RC_LANG = 0x419

#WINRT_MANIFEST.default_language = es
#WINRT_MANIFEST.background = orange
#WINRT_MANIFEST.foreground = dark
#WINRT_MANIFEST.publisher = Jackestar
#WINRT_MANIFEST.logo_310x150 = VisualElement310.png
#WINRT_MANIFEST.logo_150x150 = VisualElement256f.png
#WINRT_MANIFEST.logo_large = VisualElement256f.png
#WINRT_MANIFEST.logo_medium = VisualElement150f.png
#WINRT_MANIFEST.logo_wide = VisualElement310.png
#WINRT_MANIFEST.name = DL-JS
#WINRT_MANIFEST.version = 0.5.006

RC_FILE = resource.rc

TRANSLATIONS += \
		DL-JS_lis_esp.ts \
		DL-JS_lis_eng.ts


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    PreconfQT.hpp \
		mainwindow.hpp \
		Strings_Langs.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
