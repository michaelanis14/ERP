/**************************************************************************
**   File: contactstatuscreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTSTATUSUI_H
#define CONTACTSTATUSUI_H
#include "../../erpdisplay.h"
#include "contactstatusui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactstatus.h"
#include "../../Model/erpmodel.h"
#include "../../Model/contactstatus.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ContactStatusCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactStatusCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactStatusCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	void fill(ContactStatus* contactstatus);
ContactStatus* contactstatus;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectContactStatus();
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
