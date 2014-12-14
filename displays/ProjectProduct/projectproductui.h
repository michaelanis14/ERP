/**************************************************************************
**   File: projectproductui.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTPRODUCTUI_H
#define PROJECTPRODUCTUI_H
#include "../../erpdisplay.h"
#include "projectproductindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/projectproduct.h"
#include "../../Model/projectproduct.h"
#include "../../Model/project.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ProjectProductUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectProductUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectProductUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*project;
	ERPComboBox*product;
	void fill(ProjectProduct* projectproduct);
ProjectProduct* projectproduct;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectProjectProduct();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
