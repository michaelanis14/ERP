/**************************************************************************
**   File: currencyui.h
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CURRENCYUI_H
#define CURRENCYUI_H
#include "../../erpdisplay.h"
#include "currencyindexui.h"
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
#include <QDateEdit>
class CurrencyUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit CurrencyUI(QWidget *parent = 0);
	static void ShowUI();
	static CurrencyUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(Currency* currency);
Currency* currency;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectCurrency();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
