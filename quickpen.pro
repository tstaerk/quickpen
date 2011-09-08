# -------------------------------------------------
# Project created by QtCreator 2010-01-26T14:37:11
# -------------------------------------------------

TARGET = quickpen
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    drawscene.cpp \
    moreform.cpp
HEADERS += mainwindow.h \
    drawscene.h \
    moreform.h
FORMS += mainwindow.ui \
    moreform.ui

target.path = /opt/quickpen/bin
INSTALLS += target

desktop.path = /usr/share/applications
desktop.files += quickpen.desktop

RESOURCES += \
    quickpenresourcefile.qrc

TRANSLATIONS = quickpen_de.ts
    CODECFORTR = UTF-8
    CODECFORSRC = UTF-8
