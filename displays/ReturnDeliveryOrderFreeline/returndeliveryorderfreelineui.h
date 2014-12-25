/**************************************************************************
**   File: returndeliveryorderfreelineui.h
**   Created on: Fri Dec 19 13:54:40 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef RETURNDELIVERYORDERFREELINEUI_H
#define RETURNDELIVERYORDERFREELINEUI_H
#include "../../erpdisplay.h"
#include "returndeliveryorderfreelineindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/returndeliveryorderfreeline.h"
#include "../../Model/erpmodel.h"
#include "../../Model/returndeliveryorderfreeline.h"
#include "../../Model/returndeliveryorder.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class ReturnDeliveryOrderFreelineUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ReturnDeliveryOrderFreelineUI(QWidget *parent = 0);
	static void ShowUI();
	static ReturnDeliveryOrderFreelineUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPComboBox*returndeliveryorder;
	QLineEdit*description;
	QLineEdit*amount;
	QLineEdit*price;
	void fill(ReturnDeliveryOrderFreeline* returndeliveryorderfreeline);
ReturnDeliveryOrderFreeline* returndeliveryorderfreeline;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectReturnDeliveryOrderFreeline();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
