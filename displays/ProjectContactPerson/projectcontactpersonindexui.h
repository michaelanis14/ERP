/**************************************************************************
**   File: projectcontactpersonindexui.h
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTCONTACTPERSONINDEXUI_H
#define PROJECTCONTACTPERSONINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/projectcontactperson.h"
#include "../../Model/project.h"
#include "../../Model/contactperson.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class ProjectContactPersonIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectContactPersonIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectContactPersonIndexUI* GetUI();
ERPTableView *tabel; 
 ProjectContactPerson *model; 
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
