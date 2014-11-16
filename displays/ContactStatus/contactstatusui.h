/**************************************************************************
**   File: contactstatusui.h
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTSTATUSUI_H
#define CONTACTSTATUSUI_H
#include "../../erpdisplay.h"
#include "contactstatusindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../../Model/contactstatus.h"
#include "../../Model/contactstatus.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
class ContactStatusUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactStatusUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactStatusUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(ContactStatus* contactstatus);
	ContactStatus* contactstatus = new ContactStatus();
private:
	static ERPDisplay* p_instance;
private slots:
	void selectContactStatus();
	void cancel();
	void clear();
public slots:
	void save();
};
#endif
