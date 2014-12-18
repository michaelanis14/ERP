/**************************************************************************
**   File: taskcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef TASKUI_H
#define TASKUI_H
#include "../../erpdisplay.h"
#include "taskui.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class TaskCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit TaskCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static TaskCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*note;
	ERPComboBox*project;
	ERPComboBox*contactperson;
	void fill(Task* task);
Task* task;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectTask();
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
