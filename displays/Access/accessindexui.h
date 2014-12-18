/**************************************************************************
**   File: accessindexui.h
**   Created on: Wed Dec 17 14:40:22 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef ACCESSINDEXUI_H
#define ACCESSINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/access.h"
#include "../../Model/user.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class AccessIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit AccessIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static AccessIndexUI* GetUI();
ERPTableView *tabel; 
 Access *model; 
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
