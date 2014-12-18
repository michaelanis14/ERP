/**************************************************************************
**   File: contactpersonfieldui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONFIELDUI_H
#define CONTACTPERSONFIELDUI_H
#include "../../erpdisplay.h"
#include "contactpersonfieldindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactpersonfield.h"
#include "../../Model/erpmodel.h"
#include "../../Model/contactpersonfield.h"
#include "../../Model/fieldtype.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ContactPersonFieldUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonFieldUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonFieldUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	ERPComboBox*fieldtype;
	QCheckBox* defaults;
	void fill(ContactPersonField* contactpersonfield);
ContactPersonField* contactpersonfield;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectContactPersonField();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
