/**************************************************************************
**   File: taskui.h
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef TASKUI_H
#define TASKUI_H
#include "../../erpdisplay.h"
#include "taskindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/task.h"
#include "../../Model/erpmodel.h"
#include "../../Model/task.h"
#include "../../Model/project.h"
#include "../../Model/contactperson.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class TaskUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit TaskUI(QWidget *parent = 0);
	static void ShowUI();
	static TaskUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*note;
	ERPComboBox*project;
	ERPComboBox*contactperson;
	void fill(Task* task);
Task* task;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectTask();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
