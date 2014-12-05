/*************************************
**   Created on:  12/1/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef PRODUCTSTORESTATEUI_H
#define PRODUCTSTORESTATEUI_H
#include "../../erpdisplay.h"

#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include <QWidget>
#include <QStandardItemModel>
#include <QLineEdit>
#include <QPushButton>
#include <QtSql>

#ifndef QT_NO_PRINTER
#include "../CommonUI/erptableview.h"

#endif

class ProductStoreStateUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductStoreStateUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductStoreStateUI* GetUI();
	ERPTableView *tabel;
	ERPComboBox *store;
	QStandardItemModel *model;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();


protected:
void showEvent(QShowEvent * event);
public slots:
	void selectionChanged(QString);
};

#endif // PRODUCTSTORESTATEUI_H
