TEMPLATE = app

QT += qml quick widgets


DEFINES += ADB_COMAND=\\\"/home/oosavu/libs/android-sdk-linux/platform-tools/adb\\\"

SOURCES += main.cpp \
    launcher.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    launcher.h
