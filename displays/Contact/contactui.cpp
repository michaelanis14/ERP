﻿/*************************************
**   Created on:  10/9/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "contactui.h"
#include "../MainWindow.h"

#include <QLineEdit>

ContactUI::ContactUI(QWidget *parent) :
	ERPDisplay(parent)
{

}
ERPDisplay* ContactUI::p_instance = 0;
/**
* A function.
* Calls the Main Window show function
* passing for the function this displays static instance
*/
void ContactUI::ShowUI() {
	if (p_instance == 0) {
		p_instance = new ContactUI(mainwindow::GetMainDisplay());
	}
	mainwindow::ShowDisplay(p_instance);
}

ContactUI* ContactUI::GetUI(){
	   if (p_instance == 0) {
		   p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	   }
	   return (ContactUI*) p_instance;

}




void ContactUI::showEvent(QShowEvent * event) {
	event->accept();
}
