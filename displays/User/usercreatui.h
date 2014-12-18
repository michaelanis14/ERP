/**************************************************************************
**   File: usercreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef USERUI_H
#define USERUI_H
#include "../../erpdisplay.h"
#include "userui.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class UserCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit UserCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static UserCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*name;
	QLineEdit*username;
	QLineEdit*password;
	ERPComboBox*language;
	ERPComboBox*contact;
	void fill(User* user);
User* user;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectUser();
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
