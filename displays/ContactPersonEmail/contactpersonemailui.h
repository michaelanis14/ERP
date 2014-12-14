/**************************************************************************
**   File: contactpersonemailui.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONEMAILUI_H
#define CONTACTPERSONEMAILUI_H
#include "../../erpdisplay.h"
#include "contactpersonemailindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactpersonemail.h"
#include "../../Model/contactpersonemail.h"
#include "../../Model/contactperson.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ContactPersonEmailUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonEmailUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonEmailUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	QLineEdit*email;
	ERPComboBox*contactperson;
	void fill(ContactPersonEmail* contactpersonemail);
ContactPersonEmail* contactpersonemail;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectContactPersonEmail();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
