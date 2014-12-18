/**************************************************************************
**   File: loginui.h
**   Created on: Mon Dec 15 12:06:35 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef LOGINUI_H
#define LOGINUI_H
#include "../../erpdisplay.h"
#include "loginindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/login.h"
#include "../../Model/login.h"
#include "../Contact/contactindexui.h"
#include "../../Model/user.h"
#include "../../Model/access.h"
#include "../../Model/erpmodel.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class LoginUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit LoginUI(QWidget *parent = 0);
	static void ShowUI();
	static LoginUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*username;
	QLineEdit*password;
	Login* login;
private:
	static ERPDisplay* p_instance;
public slots:
	bool save();
protected:
	  void keyPressEvent(QKeyEvent *event);
	void resizeEvent(QResizeEvent * event);
	void showEvent(QShowEvent * event);
};
#endif
