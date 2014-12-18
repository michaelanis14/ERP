/**************************************************************************
**   File: contactpersoncreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONUI_H
#define CONTACTPERSONUI_H
#include "../../erpdisplay.h"
#include "contactpersonui.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class ContactPersonCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ContactPersonTelephoneUI* ContactPersonTelephoneui;
	QList<ContactPersonTelephoneUI*> ContactPersonTelephones;
	AddRemoveButtons* addremoveContactPersonTelephoneBtn;
	ContactPersonEmailUI* ContactPersonEmailui;
	QList<ContactPersonEmailUI*> ContactPersonEmails;
	AddRemoveButtons* addremoveContactPersonEmailBtn;
	ProjectContactPersonUI* ProjectContactPersonui;
	QList<ProjectContactPersonUI*> ProjectContactPersons;
	AddRemoveButtons* addremoveProjectContactPersonBtn;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
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
	void refreshTabel();
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
	void removeRow();
public slots:
	bool save();
	bool updateModel();
	void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
