/*************************************
**   Created on:  10/3/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef CONTACTINDEXUI_H
#define CONTACTINDEXUI_H



#include "../CommonUI/erpcombobox.h"
#include "../../erpdisplay.h"
#include "../../Model/contact.h"
#include "../CommonUI/flowlayout.h"
#include "../CommonUI/erpformblock.h"

#include <QWidget>
#include <QPushButton>
#include <QTableView>
#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>



namespace Ui {
class contactIndexUI;
}

class contactIndexUI : public ERPDisplay
{
	Q_OBJECT

public:
	explicit contactIndexUI(QWidget *parent = 0);

	static void ShowUI();
	static contactIndexUI* GetUI();
	QTableView *view;
	Contact *model;
	Contact contact;
	QPushButton* remove;
	~contactIndexUI();

private:
	Ui::contactIndexUI *ui;
	static ERPDisplay* p_instance;
	class QVBoxLayout* boxLayout;
	class FlowLayout * flowLayout;
	ERPComboBox* combo;

protected:
	void showEvent(QShowEvent * event);
private slots:
	void addRow();
	void removeRow();
	void onSelectionChanged();

};

#endif // CONTACTINDEXUI_H
