/**************************************************************************
**   File: contacttypecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTTYPEUI_H
#define CONTACTTYPEUI_H
#include "../../erpdisplay.h"
#include "contacttypeui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contacttype.h"
#include "../../Model/erpmodel.h"
#include "../../Model/contacttype.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ContactTypeCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactTypeCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactTypeCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	void fill(ContactType* contacttype);
ContactType* contacttype;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectContactType();
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
