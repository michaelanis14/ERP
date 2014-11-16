/**************************************************************************
**   File: taxui.h
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef TAXUI_H
#define TAXUI_H
#include "../../erpdisplay.h"
#include "taxindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../../Model/tax.h"
#include "../../Model/tax.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
class TaxUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit TaxUI(QWidget *parent = 0);
	static void ShowUI();
	static TaxUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*ratio;
	QLineEdit*description;
	void fill(Tax* tax);
	Tax* tax = new Tax();
private:
	static ERPDisplay* p_instance;
private slots:
	void selectTax();
	void cancel();
	void clear();
public slots:
	void save();
};
#endif
