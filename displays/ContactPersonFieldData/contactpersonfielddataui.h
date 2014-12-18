/**************************************************************************
**   File: contactpersonfielddataui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONFIELDDATAUI_H
#define CONTACTPERSONFIELDDATAUI_H
#include "../../erpdisplay.h"
#include "contactpersonfielddataindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactpersonfielddata.h"
#include "../../Model/erpmodel.h"
#include "../../Model/contactpersonfielddata.h"
#include "../../Model/contactperson.h"
#include "../../Model/contactpersonfield.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ContactPersonFieldDataUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonFieldDataUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonFieldDataUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*contactperson;
	ERPComboBox*contactpersonfield;
	QLineEdit*value;
	void fill(ContactPersonFieldData* contactpersonfielddata);
ContactPersonFieldData* contactpersonfielddata;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectContactPersonFieldData();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
