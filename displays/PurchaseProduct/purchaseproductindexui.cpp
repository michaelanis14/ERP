/**************************************************************************
**   File: purchaseproductindexui.cpp
**   Created on: Mon Dec 01 14:22:11 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "purchaseproductindexui.h"
#include "purchaseproductui.h"
#include "../MainWindow.h"
#include "../../Model/erpmodel.h"

PurchaseProductIndexUI::PurchaseProductIndexUI(QWidget *parent) :ERPDisplay(parent)
{

this->setObjectName("PurchaseProductIndexUI");
flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);
model = new PurchaseProduct(); 
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
 QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, this, &PurchaseProductIndexUI::onSelectionChanged);
this->controllers->addControllerButton(add); 
 this->controllers->addControllerButton(edit);  
 this->controllers->addControllerButton(remove);
}
ERPDisplay* PurchaseProductIndexUI::p_instance = 0;
void PurchaseProductIndexUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new PurchaseProductIndexUI(mainwindow::GetMainDisplay());
	} 
 PurchaseProductIndexUI::GetUI()->model->refresh();	
 mainwindow::ShowDisplay(p_instance); 
}
PurchaseProductIndexUI*PurchaseProductIndexUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (PurchaseProductIndexUI*) p_instance; 
}
void PurchaseProductIndexUI::addRow(){ 
 PurchaseProductUI::ShowUI(); 
 PurchaseProductUI::GetUI()->fill(new PurchaseProduct()); 
 }
void PurchaseProductIndexUI::editRow(){ 
 PurchaseProductUI::ShowUI(); 
 PurchaseProductUI::GetUI()->fill(model->get(tabel->selectionModel()->selectedRows().last())); 
 }
void PurchaseProductIndexUI::removeRow(){ 
 model->remove(tabel->selectionModel()->selectedRows().last()); 
 }
void PurchaseProductIndexUI::onSelectionChanged(){ 
 int e = tabel->selectionModel()->selectedRows().count(); 
 remove->setEnabled(e); 
 edit->setEnabled(e); 
 }
void PurchaseProductIndexUI::showEvent(QShowEvent * event){ 
 	if(this->parent() != 0){ 
 tabel->setMinimumWidth(mainwindow::GetMainDisplay()->width() - mainwindow::GetMainDisplay()->navigation->width() - 50); 
 tabel->setMinimumHeight(mainwindow::GetMainDisplay()->height() - mainwindow::GetMainDisplay()->inNavContacts->height() - 100); 
	} 
 event->accept(); 
 }

