/**************************************************************************
**   File: timebookingindexui.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef TIMEBOOKINGINDEXUI_H
#define TIMEBOOKINGINDEXUI_H
#include "../../erpdisplay.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/erptableview.h"
#include "../../Model/timebooking.h"
#include "../../Model/project.h"
#include "../../Model/service.h"
#include "../../Model/employee.h"


#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
class TimeBookingIndexUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit TimeBookingIndexUI(QWidget *parent = 0);
	static void ShowUI();
	static TimeBookingIndexUI* GetUI();
ERPTableView *tabel; 
 TimeBooking *model; 
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
