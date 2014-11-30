/**************************************************************************
**   File: paymentindexui.cpp
**   Created on: Sun Nov 30 23:37:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "paymentindexui.h"
#include "paymentui.h"
#include "../MainWindow.h"
#include "../../Model/erpmodel.h"

PaymentIndexUI::PaymentIndexUI(QWidget *parent) :ERPDisplay(parent)
{

this->setObjectName("PaymentIndexUI");
flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);
model = new Payment(); 
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
 QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, this, &PaymentIndexUI::onSelectionChanged);
this->controllers->addControllerButton(add); 
 this->controllers->addControllerButton(edit);  
 this->controllers->addControllerButton(remove);
}
ERPDisplay* PaymentIndexUI::p_instance = 0;
void PaymentIndexUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new PaymentIndexUI(mainwindow::GetMainDisplay());
	} 
 PaymentIndexUI::GetUI()->model->refresh();	
 mainwindow::ShowDisplay(p_instance); 
}
PaymentIndexUI*PaymentIndexUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (PaymentIndexUI*) p_instance; 
}
void PaymentIndexUI::addRow(){ 
 PaymentUI::ShowUI(); 
 PaymentUI::GetUI()->fill(new Payment()); 
 }
void PaymentIndexUI::editRow(){ 
 PaymentUI::ShowUI(); 
 PaymentUI::GetUI()->fill(model->get(tabel->selectionModel()->selectedRows().last())); 
 }
void PaymentIndexUI::removeRow(){ 
 model->remove(tabel->selectionModel()->selectedRows().last()); 
 }
void PaymentIndexUI::onSelectionChanged(){ 
 int e = tabel->selectionModel()->selectedRows().count(); 
 remove->setEnabled(e); 
 edit->setEnabled(e); 
 }
void PaymentIndexUI::showEvent(QShowEvent * event){ 
 	if(this->parent() != 0){ 
 tabel->setMinimumWidth(mainwindow::GetMainDisplay()->width() - mainwindow::GetMainDisplay()->navigation->width() - 50); 
 tabel->setMinimumHeight(mainwindow::GetMainDisplay()->height() - mainwindow::GetMainDisplay()->inNavContacts->height() - 100); 
	} 
 event->accept(); 
 }

