/**************************************************************************
**   File: contactclassui.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
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
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactclass.h"
#include "../../Model/contactclass.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
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
ContactClass* contactclass;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectContactClass();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
