/**************************************************************************
**   File: projectstatuscreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTSTATUSUI_H
#define PROJECTSTATUSUI_H
#include "../../erpdisplay.h"
#include "projectstatusui.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class ProjectStatusCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectStatusCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectStatusCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	void fill(ProjectStatus* projectstatus);
ProjectStatus* projectstatus;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectProjectStatus();
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
