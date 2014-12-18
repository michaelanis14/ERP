/**************************************************************************
**   File: projectsalesui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTSALESUI_H
#define PROJECTSALESUI_H
#include "../../erpdisplay.h"
#include "projectsalesindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/projectsales.h"
#include "../../Model/erpmodel.h"
#include "../../Model/projectsales.h"
#include "../../Model/project.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ProjectSalesUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectSalesUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectSalesUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*project;
	ERPComboBox*contact;
	void fill(ProjectSales* projectsales);
ProjectSales* projectsales;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectProjectSales();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
