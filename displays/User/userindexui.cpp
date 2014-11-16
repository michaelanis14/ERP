/**************************************************************************
**   File: userindexui.cpp
**   Created on: Sun Nov 16 16:19:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "userindexui.h"
#include "userui.h"
#include "../MainWindow.h"
#include "../../Model/erpmodel.h"

UserIndexUI::UserIndexUI(QWidget *parent) :ERPDisplay(parent)
{

flowLayout = new FlowLayout(formPanel);
flowLayout->setContentsMargins(0,0,0,0);
model = new User(); 
	model->refresh(); 
	if(!ErpModel::GetInstance()->db.open()) 
	qDebug() <<"Couldn't open databaseee!";
ERPFormBlock* block0Layout = new ERPFormBlock; 
 tabel = new QTableView(); 
 tabel->setModel(model); 
 tabel->setItemDelegate(new QSqlRelationalDelegate(tabel)); 
 tabel->setMinimumWidth(this->width()); 
 tabel->setMinimumHeight(this->height() - 50); 
 tabel->hideColumn(0); // don't show the ID 
 tabel->setSortingEnabled(true); 
 tabel->setSelectionBehavior(QAbstractItemView::SelectRows); 
 tabel->setSelectionMode(QAbstractItemView::SingleSelection); 
 block0Layout->addRow("",tabel); 
 flowLayout->addWidget(block0Layout); 
 QWidget* addremove = new QWidget(); 
 QHBoxLayout* addRemovelayout = new QHBoxLayout(addremove); 
 addRemovelayout->setContentsMargins(0,0,0,0); 
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
 addRemovelayout->addStretch(1); 
 addRemovelayout->addWidget(add,0,Qt::AlignCenter); 
 addRemovelayout->addWidget(edit,0,Qt::AlignCenter); 
 addRemovelayout->addWidget(remove,0,Qt::AlignCenter); 
 addRemovelayout->addStretch(1); 
 block0Layout->addWidget(addremove); 
 QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, this, &UserIndexUI::onSelectionChanged); 
 }
ERPDisplay* UserIndexUI::p_instance = 0;
void UserIndexUI::ShowUI() { 
	if (p_instance == 0) { 
		p_instance = new UserIndexUI(mainwindow::GetMainDisplay());
	} 
 UserIndexUI::GetUI()->model->refresh();	
 mainwindow::ShowDisplay(p_instance); 
}
UserIndexUI*UserIndexUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (UserIndexUI*) p_instance; 
}
void UserIndexUI::addRow(){ 
 UserUI::ShowUI(); 
 UserUI::GetUI()->fill(new User()); 
 }
void UserIndexUI::editRow(){ 
 UserUI::ShowUI(); 
 UserUI::GetUI()->fill(model->get(tabel->selectionModel()->selectedRows().last())); 
 }
void UserIndexUI::removeRow(){ 
 model->remove(tabel->selectionModel()->selectedRows().last()); 
 }
void UserIndexUI::onSelectionChanged(){ 
 int e = tabel->selectionModel()->selectedRows().count(); 
 remove->setEnabled(e); 
 edit->setEnabled(e); 
 }

