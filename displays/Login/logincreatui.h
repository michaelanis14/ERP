/**************************************************************************
**   File: logincreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef LOGINUI_H
#define LOGINUI_H
#include "../../erpdisplay.h"
#include "loginui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/login.h"
#include "../../Model/erpmodel.h"
#include "../../Model/login.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class LoginCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit LoginCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static LoginCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*username;
	QLineEdit*password;
	void fill(Login* login);
Login* login;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectLogin();
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
