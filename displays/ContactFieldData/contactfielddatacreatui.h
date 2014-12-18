/**************************************************************************
**   File: contactfielddatacreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTFIELDDATAUI_H
#define CONTACTFIELDDATAUI_H
#include "../../erpdisplay.h"
#include "contactfielddataui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactfielddata.h"
#include "../../Model/erpmodel.h"
#include "../../Model/contactfielddata.h"
#include "../../Model/contact.h"
#include "../../Model/contactfield.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ContactFieldDataCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactFieldDataCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactFieldDataCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*contact;
	ERPComboBox*contactfield;
	QLineEdit*value;
	void fill(ContactFieldData* contactfielddata);
ContactFieldData* contactfielddata;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectContactFieldData();
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
