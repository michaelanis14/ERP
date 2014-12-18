/**************************************************************************
**   File: fieldtypecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef FIELDTYPEUI_H
#define FIELDTYPEUI_H
#include "../../erpdisplay.h"
#include "fieldtypeui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/fieldtype.h"
#include "../../Model/erpmodel.h"
#include "../../Model/fieldtype.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class FieldTypeCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit FieldTypeCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static FieldTypeCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	void fill(FieldType* fieldtype);
FieldType* fieldtype;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectFieldType();
	void cancel();
	void clear();
	void removeRow();
public slots:
	bool save();
	bool updateModel();
	void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
