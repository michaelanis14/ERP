/**************************************************************************
**   File: contactfieldcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTFIELDUI_H
#define CONTACTFIELDUI_H
#include "../../erpdisplay.h"
#include "contactfieldui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactfield.h"
#include "../../Model/erpmodel.h"
#include "../../Model/contactfield.h"
#include "../../Model/fieldtype.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ContactFieldCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactFieldCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactFieldCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	ERPComboBox*fieldtype;
	QCheckBox* defaults;
	void fill(ContactField* contactfield);
ContactField* contactfield;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectContactField();
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
