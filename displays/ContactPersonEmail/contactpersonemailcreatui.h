/**************************************************************************
**   File: contactpersonemailcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTPERSONEMAILUI_H
#define CONTACTPERSONEMAILUI_H
#include "../../erpdisplay.h"
#include "contactpersonemailui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactpersonemail.h"
#include "../../Model/erpmodel.h"
#include "../../Model/contactpersonemail.h"
#include "../../Model/contactperson.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ContactPersonEmailCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactPersonEmailCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactPersonEmailCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	QLineEdit*email;
	ERPComboBox*contactperson;
	void fill(ContactPersonEmail* contactpersonemail);
ContactPersonEmail* contactpersonemail;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectContactPersonEmail();
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
