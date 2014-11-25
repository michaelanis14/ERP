/**************************************************************************
**   File: currencyindexui.h
**   Created on: Tue Nov 25 00:34:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef CURRENCYINDEXUI_H
#define CURRENCYINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/currency.h"
#include "../../Model/currency.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class CurrencyIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit CurrencyIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static CurrencyIndexUI* GetUI();
QTableView *tabel; 
 Currency *model; 
 QPushButton* add; 
 QPushButton* remove; 
 QPushButton* edit;
private:
	static ERPDisplay* p_instance;
private slots:
	void addRow(); 
 void removeRow(); 
 void editRow(); 
 void onSelectionChanged();
};
#endif
