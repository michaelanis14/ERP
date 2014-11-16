/**************************************************************************
**   File: countryui.h
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef COUNTRYUI_H
#define COUNTRYUI_H
#include "../../erpdisplay.h"
#include "countryindexui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../../Model/country.h"
#include "../../Model/country.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
class CountryUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit CountryUI(QWidget *parent = 0);
	static void ShowUI();
	static CountryUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*name;
	void fill(Country* country);
	Country* country = new Country();
private:
	static ERPDisplay* p_instance;
private slots:
	void selectCountry();
	void cancel();
	void clear();
public slots:
	void save();
};
#endif
