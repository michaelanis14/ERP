/**************************************************************************
**   File: unitui.h
**   Created on: Sun Nov 16 16:19:26 EET 2014
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
#include "../../Model/unit.h"
#include "../../Model/unit.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
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
	Unit* unit = new Unit();
private:
	static ERPDisplay* p_instance;
private slots:
	void selectUnit();
	void cancel();
	void clear();
public slots:
	void save();
};
#endif
