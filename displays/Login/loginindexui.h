/**************************************************************************
**   File: loginindexui.h
**   Created on: Wed Dec 17 14:47:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef LOGININDEXUI_H
#define LOGININDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/login.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class LoginIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit LoginIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static LoginIndexUI* GetUI();
ERPTableView *tabel;
 Login *model;
 QPushButton* add;
 QPushButton* remove;
 QPushButton* edit;
private:
	static ERPDisplay* p_instance;
private slots:
	void addRow();
 void removeRow();
 void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
