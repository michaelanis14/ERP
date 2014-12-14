/**************************************************************************
**   File: taskindexui.h
**   Created on: Sun Dec 14 22:39:13 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef TASKINDEXUI_H
#define TASKINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/task.h"
#include "../../Model/project.h"
#include "../../Model/contactperson.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class TaskIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit TaskIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static TaskIndexUI* GetUI();
ERPTableView *tabel; 
 Task *model; 
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
