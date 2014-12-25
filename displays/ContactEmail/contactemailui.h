/**************************************************************************
**   File: contactemailui.h
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTEMAILUI_H
#define CONTACTEMAILUI_H
#include "../../erpdisplay.h"
#include "contactemailindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactemail.h"
#include "../../Model/erpmodel.h"
#include "../../Model/contactemail.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ContactEmailUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactEmailUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactEmailUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	QLineEdit*email;
	ERPComboBox*contact;
	void fill(ContactEmail* contactemail);
ContactEmail* contactemail;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectContactEmail();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
