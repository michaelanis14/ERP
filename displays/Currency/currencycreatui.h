/**************************************************************************
**   File: currencycreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CURRENCYUI_H
#define CURRENCYUI_H
#include "../../erpdisplay.h"
#include "currencyui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/currency.h"
#include "../../Model/erpmodel.h"
#include "../../Model/currency.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class CurrencyCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit CurrencyCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static CurrencyCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	void fill(Currency* currency);
Currency* currency;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectCurrency();
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
