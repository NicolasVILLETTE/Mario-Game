QT += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION,4): QT += widgets
HEADERS += \
    control.h \
    view.h \
    choix.h \
    mario.h \
    dk.h \
    model.h \
    brick.h \
    baril.h

SOURCES += \
    control.cpp \
    view.cpp \
    main.cpp \
    choix.cpp \
    mario.cpp \
    dk.cpp \
    model.cpp \
    brick.cpp \
    baril.cpp

FORMS += \
    View.ui

RESOURCES += \
    ress.qrc



