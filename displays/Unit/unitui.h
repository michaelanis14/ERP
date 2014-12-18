/**************************************************************************
**   File: unitui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef UNITUI_H
#define UNITUI_H
#include "../../erpdisplay.h"
#include "unitindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/unit.h"
#include "../../Model/erpmodel.h"
#include "../../Model/unit.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class UnitUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit UnitUI(QWidget *parent = 0);
	static void ShowUI();
	static UnitUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*description;
	void fill(Unit* unit);
Unit* unit;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectUnit();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
