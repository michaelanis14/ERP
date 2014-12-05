/**************************************************************************
**   File: unitindexui.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef UNITINDEXUI_H
#define UNITINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/unit.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class UnitIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit UnitIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static UnitIndexUI* GetUI();
ERPTableView *tabel; 
 Unit *model; 
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
