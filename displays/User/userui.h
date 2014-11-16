/**************************************************************************
**   File: userui.h
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef USERUI_H
#define USERUI_H
#include "../../erpdisplay.h"
#include "userindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../../Model/user.h"
#include "../../Model/user.h"
#include "../../Model/employee.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
class UserUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit UserUI(QWidget *parent = 0);
	static void ShowUI();
	static UserUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*name;
	QLineEdit*username;
	QLineEdit*password;
	QLineEdit*lastlogin;
	ERPComboBox*employee;
	QCheckBox* active;
	QLineEdit*lastip;
	void fill(User* user);
	User* user = new User();
private:
	static ERPDisplay* p_instance;
private slots:
	void selectUser();
	void cancel();
	void clear();
public slots:
	void save();
};
#endif
