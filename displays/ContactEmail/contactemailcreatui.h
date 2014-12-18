/**************************************************************************
**   File: contactemailcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTEMAILUI_H
#define CONTACTEMAILUI_H
#include "../../erpdisplay.h"
#include "contactemailui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactemail.h"
#include "../../Model/erpmodel.h"
#include "../../Model/contactemail.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ContactEmailCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactEmailCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactEmailCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	QLineEdit*email;
	ERPComboBox*contact;
	void fill(ContactEmail* contactemail);
ContactEmail* contactemail;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectContactEmail();
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
