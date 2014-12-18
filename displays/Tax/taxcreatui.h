/**************************************************************************
**   File: taxcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef TAXUI_H
#define TAXUI_H
#include "../../erpdisplay.h"
#include "taxui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/tax.h"
#include "../../Model/erpmodel.h"
#include "../../Model/tax.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class TaxCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit TaxCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static TaxCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*title;
	void fill(Tax* tax);
Tax* tax;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectTax();
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
