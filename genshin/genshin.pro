QT       += core gui
QT  += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cardpool.cpp \
    cardpool_info.cpp \
    connect_sql.cpp \
    history.cpp \
    history_info.cpp \
    insert_role.cpp \
    item_info.cpp \
    main.cpp \
    login.cpp \
    manage_user.cpp \
    manager.cpp \
    money.cpp \
    once_draw.cpp \
    tenth_draw.cpp \
    update_info.cpp \
    user_bag.cpp \
    user_draw.cpp \
    user_info.cpp \
    user_register.cpp

HEADERS += \
    cardpool.h \
    cardpool_info.h \
    connect_sql.h \
    history.h \
    history_info.h \
    insert_role.h \
    item_info.h \
    login.h \
    manage_user.h \
    manager.h \
    money.h \
    once_draw.h \
    tenth_draw.h \
    update_info.h \
    user_bag.h \
    user_draw.h \
    user_info.h \
    user_register.h

FORMS += \
    cardpool.ui \
    connect_sql.ui \
    history.ui \
    insert_role.ui \
    login.ui \
    manage_user.ui \
    manager.ui \
    money.ui \
    once_draw.ui \
    tenth_draw.ui \
    update_info.ui \
    user_bag.ui \
    user_draw.ui \
    user_register.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc
