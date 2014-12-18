/**************************************************************************
**   File: contacttelephoneui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTTELEPHONEUI_H
#define CONTACTTELEPHONEUI_H
#include "../../erpdisplay.h"
#include "contacttelephoneindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contacttelephone.h"
#include "../../Model/erpmodel.h"
#include "../../Model/contacttelephone.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ContactTelephoneUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactTelephoneUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactTelephoneUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	QLineEdit*number;
	ERPComboBox*contact;
	void fill(ContactTelephone* contacttelephone);
ContactTelephone* contacttelephone;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectContactTelephone();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
