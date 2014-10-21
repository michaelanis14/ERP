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


	Contact contact;
	~contactIndexUI();

private:
	Ui::contactIndexUI *ui;
	static ERPDisplay* p_instance;
	class QVBoxLayout* boxLayout;
	class FlowLayout * flowLayout;
	ERPComboBox* combo;
protected slots:


protected:
	void showEvent(QShowEvent * event);
};

#endif // CONTACTINDEXUI_H
