/**************************************************************************
**   File: projectserviceui.h
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTSERVICEUI_H
#define PROJECTSERVICEUI_H
#include "../../erpdisplay.h"
#include "projectserviceindexui.h"
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
#include <QDateEdit>
class ProjectServiceUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectServiceUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectServiceUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*project;
	ERPComboBox*service;
	void fill(ProjectService* projectservice);
ProjectService* projectservice;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectProjectService();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
