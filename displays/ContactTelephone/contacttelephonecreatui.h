/**************************************************************************
**   File: contacttelephonecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTTELEPHONEUI_H
#define CONTACTTELEPHONEUI_H
#include "../../erpdisplay.h"
#include "contacttelephoneui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contacttelephone.h"
#include "../../Model/erpmodel.h"
#include "../../Model/contacttelephone.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ContactTelephoneCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactTelephoneCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactTelephoneCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	QLineEdit*number;
	ERPComboBox*contact;
	void fill(ContactTelephone* contacttelephone);
ContactTelephone* contacttelephone;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectContactTelephone();
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
