/**************************************************************************
**   File: timebookingcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef TIMEBOOKINGUI_H
#define TIMEBOOKINGUI_H
#include "../../erpdisplay.h"
#include "timebookingui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/timebooking.h"
#include "../../Model/erpmodel.h"
#include "../../Model/timebooking.h"
#include "../../Model/project.h"
#include "../../Model/service.h"
#include "../../Model/user.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class TimeBookingCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit TimeBookingCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static TimeBookingCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*title;
	QDateEdit*startdate;
	QDateEdit*enddate;
	QLineEdit*starttime;
	QLineEdit*endtime;
	QLineEdit*breaktime;
	QCheckBox* onlytimebooking;
	ERPComboBox*project;
	ERPComboBox*service;
	ERPComboBox*user;
	QLineEdit*note;
	void fill(TimeBooking* timebooking);
TimeBooking* timebooking;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectTimeBooking();
	void cancel();
	void clear();
	void removeRow();
public slots:
	bool save();
	bool updateModel();
	void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
