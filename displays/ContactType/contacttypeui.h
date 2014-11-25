/**************************************************************************
**   File: contacttypeui.h
**   Created on: Tue Nov 25 00:34:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTTYPEUI_H
#define CONTACTTYPEUI_H
#include "../../erpdisplay.h"
#include "contacttypeindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contacttype.h"
#include "../../Model/contacttype.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
class ContactTypeUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactTypeUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactTypeUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(ContactType* contacttype);
ContactType* contacttype;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectContactType();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
