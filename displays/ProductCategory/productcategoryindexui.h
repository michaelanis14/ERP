/**************************************************************************
**   File: productcategoryindexui.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PRODUCTCATEGORYINDEXUI_H
#define PRODUCTCATEGORYINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/productcategory.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ProductCategoryIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductCategoryIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductCategoryIndexUI* GetUI();
ERPTableView *tabel; 
 ProductCategory *model; 
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
protected:
void showEvent(QShowEvent * event);
};
#endif
