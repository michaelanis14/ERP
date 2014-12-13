/**************************************************************************
**   File: projectcontactpersonvariablesindexui.h
**   Created on: Wed Dec 10 20:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTCONTACTPERSONVARIABLESINDEXUI_H
#define PROJECTCONTACTPERSONVARIABLESINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/projectcontactpersonvariables.h"
#include "../../Model/project.h"
#include "../../Model/contactperson.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class projectcontactpersonvariablesIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit projectcontactpersonvariablesIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static projectcontactpersonvariablesIndexUI* GetUI();
ERPTableView *tabel; 
 projectcontactpersonvariables *model; 
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
