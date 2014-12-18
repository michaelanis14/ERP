/**************************************************************************
**   File: projectcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTUI_H
#define PROJECTUI_H
#include "../../erpdisplay.h"
#include "projectui.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class ProjectCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ProjectSalesUI* ProjectSalesui;
	QList<ProjectSalesUI*> ProjectSaless;
	AddRemoveButtons* addremoveProjectSalesBtn;
	TaskUI* Taskui;
	QList<TaskUI*> Tasks;
	AddRemoveButtons* addremoveTaskBtn;
	ProjectContactPersonUI* ProjectContactPersonui;
	QList<ProjectContactPersonUI*> ProjectContactPersons;
	AddRemoveButtons* addremoveProjectContactPersonBtn;
	ProjectProductUI* ProjectProductui;
	QList<ProjectProductUI*> ProjectProducts;
	AddRemoveButtons* addremoveProjectProductBtn;
	ProjectServiceUI* ProjectServiceui;
	QList<ProjectServiceUI*> ProjectServices;
	AddRemoveButtons* addremoveProjectServiceBtn;
	ProjectFileUI* ProjectFileui;
	QList<ProjectFileUI*> ProjectFiles;
	AddRemoveButtons* addremoveProjectFileBtn;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
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
	void refreshTabel();
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
	void removeRow();
public slots:
	bool save();
	bool updateModel();
	void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
