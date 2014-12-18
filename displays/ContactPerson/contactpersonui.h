/**************************************************************************
**   File: contactpersonui.h
**   Created on: Thu Dec 18 10:59:52 EET 2014
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
#include "../../Model/erpmodel.h"
#include "../../Model/contactperson.h"
#include "../../Model/contact.h"

#include "../ContactPersonTelephone/contactpersontelephoneui.h"
#include "../ContactPersonEmail/contactpersonemailui.h"
#include "../ProjectContactPerson/projectcontactpersonui.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ContactPersonUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPFormBlock* block1Layout;
	ERPFormBlock* block2Layout;
	ERPFormBlock* block3Layout;
	QList<ContactPersonTelephoneUI*> ContactPersonTelephones;
	QList<ContactPersonEmailUI*> ContactPersonEmails;
	QList<ProjectContactPersonUI*> ProjectContactPersons;
	QLineEdit*title;
	ERPComboBox*contact;
	QLineEdit*name;
	QLineEdit*lastname;
	QLineEdit*position;
	QDateEdit*birthdate;
	QLineEdit*number;
	void fill(ContactPerson* contactperson);
ContactPerson* contactperson;
private:
	static ERPDisplay* p_instance;
private slots:
	void addContactPersonTelephone();
	void addContactPersonTelephone(ContactPersonTelephone* ContactPersonTelephone);
	void removeContactPersonTelephone(QWidget* widget);
	void addContactPersonEmail();
	void addContactPersonEmail(ContactPersonEmail* ContactPersonEmail);
	void removeContactPersonEmail(QWidget* widget);
	void addProjectContactPerson();
	void addProjectContactPerson(ProjectContactPerson* ProjectContactPerson);
	void removeProjectContactPerson(QWidget* widget);
	void selectContactPerson();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
