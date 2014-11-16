/**************************************************************************
**   File: contactclassui.h
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTCLASSUI_H
#define CONTACTCLASSUI_H
#include "../../erpdisplay.h"
#include "contactclassindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../../Model/contactclass.h"
#include "../../Model/contactclass.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
class ContactClassUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactClassUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactClassUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(ContactClass* contactclass);
	ContactClass* contactclass = new ContactClass();
private:
	static ERPDisplay* p_instance;
private slots:
	void selectContactClass();
	void cancel();
	void clear();
public slots:
	void save();
};
#endif
