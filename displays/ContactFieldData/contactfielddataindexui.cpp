/**************************************************************************
**   File: contactfielddataindexui.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "contactfielddataindexui.h"
#include "contactfielddataui.h"
#include "../MainWindow.h"
#include "../../Model/erpmodel.h"

ContactFieldDataIndexUI::ContactFieldDataIndexUI(QWidget *parent) :ERPDisplay(parent)
{

this->setObjectName("ContactFieldDataIndexUI");
flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);
model = new ContactFieldData(); 
	model->refresh(); 
	if(!ErpModel::GetInstance()->db.open()) 
	qDebug() <<"Couldn't open databaseee!";
ERPFormBlock* block0Layout = new ERPFormBlock; 
 tabel = new ERPTableView(); 
 tabel->tabel->setModel(model); 
 block0Layout->addRow("",tabel); 
 flowLayout->addWidget(block0Layout); 
  add = new QPushButton("Add"); 
 QObject::connect(add, SIGNAL(clicked()), this, SLOT(addRow())); 
 add->setObjectName("add"); 
 remove = new QPushButton("Remove"); 
 remove->setObjectName("remove"); 
 QObject::connect(remove, SIGNAL(clicked()), this, SLOT(removeRow())); 
 edit = new QPushButton("Edit"); 
 QObject::connect(edit, SIGNAL(clicked()), this, SLOT(editRow())); 
 edit->setObjectName("edit"); 
 edit->setEnabled(false); 
 remove->setEnabled(false); 
 QObject::connect(tabel->tabel->selectionModel(), &QItemSelectionModel::selectionChanged, this, &ContactFieldDataIndexUI::onSelectionChanged);
this->controllers->addControllerButton(add); 
 this->controllers->addControllerButton(edit);  
 this->controllers->addControllerButton(remove);
}
ERPDisplay* ContactFieldDataIndexUI::p_instance = 0;
void ContactFieldDataIndexUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ContactFieldDataIndexUI(mainwindow::GetMainDisplay()); 	
 mainwindow::ShowDisplay(p_instance); 
}
ContactFieldDataIndexUI*ContactFieldDataIndexUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ContactFieldDataIndexUI*) p_instance; 
}
void ContactFieldDataIndexUI::addRow(){ 
 ContactFieldDataUI::ShowUI(); 
 ContactFieldDataUI::GetUI()->fill(new ContactFieldData()); 
 }
void ContactFieldDataIndexUI::editRow(){ 
 ContactFieldDataUI::ShowUI(); 
 ContactFieldDataUI::GetUI()->fill(model->get(tabel->tabel->selectionModel()->selectedRows().last())); 
 }
void ContactFieldDataIndexUI::removeRow(){ 
 model->remove(tabel->tabel->selectionModel()->selectedRows().last()); 
 }
void ContactFieldDataIndexUI::onSelectionChanged(){ 
 int e = tabel->tabel->selectionModel()->selectedRows().count(); 
 remove->setEnabled(e); 
 edit->setEnabled(e); 
 }
void ContactFieldDataIndexUI::showEvent(QShowEvent * event){ 
 	if(this->parent() != 0){ 
 tabel->setMinimumWidth(mainwindow::GetMainDisplay()->width() - mainwindow::GetMainDisplay()->navigation->width() - 50); 
 tabel->setMinimumHeight(mainwindow::GetMainDisplay()->height() - mainwindow::GetMainDisplay()->inNavContacts->height() - 100); 
	} 
 event->accept(); 
 }

