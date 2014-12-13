/**************************************************************************
**   File: projectcontactpersonui.h
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTCONTACTPERSONUI_H
#define PROJECTCONTACTPERSONUI_H
#include "../../erpdisplay.h"
#include "projectcontactpersonindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/projectcontactperson.h"
#include "../../Model/projectcontactperson.h"
#include "../../Model/project.h"
#include "../../Model/contactperson.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ProjectContactPersonUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectContactPersonUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectContactPersonUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*project;
	ERPComboBox*contactperson;
	void fill(ProjectContactPerson* projectcontactperson);
ProjectContactPerson* projectcontactperson;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectProjectContactPerson();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
