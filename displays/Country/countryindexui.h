/**************************************************************************
**   File: countryindexui.h
**   Created on: Sun Nov 23 14:11:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef COUNTRYINDEXUI_H
#define COUNTRYINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/country.h"
#include "../../Model/country.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class CountryIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit CountryIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static CountryIndexUI* GetUI();
QTableView *tabel; 
 Country *model; 
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
