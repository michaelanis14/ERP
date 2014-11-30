/**************************************************************************
**   File: deliveryorderstatusindexui.cpp
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "deliveryorderstatusindexui.h"
#include "deliveryorderstatusui.h"
#include "../MainWindow.h"
#include "../../Model/erpmodel.h"

DeliveryOrderStatusIndexUI::DeliveryOrderStatusIndexUI(QWidget *parent) :ERPDisplay(parent)
{

this->setObjectName("DeliveryOrderStatusIndexUI");
flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);
model = new DeliveryOrderStatus(); 
	model->refresh(); 
	if(!ErpModel::GetInstance()->db.open()) 
	qDebug() <<"Couldn't open databaseee!";
ERPFormBlock* block0Layout = new ERPFormBlock; 
 tabel = new QTableView(); 
 tabel->setModel(model); 
 tabel->setItemDelegate(new QSqlRelationalDelegate(tabel)); 
 tabel->hideColumn(0); // don't show the ID 
 tabel->setSortingEnabled(true); 
 tabel->setSelectionBehavior(QAbstractItemView::SelectRows); 
 tabel->setSelectionMode(QAbstractItemView::SingleSelection); 
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
 QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, this, &DeliveryOrderStatusIndexUI::onSelectionChanged);
this->controllers->addControllerButton(add); 
 this->controllers->addControllerButton(edit);  
 this->controllers->addControllerButton(remove);
}
ERPDisplay* DeliveryOrderStatusIndexUI::p_instance = 0;
void DeliveryOrderStatusIndexUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new DeliveryOrderStatusIndexUI(mainwindow::GetMainDisplay());
	} 
 DeliveryOrderStatusIndexUI::GetUI()->model->refresh();	
 mainwindow::ShowDisplay(p_instance); 
}
DeliveryOrderStatusIndexUI*DeliveryOrderStatusIndexUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (DeliveryOrderStatusIndexUI*) p_instance; 
}
void DeliveryOrderStatusIndexUI::addRow(){ 
 DeliveryOrderStatusUI::ShowUI(); 
 DeliveryOrderStatusUI::GetUI()->fill(new DeliveryOrderStatus()); 
 }
void DeliveryOrderStatusIndexUI::editRow(){ 
 DeliveryOrderStatusUI::ShowUI(); 
 DeliveryOrderStatusUI::GetUI()->fill(model->get(tabel->selectionModel()->selectedRows().last())); 
 }
void DeliveryOrderStatusIndexUI::removeRow(){ 
 model->remove(tabel->selectionModel()->selectedRows().last()); 
 }
void DeliveryOrderStatusIndexUI::onSelectionChanged(){ 
 int e = tabel->selectionModel()->selectedRows().count(); 
 remove->setEnabled(e); 
 edit->setEnabled(e); 
 }
void DeliveryOrderStatusIndexUI::showEvent(QShowEvent * event){ 
 	if(this->parent() != 0){ 
 tabel->setMinimumWidth(mainwindow::GetMainDisplay()->width() - mainwindow::GetMainDisplay()->navigation->width() - 50); 
 tabel->setMinimumHeight(mainwindow::GetMainDisplay()->height() - mainwindow::GetMainDisplay()->inNavContacts->height() - 100); 
	} 
 event->accept(); 
 }

