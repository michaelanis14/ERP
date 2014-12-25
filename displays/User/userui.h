/**************************************************************************
**   File: userui.h
**   Created on: Thu Dec 18 12:57:58 EET 2014
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
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/user.h"
#include "../../Model/erpmodel.h"
#include "../../Model/user.h"
#include "../../Model/language.h"
#include "../../Model/contact.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
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
	ERPComboBox*language;
	ERPComboBox*contact;
	void fill(User* user);
User* user;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectUser();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
