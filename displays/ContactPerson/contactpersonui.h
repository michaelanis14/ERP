/**************************************************************************
**   File: contactpersonui.h
**   Created on: Wed Nov 26 16:22:56 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONUI_H
#define CONTACTPERSONUI_H
#include "../../erpdisplay.h"
#include "contactpersonindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactperson.h"
#include "../../Model/contactperson.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
class ContactPersonUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*personalsalut;
	QLineEdit*titleprefix;
	QLineEdit*name;
	QLineEdit*lastname;
	QLineEdit*position;
	QLineEdit*birthdate;
	QLineEdit*contactpersonenumber;
	QLineEdit*email;
	QLineEdit*phonenum;
	QLineEdit*phonenum2;
	QLineEdit*mobile;
	QLineEdit*fax;
	QCheckBox* active;
	ERPComboBox*contact;
	void fill(ContactPerson* contactperson);
ContactPerson* contactperson;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectContactPerson();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
