/**************************************************************************
**   File: contactclasscreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CONTACTCLASSUI_H
#define CONTACTCLASSUI_H
#include "../../erpdisplay.h"
#include "contactclassui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/contactclass.h"
#include "../../Model/erpmodel.h"
#include "../../Model/contactclass.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ContactClassCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactClassCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactClassCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	void fill(ContactClass* contactclass);
ContactClass* contactclass;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectContactClass();
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
