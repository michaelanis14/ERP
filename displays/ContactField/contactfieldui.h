/**************************************************************************
**   File: contactfieldui.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTFIELDUI_H
#define CONTACTFIELDUI_H
#include "../../erpdisplay.h"
#include "contactfieldindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactfield.h"
#include "../../Model/contactfield.h"
#include "../../Model/fieldtype.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ContactFieldUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactFieldUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactFieldUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	ERPComboBox*fieldtype;
	QCheckBox* defaults;
	void fill(ContactField* contactfield);
ContactField* contactfield;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectContactField();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
