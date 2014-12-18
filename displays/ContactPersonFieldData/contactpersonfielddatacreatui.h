/**************************************************************************
**   File: contactpersonfielddatacreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONFIELDDATAUI_H
#define CONTACTPERSONFIELDDATAUI_H
#include "../../erpdisplay.h"
#include "contactpersonfielddataui.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class ContactPersonFieldDataCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonFieldDataCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonFieldDataCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*contactperson;
	ERPComboBox*contactpersonfield;
	QLineEdit*value;
	void fill(ContactPersonFieldData* contactpersonfielddata);
ContactPersonFieldData* contactpersonfielddata;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectContactPersonFieldData();
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
