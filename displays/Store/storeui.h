/**************************************************************************
**   File: storeui.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef STOREUI_H
#define STOREUI_H
#include "../../erpdisplay.h"
#include "storeindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/store.h"
#include "../../Model/store.h"
#include "../../Model/country.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QDateEdit>
class StoreUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit StoreUI(QWidget *parent = 0);
	static void ShowUI();
	static StoreUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*name;
	QLineEdit*address;
	QLineEdit*postalcode;
	QLineEdit*city;
	ERPComboBox*country;
	void fill(Store* store);
Store* store;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectStore();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
