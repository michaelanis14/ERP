/**************************************************************************
**   File: productfielddataindexui.h
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PRODUCTFIELDDATAINDEXUI_H
#define PRODUCTFIELDDATAINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../../Model/productfielddata.h"
#include "../../Model/product.h"
#include "../../Model/productfield.h"


#include <QWidget>
#include <QLineEdit>
#include <QTableView>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ProductFieldDataIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductFieldDataIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductFieldDataIndexUI* GetUI();
QTableView *tabel; 
 ProductFieldData *model; 
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
