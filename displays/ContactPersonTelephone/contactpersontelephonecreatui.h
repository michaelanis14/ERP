/**************************************************************************
**   File: contactpersontelephonecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONTELEPHONEUI_H
#define CONTACTPERSONTELEPHONEUI_H
#include "../../erpdisplay.h"
#include "contactpersontelephoneui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactpersontelephone.h"
#include "../../Model/erpmodel.h"
#include "../../Model/contactpersontelephone.h"
#include "../../Model/contactperson.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ContactPersonTelephoneCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonTelephoneCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonTelephoneCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	QLineEdit*number;
	ERPComboBox*contactperson;
	void fill(ContactPersonTelephone* contactpersontelephone);
ContactPersonTelephone* contactpersontelephone;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectContactPersonTelephone();
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
