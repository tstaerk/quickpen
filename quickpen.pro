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

target.path = /opt/de.staerk.quickpen

desktop.path = /usr/share/applications
desktop.files += quickpen.desktop

icons.path = /usr/share/icons
icons.files += quickpen-icon.png

INSTALLS += target desktop icons

RESOURCES += \
    quickpenresourcefile.qrc

TRANSLATIONS = quickpen_de.ts
    CODECFORTR = UTF-8
    CODECFORSRC = UTF-8
