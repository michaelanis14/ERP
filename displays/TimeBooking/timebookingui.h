/**************************************************************************
**   File: timebookingui.h
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef TIMEBOOKINGUI_H
#define TIMEBOOKINGUI_H
#include "../../erpdisplay.h"
#include "timebookingindexui.h"
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
#include <QDateEdit>
class TimeBookingUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit TimeBookingUI(QWidget *parent = 0);
	static void ShowUI();
	static TimeBookingUI* GetUI();
	ERPFormBlock* block0Layout;
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
private slots:
	void selectTimeBooking();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
