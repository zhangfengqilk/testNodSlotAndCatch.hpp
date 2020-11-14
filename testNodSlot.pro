TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    connection_tests.cpp \   
    disconnect_all_slots_tests.cpp \
    general_tests.cpp \
    move_tests.cpp \
    return_value_tests.cpp \
    slot_count_tests.cpp \
    usage_examples.cpp

HEADERS += \
    catch.hpp \
    test_helpers.hpp \
    nod/nod.hpp

SUBDIRS += \
    testNodSlot.pro

DISTFILES +=


# boost
LIBS += -lboost_system  -lpthread -lboost_thread

