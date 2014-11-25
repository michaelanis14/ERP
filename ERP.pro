#-------------------------------------------------
#   File: ERP.pro
#   Created on: Sun Nov 16 16:19:26 EET 2014
#   Author: Michael Bishara
#   Copyright: SphinxSolutions.
#-------------------------------------------------

QT   += core gui widgets sql
QTPLUGIN += qsqlmysql


INCLUDEPATH =/usr/local/mysql-5.6.20-osx10.8-x86_64/include
QMAKE_MAC_SDK = macosx10.9


TARGET = ERP
TEMPLATE = app

SOURCES += main.cpp \
	displays/mainwindow.cpp \
	erpdisplay.cpp \
	displays/CommonUI/erpcombobox.cpp \
	displays/CommonUI/flowlayout.cpp  \
	displays/CommonUI/erpformblock.cpp  \
	displays/CommonUI/addremovebuttons.cpp  \
	Model/erpmodel.cpp \
	Model/contact.cpp \
	Model/contactclass.cpp \
	Model/bankaccount.cpp \
	Model/contactperson.cpp \
	Model/contactstatus.cpp \
	Model/contacttype.cpp \
	Model/country.cpp \
	Model/currency.cpp \
	Model/employee.cpp \
	Model/product.cpp \
	Model/tax.cpp \
	Model/unit.cpp \
	Model/user.cpp \
	displays/Contact/contactindexui.cpp \
	displays/Contact/contactui.cpp \
	displays/ContactClass/contactclassindexui.cpp \
	displays/ContactClass/contactclassui.cpp \
	displays/BankAccount/bankaccountindexui.cpp \
	displays/BankAccount/bankaccountui.cpp \
	displays/ContactPerson/contactpersonindexui.cpp \
	displays/ContactPerson/contactpersonui.cpp \
	displays/ContactStatus/contactstatusindexui.cpp \
	displays/ContactStatus/contactstatusui.cpp \
	displays/ContactType/contacttypeindexui.cpp \
	displays/ContactType/contacttypeui.cpp \
	displays/Country/countryindexui.cpp \
	displays/Country/countryui.cpp \
	displays/Currency/currencyindexui.cpp \
	displays/Currency/currencyui.cpp \
	displays/Employee/employeeindexui.cpp \
	displays/Employee/employeeui.cpp \
	displays/Product/productindexui.cpp \
	displays/Product/productui.cpp \
	displays/Tax/taxindexui.cpp \
	displays/Tax/taxui.cpp \
	displays/Unit/unitindexui.cpp \
	displays/Unit/unitui.cpp \
	displays/User/userindexui.cpp \
	displays/User/userui.cpp \
    displays/CommonUI/navigationButtons.cpp \
    displays/CommonUI/HNavigationButtons.cpp \
    displays/CommonUI/ean13.cpp \
    displays/CommonUI/barcode.cpp \
    displays/CommonUI/LineEditValidator.cpp \
    displays/CommonUI/RemovebtnWidgets.cpp

HEADERS += displays/mainwindow.h \	erpdisplay.h \
	displays/CommonUI/erpcombobox.h \
	displays/CommonUI/flowlayout.h  \
	displays/CommonUI/erpformblock.h  \
	displays/CommonUI/addremovebuttons.h  \
	Model/erpmodel.h \
	Model/contact.h \
	Model/contactclass.h \
	Model/bankaccount.h \
	Model/contactperson.h \
	Model/contactstatus.h \
	Model/contacttype.h \
	Model/country.h \
	Model/currency.h \
	Model/employee.h \
	Model/product.h \
	Model/tax.h \
	Model/unit.h \
	Model/user.h \
	displays/Contact/contactindexui.h \
	displays/Contact/contactui.h \
	displays/ContactClass/contactclassindexui.h \
	displays/ContactClass/contactclassui.h \
	displays/BankAccount/bankaccountindexui.h \
	displays/BankAccount/bankaccountui.h \
	displays/ContactPerson/contactpersonindexui.h \
	displays/ContactPerson/contactpersonui.h \
	displays/ContactStatus/contactstatusindexui.h \
	displays/ContactStatus/contactstatusui.h \
	displays/ContactType/contacttypeindexui.h \
	displays/ContactType/contacttypeui.h \
	displays/Country/countryindexui.h \
	displays/Country/countryui.h \
	displays/Currency/currencyindexui.h \
	displays/Currency/currencyui.h \
	displays/Employee/employeeindexui.h \
	displays/Employee/employeeui.h \
	displays/Product/productindexui.h \
	displays/Product/productui.h \
	displays/Tax/taxindexui.h \
	displays/Tax/taxui.h \
	displays/Unit/unitindexui.h \
	displays/Unit/unitui.h \
	displays/User/userindexui.h \
	displays/User/userui.h \
    displays/CommonUI/navigationButtons.h \
    displays/CommonUI/HNavigationButtons.h \
    displays/CommonUI/ean13.h \
    displays/CommonUI/barcode.h \
    displays/CommonUI/LineEditValidator.h \
    displays/CommonUI/RemovebtnWidgets.h

FORMS	+= mainwindow.ui

RESOURCES += Resources.qrc
