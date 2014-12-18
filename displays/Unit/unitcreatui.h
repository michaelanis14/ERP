/**************************************************************************
**   File: unitcreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef UNITUI_H
#define UNITUI_H
#include "../../erpdisplay.h"
#include "unitui.h"
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
#include <QHBoxLayout>
#include <QDateEdit>
class UnitCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit UnitCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static UnitCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*description;
	void fill(Unit* unit);
Unit* unit;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectUnit();
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
