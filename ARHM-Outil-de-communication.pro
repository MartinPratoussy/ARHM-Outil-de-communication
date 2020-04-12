#-------------------------------------------------
#
# Project created by QtCreator 2020-02-06T14:30:00
#
#-------------------------------------------------

QT       += core gui
QT       += texttospeech
QT       += multimedia
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ARHM-Outil-de-communication
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        addedituser.cpp \
        adduser.cpp \
        edituser.cpp \
        interface.cpp \
        main.cpp \
        pictogram.cpp \
        selectpicto.cpp \
        sound.cpp \
        testinterface.cpp \
        user.cpp \
        userlist.cpp

HEADERS += \
        addedituser.h \
        adduser.h \
        edituser.h \
        interface.h \
        pictogram.h \
        selectpicto.h \
        sound.h \
        testinterface.h \
        user.h \
        userlist.h

FORMS += \
        addedituser.ui \
        interface.ui \
        selectpicto.ui \
        userlist.ui

CONFIG += mobility
MOBILITY = 


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_PACKAGE_SOURCE_DIR = \
        $$PWD/android
}