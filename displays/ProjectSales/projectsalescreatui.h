/**************************************************************************
**   File: projectsalescreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTSALESUI_H
#define PROJECTSALESUI_H
#include "../../erpdisplay.h"
#include "projectsalesui.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class ProjectSalesCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectSalesCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectSalesCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*project;
	ERPComboBox*contact;
	void fill(ProjectSales* projectsales);
ProjectSales* projectsales;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectProjectSales();
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
