/**************************************************************************
**   File: projectstatusui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTSTATUSUI_H
#define PROJECTSTATUSUI_H
#include "../../erpdisplay.h"
#include "projectstatusindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/projectstatus.h"
#include "../../Model/erpmodel.h"
#include "../../Model/projectstatus.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ProjectStatusUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectStatusUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectStatusUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(ProjectStatus* projectstatus);
ProjectStatus* projectstatus;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectProjectStatus();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
