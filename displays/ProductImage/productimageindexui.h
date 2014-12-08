/**************************************************************************
**   File: productimageindexui.h
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PRODUCTIMAGEINDEXUI_H
#define PRODUCTIMAGEINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/productimage.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ProductImageIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductImageIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductImageIndexUI* GetUI();
ERPTableView *tabel; 
 ProductImage *model; 
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
