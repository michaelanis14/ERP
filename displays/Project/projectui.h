/**************************************************************************
**   File: projectui.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
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
#include "../../Model/project.h"


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
	QLineEdit*title;
	void fill(Project* project);
Project* project;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectProject();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
