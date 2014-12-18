/**************************************************************************
**   File: projectui.h
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTUI_H
#define PROJECTUI_H
#include "../../erpdisplay.h"
#include "projectindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/project.h"
#include "../../Model/erpmodel.h"
#include "../../Model/project.h"
#include "../../Model/projectstatus.h"
#include "../../Model/contact.h"

#include "../ProjectSales/projectsalesui.h"
#include "../Task/taskui.h"
#include "../ProjectContactPerson/projectcontactpersonui.h"
#include "../ProjectProduct/projectproductui.h"
#include "../ProjectService/projectserviceui.h"
#include "../ProjectFile/projectfileui.h"

#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ProjectUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPFormBlock* block1Layout;
	ERPFormBlock* block2Layout;
	ERPFormBlock* block3Layout;
	ERPFormBlock* block4Layout;
	ERPFormBlock* block5Layout;
	ERPFormBlock* block6Layout;
	ERPFormBlock* block7Layout;
	ERPFormBlock* block8Layout;
	QList<ProjectSalesUI*> ProjectSaless;
	QList<TaskUI*> Tasks;
	QList<ProjectContactPersonUI*> ProjectContactPersons;
	QList<ProjectProductUI*> ProjectProducts;
	QList<ProjectServiceUI*> ProjectServices;
	QList<ProjectFileUI*> ProjectFiles;
	QLineEdit*title;
	ERPComboBox*projectstatus;
	ERPComboBox*contact;
	QDateEdit*startdate;
	QDateEdit*enddate;
	QCheckBox* willbeinvoiced;
	QLineEdit*note;
	void fill(Project* project);
Project* project;
private:
	static ERPDisplay* p_instance;
private slots:
	void addProjectSales();
	void addProjectSales(ProjectSales* ProjectSales);
	void removeProjectSales(QWidget* widget);
	void addTask();
	void addTask(Task* Task);
	void removeTask(QWidget* widget);
	void addProjectContactPerson();
	void addProjectContactPerson(ProjectContactPerson* ProjectContactPerson);
	void removeProjectContactPerson(QWidget* widget);
	void addProjectProduct();
	void addProjectProduct(ProjectProduct* ProjectProduct);
	void removeProjectProduct(QWidget* widget);
	void addProjectService();
	void addProjectService(ProjectService* ProjectService);
	void removeProjectService(QWidget* widget);
	void addProjectFile();
	void addProjectFile(ProjectFile* ProjectFile);
	void removeProjectFile(QWidget* widget);
	void selectProject();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
