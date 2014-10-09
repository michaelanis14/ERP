/*************************************
**   Created on:  10/9/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef CONTACTUI_H
#define CONTACTUI_H

#include "../../erpdisplay.h"
#include "../../Model/contact.h"
#include "../CommonUI/flowlayout.h"
#include "../CommonUI/erpformblock.h"

#include <QWidget>

class ContactUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ContactUI(QWidget *parent = 0);
	static void ShowUI();
	static ContactUI* GetUI();

	Contact contact;
private:
	static ERPDisplay* p_instance;

protected:
	void showEvent(QShowEvent * event);

};

#endif // CONTACTUI_H
