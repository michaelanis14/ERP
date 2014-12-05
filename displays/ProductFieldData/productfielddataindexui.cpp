/**************************************************************************
**   File: productfielddataindexui.cpp
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "productfielddataindexui.h"
#include "productfielddataui.h"
#include "../MainWindow.h"
#include "../../Model/erpmodel.h"

ProductFieldDataIndexUI::ProductFieldDataIndexUI(QWidget *parent) :ERPDisplay(parent)
{

this->setObjectName("ProductFieldDataIndexUI");
flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);
model = new ProductFieldData(); 
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
 QObject::connect(tabel->tabel->selectionModel(), &QItemSelectionModel::selectionChanged, this, &ProductFieldDataIndexUI::onSelectionChanged);
this->controllers->addControllerButton(add); 
 this->controllers->addControllerButton(edit);  
 this->controllers->addControllerButton(remove);
}
ERPDisplay* ProductFieldDataIndexUI::p_instance = 0;
void ProductFieldDataIndexUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new ProductFieldDataIndexUI(mainwindow::GetMainDisplay()); 	
 mainwindow::ShowDisplay(p_instance); 
}
ProductFieldDataIndexUI*ProductFieldDataIndexUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (ProductFieldDataIndexUI*) p_instance; 
}
void ProductFieldDataIndexUI::addRow(){ 
 ProductFieldDataUI::ShowUI(); 
 ProductFieldDataUI::GetUI()->fill(new ProductFieldData()); 
 }
void ProductFieldDataIndexUI::editRow(){ 
 ProductFieldDataUI::ShowUI(); 
 ProductFieldDataUI::GetUI()->fill(model->get(tabel->tabel->selectionModel()->selectedRows().last())); 
 }
void ProductFieldDataIndexUI::removeRow(){ 
 model->remove(tabel->tabel->selectionModel()->selectedRows().last()); 
 }
void ProductFieldDataIndexUI::onSelectionChanged(){ 
 int e = tabel->tabel->selectionModel()->selectedRows().count(); 
 remove->setEnabled(e); 
 edit->setEnabled(e); 
 }
void ProductFieldDataIndexUI::showEvent(QShowEvent * event){ 
 	if(this->parent() != 0){ 
 tabel->setMinimumWidth(mainwindow::GetMainDisplay()->width() - mainwindow::GetMainDisplay()->navigation->width() - 50); 
 tabel->setMinimumHeight(mainwindow::GetMainDisplay()->height() - mainwindow::GetMainDisplay()->inNavContacts->height() - 100); 
	} 
 event->accept(); 
 }

