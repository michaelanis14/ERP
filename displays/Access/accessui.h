/**************************************************************************
**   File: accessui.h
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef ACCESSUI_H
#define ACCESSUI_H
#include "../../erpdisplay.h"
#include "accessindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/access.h"
#include "../../Model/erpmodel.h"
#include "../../Model/access.h"
#include "../../Model/user.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class AccessUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit AccessUI(QWidget *parent = 0);
	static void ShowUI();
	static AccessUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*title;
	QCheckBox* admin;
	QCheckBox* deliveryorderserial;
	QCheckBox* deliveryorder;
	QCheckBox* company;
	QCheckBox* tax;
	QCheckBox* contact;
	QCheckBox* contacttelephone;
	QCheckBox* contactemail;
	QCheckBox* bankaccount;
	QCheckBox* contactclass;
	QCheckBox* contacttype;
	QCheckBox* country;
	QCheckBox* currency;
	QCheckBox* contactstatus;
	QCheckBox* fieldtype;
	QCheckBox* contactfield;
	QCheckBox* contactfielddata;
	QCheckBox* contactpersonfield;
	QCheckBox* contactpersonfielddata;
	QCheckBox* contactperson;
	QCheckBox* contactpersontelephone;
	QCheckBox* contactpersonemail;
	QCheckBox* projectstatus;
	QCheckBox* project;
	QCheckBox* projectfile;
	QCheckBox* projectcontactperson;
	QCheckBox* projectservice;
	QCheckBox* projectsales;
	QCheckBox* unit;
	QCheckBox* productcategory;
	QCheckBox* productimage;
	QCheckBox* product;
	QCheckBox* productfield;
	QCheckBox* productfielddata;
	QCheckBox* service;
	QCheckBox* store;
	QCheckBox* purchasestatus;
	QCheckBox* purchaseserial;
	QCheckBox* purchase;
	QCheckBox* purchasestoreproduct;
	QCheckBox* purchasefreeline;
	QCheckBox* returnpurchase;
	QCheckBox* returnpurchasestoreproduct;
	QCheckBox* returnpurchasefreeline;
	QCheckBox* deliveryorderstatus;
	QCheckBox* deliveryorderstoreproduct;
	QCheckBox* deliveryorderservice;
	QCheckBox* deliveryorderfreeline;
	QCheckBox* returndeliveryorder;
	QCheckBox* returndeliveryorderstoreproduct;
	QCheckBox* returndeliveryorderservice;
	QCheckBox* returndeliveryorderfreeline;
	QCheckBox* invoiceperiod;
	QCheckBox* invoiceyear;
	QCheckBox* invoicestate;
	QCheckBox* invoiceserial;
	QCheckBox* invoice;
	QCheckBox* invoicestatedate;
	QCheckBox* invoicefreeline;
	QCheckBox* paymenttype;
	QCheckBox* payment;
	QCheckBox* task;
	QCheckBox* language;
	QCheckBox* timebooking;
	QCheckBox* login;
	QLineEdit*hashkey;
	ERPComboBox*user;
	void fill(Access* access);
Access* access;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectAccess();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
