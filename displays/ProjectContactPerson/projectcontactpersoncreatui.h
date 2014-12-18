/**************************************************************************
**   File: projectcontactpersoncreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTCONTACTPERSONUI_H
#define PROJECTCONTACTPERSONUI_H
#include "../../erpdisplay.h"
#include "projectcontactpersonui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/projectcontactperson.h"
#include "../../Model/erpmodel.h"
#include "../../Model/projectcontactperson.h"
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
class ProjectContactPersonCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectContactPersonCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectContactPersonCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*project;
	ERPComboBox*contactperson;
	void fill(ProjectContactPerson* projectcontactperson);
ProjectContactPerson* projectcontactperson;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectProjectContactPerson();
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
