/**************************************************************************
**   File: fieldtypeui.h
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef FIELDTYPEUI_H
#define FIELDTYPEUI_H
#include "../../erpdisplay.h"
#include "fieldtypeindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/fieldtype.h"
#include "../../Model/fieldtype.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class FieldTypeUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit FieldTypeUI(QWidget *parent = 0);
	static void ShowUI();
	static FieldTypeUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(FieldType* fieldtype);
FieldType* fieldtype;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectFieldType();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
