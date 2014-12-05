/**************************************************************************
**   File: contactfielddataui.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTFIELDDATAUI_H
#define CONTACTFIELDDATAUI_H
#include "../../erpdisplay.h"
#include "contactfielddataindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactfielddata.h"
#include "../../Model/contactfielddata.h"
#include "../../Model/contact.h"
#include "../../Model/contactfield.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ContactFieldDataUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactFieldDataUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactFieldDataUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*contact;
	ERPComboBox*contactfield;
	QLineEdit*value;
	void fill(ContactFieldData* contactfielddata);
ContactFieldData* contactfielddata;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectContactFieldData();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
