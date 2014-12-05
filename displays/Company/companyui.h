/**************************************************************************
**   File: companyui.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef COMPANYUI_H
#define COMPANYUI_H
#include "../../erpdisplay.h"
#include "companyindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/company.h"
#include "../../Model/company.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class CompanyUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit CompanyUI(QWidget *parent = 0);
	static void ShowUI();
	static CompanyUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*name;
	QLineEdit*header;
	QLineEdit*footer;
	void fill(Company* company);
Company* company;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectCompany();
	void cancel();
	void clear();
public slots:
	bool save();
};
#endif
