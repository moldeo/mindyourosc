# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

# This is a reminder that you are using a generated .pro file.
# Remove it when you are finished editing this file.
message("You are running qmake on a generated .pro file. This may not work!")


TEMPLATE = app
TARGET = MindYourOSCs
DESTDIR = ../bin
CONFIG += debug
DEFINES += _WINDOWS QT_LARGEFILE_SUPPORT QT_DLL
INCLUDEPATH += ./../include \
    ./debug \
    . \
    $(QTDIR)/mkspecs/win32-msvc2008 \
    Debug
LIBS += -L"./../lib" \
    -ledk
DEPENDPATH += .
MOC_DIR += debug
OBJECTS_DIR += debug
UI_DIR += .
RCC_DIR += GeneratedFiles
include(MindYourOSCs.pri)
