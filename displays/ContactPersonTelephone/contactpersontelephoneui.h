/**************************************************************************
**   File: contactpersontelephoneui.h
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONTELEPHONEUI_H
#define CONTACTPERSONTELEPHONEUI_H
#include "../../erpdisplay.h"
#include "contactpersontelephoneindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactpersontelephone.h"
#include "../../Model/contactpersontelephone.h"
#include "../../Model/contactperson.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ContactPersonTelephoneUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonTelephoneUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonTelephoneUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	QLineEdit*number;
	ERPComboBox*contactperson;
	void fill(ContactPersonTelephone* contactpersontelephone);
ContactPersonTelephone* contactpersontelephone;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectContactPersonTelephone();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
