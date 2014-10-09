#-------------------------------------------------
#
# Project created by QtCreator 2014-08-19T13:09:32
#
#-------------------------------------------------

QT       += core gui widgets sql
QTPLUGIN += qsqlmysql
INCLUDEPATH =/usr/local/mysql-5.6.20-osx10.8-x86_64/include

QMAKE_MAC_SDK = macosx10.9
TARGET = ERP
TEMPLATE = app

SOURCES += main.cpp \
	displays/mainwindow.cpp \
	erpdisplay.cpp \
	Model/contact.cpp \
	Model/contactperson.cpp \
	Model/bankaccount.cpp \
	Model/contactstatus.cpp \
	Model/contacttype.cpp \
	Model/country.cpp \
	Model/currency.cpp \
	Model/tax.cpp \
	Model/contactclass.cpp \
	Model/product.cpp \
	Model/unit.cpp \
	Model/erpmodel.cpp \
	Model/user.cpp \
	Model/employee.cpp \
	displays/Contact/contactindexui.cpp \
	displays/CommonUI/erpcombobox.cpp \
	displays/CommonUI/flowlayout.cpp \
	displays/CommonUI/erpformblock.cpp \
    displays/Contact/contactui.cpp

HEADERS  += displays/mainwindow.h \
	erpdisplay.h \
	Model/contact.h \
	Model/contactperson.h \
	Model/bankaccount.h \
	Model/contactstatus.h \
	Model/contacttype.h \
	Model/country.h \
	Model/currency.h \
	Model/tax.h \
	Model/contactclass.h \
	Model/product.h \
	Model/unit.h \
	Model/erpmodel.h \
	Model/user.h \
	Model/employee.h \
	displays/Contact/contactindexui.h \
	displays/CommonUI/erpcombobox.h \
	displays/CommonUI/flowlayout.h \
	displays/CommonUI/erpformblock.h \
    displays/Contact/contactui.h

FORMS    += mainwindow.ui \
	displays/Contact/indexcontactdisplay.ui \
	displays/Contact/contactindexui.ui

RESOURCES += \
	Resources.qrc
