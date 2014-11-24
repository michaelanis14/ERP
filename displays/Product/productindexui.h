/**************************************************************************
**   File: productindexui.h
**   Created on: Sun Nov 23 14:11:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PRODUCTINDEXUI_H
#define PRODUCTINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/product.h"
#include "../../Model/product.h"
#include "../../Model/tax.h"
#include "../../Model/unit.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ProductIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductIndexUI* GetUI();
QTableView *tabel; 
 Product *model; 
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
