/**************************************************************************
**   File: projectservicecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTSERVICEUI_H
#define PROJECTSERVICEUI_H
#include "../../erpdisplay.h"
#include "projectserviceui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/projectservice.h"
#include "../../Model/erpmodel.h"
#include "../../Model/projectservice.h"
#include "../../Model/project.h"
#include "../../Model/service.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ProjectServiceCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectServiceCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectServiceCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*project;
	ERPComboBox*service;
	void fill(ProjectService* projectservice);
ProjectService* projectservice;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectProjectService();
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
