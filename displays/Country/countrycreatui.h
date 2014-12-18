/**************************************************************************
**   File: countrycreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef COUNTRYUI_H
#define COUNTRYUI_H
#include "../../erpdisplay.h"
#include "countryui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/country.h"
#include "../../Model/erpmodel.h"
#include "../../Model/country.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class CountryCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit CountryCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static CountryCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*name;
	void fill(Country* country);
Country* country;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectCountry();
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
