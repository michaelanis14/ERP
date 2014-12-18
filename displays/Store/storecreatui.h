/**************************************************************************
**   File: storecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef STOREUI_H
#define STOREUI_H
#include "../../erpdisplay.h"
#include "storeui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/store.h"
#include "../../Model/erpmodel.h"
#include "../../Model/store.h"
#include "../../Model/country.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class StoreCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit StoreCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static StoreCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*name;
	QLineEdit*address;
	QLineEdit*postalcode;
	QLineEdit*city;
	ERPComboBox*country;
	void fill(Store* store);
Store* store;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectStore();
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
