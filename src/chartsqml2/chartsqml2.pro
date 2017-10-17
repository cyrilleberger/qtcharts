
TARGET = qtchartsqml2
CXX_MODULE = charts

QT += qml quick
QT += charts charts-private

include($$PWD/designer/designer.pri)

SOURCES += \
    chartsqml2_plugin.cpp \
    declarativechart.cpp \
    declarativexypoint.cpp \
    declarativexyseries.cpp \
    declarativelineseries.cpp \
    declarativesplineseries.cpp \
    declarativeareaseries.cpp \
    declarativescatterseries.cpp \
    declarativepieseries.cpp \
    declarativebarseries.cpp \
    declarativecategoryaxis.cpp \
    declarativemargins.cpp \
    declarativeaxes.cpp \
    declarativepolarchart.cpp \
    declarativeboxplotseries.cpp \
    declarativechartnode.cpp \
    declarativerendernode.cpp

HEADERS += \
    declarativechart.h \
    declarativexypoint.h \
    declarativexyseries.h \
    declarativelineseries.h \
    declarativesplineseries.h \
    declarativeareaseries.h \
    declarativescatterseries.h \
    declarativepieseries.h \
    declarativebarseries.h \
    declarativecategoryaxis.h \
    declarativemargins.h \
    declarativeaxes.h \
    declarativepolarchart.h \
    declarativeboxplotseries.h \
    declarativechartnode.h \
    declarativerendernode.h

load(qml_plugin)

win32 {
    QMAKE_TARGET_PRODUCT = "Qt Charts (Qt $$QT_VERSION)"
    QMAKE_TARGET_DESCRIPTION = "Charts QML plugin for Qt."
}

target.path=$${PREFIX}/lib
class_headers.path =$${PREFIX}/include/$$MODULE_INCNAME
targ_headers.path =$${PREFIX}/include/$$MODULE_INCNAME
private_headers.path=$${PREFIX}/include/$$MODULE_INCNAME/$$VERSION/$$MODULE_INCNAME/private
qpa_headers.path=$${PREFIX}/include/$$MODULE_INCNAME/$$VERSION/$$MODULE_INCNAME/qpa
pritarget.path = $${PREFIX}/lib/qt5/mkspecs/modules
privpritarget.path = $${PREFIX}/lib/qt5/mkspecs/modules
cmake_qt5_plugin_file.path = $${PREFIX}/lib/cmake/Qt5$${CMAKE_MODULE_NAME}
cmake_qt5_module_files.path = $${PREFIX}/lib/cmake/Qt5$${CMAKE_MODULE_NAME}
qmldir.path = $$PREFIX/lib/qt5/qml/$$TARGETPATH

CONFIG -= create_cmake
