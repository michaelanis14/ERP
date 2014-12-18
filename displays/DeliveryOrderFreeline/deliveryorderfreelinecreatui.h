/**************************************************************************
**   File: deliveryorderfreelinecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef DELIVERYORDERFREELINEUI_H
#define DELIVERYORDERFREELINEUI_H
#include "../../erpdisplay.h"
#include "deliveryorderfreelineui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/deliveryorderfreeline.h"
#include "../../Model/erpmodel.h"
#include "../../Model/deliveryorderfreeline.h"
#include "../../Model/deliveryorder.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class DeliveryOrderFreelineCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit DeliveryOrderFreelineCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static DeliveryOrderFreelineCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	ERPComboBox*deliveryorder;
	QLineEdit*description;
	QLineEdit*amount;
	QLineEdit*price;
	void fill(DeliveryOrderFreeline* deliveryorderfreeline);
DeliveryOrderFreeline* deliveryorderfreeline;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectDeliveryOrderFreeline();
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
