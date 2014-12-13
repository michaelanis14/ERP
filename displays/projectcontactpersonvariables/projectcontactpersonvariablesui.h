/**************************************************************************
**   File: projectcontactpersonvariablesui.h
**   Created on: Wed Dec 10 20:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTCONTACTPERSONVARIABLESUI_H
#define PROJECTCONTACTPERSONVARIABLESUI_H
#include "../../erpdisplay.h"
#include "projectcontactpersonvariablesindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/projectcontactpersonvariables.h"
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
class projectcontactpersonvariablesUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit projectcontactpersonvariablesUI(QWidget *parent = 0);
	static void ShowUI();
	static projectcontactpersonvariablesUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*project;
	ERPComboBox*contactperson;
	void fill(projectcontactpersonvariables* projectcontactpersonvariables);
projectcontactpersonvariables* projectcontactpersonvariables;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectprojectcontactpersonvariables();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
