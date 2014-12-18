/**************************************************************************
**   File: companycreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef COMPANYUI_H
#define COMPANYUI_H
#include "../../erpdisplay.h"
#include "companyui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/company.h"
#include "../../Model/erpmodel.h"
#include "../../Model/company.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class CompanyCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit CompanyCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static CompanyCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*name;
	QLineEdit*header;
	QLineEdit*footer;
	void fill(Company* company);
Company* company;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectCompany();
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
