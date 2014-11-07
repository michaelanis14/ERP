/*************************************
**   Created on:  10/3/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/



#include "contactindexui.h"
#include "contactui.h"
#include "ui_contactindexui.h"
#include "../MainWindow.h"
#include "../../Model/erpmodel.h"


#include <QLineEdit>

#include <QtSql>
#include <QSqlQueryModel>
#include <QModelIndex>
#include <QSqlRelationalTableModel>



contactIndexUI::contactIndexUI(QWidget *parent) :
	ERPDisplay(parent)
{
	//ui->setupUi(this);
	flowLayout = new FlowLayout(formPanel);

	flowLayout->setContentsMargins(0,0,0,0);
	ERPFormBlock* block0Layout = new ERPFormBlock;
	//Index = new QTableView(this);


	model = new Contact();

//	model->setQuery("select * from Contact");


	model->refresh();
	//model->setHeaderData(0, Qt::Horizontal, ("Name"));
	//model->setHeaderData(1, Qt::Horizontal, ("Salary"));
	if(!ErpModel::GetInstance()->db.open())
	qDebug() <<"Couldn't open databaseee!";

	view = new QTableView();
	view->setModel(model);
	view->setItemDelegate(new QSqlRelationalDelegate(view));
	view->setMinimumWidth(600);
	view->hideColumn(0); // don't show the ID
	//view->show();
	//view->horizontalHeader()->setSectionResizeMode(QTableView::);
	view->setSortingEnabled(true);

	block0Layout->addRow("",view);
	ErpModel::GetInstance()->db.close();
	flowLayout->addWidget(block0Layout);

	QWidget* addremove = new QWidget();
	QHBoxLayout* addRemovelayout = new QHBoxLayout(addremove);
	addRemovelayout->setContentsMargins(0,0,0,0);
	QPushButton* add = new QPushButton("Add");
	QObject::connect(add, SIGNAL(clicked()), this, SLOT(addRow()));
	add->setObjectName("add");
	remove = new QPushButton("Remove");
	remove->setObjectName("remove");
	QObject::connect(remove, SIGNAL(clicked()), this, SLOT(removeRow()));

	remove->setEnabled(false);


	addRemovelayout->addStretch(1);
	addRemovelayout->addWidget(add,0,Qt::AlignCenter);
	addRemovelayout->addStretch(0);
	addRemovelayout->addWidget(remove,0,Qt::AlignCenter);
	addRemovelayout->addStretch(1);

	block0Layout->addWidget(addremove);

	// enable remove button when a row is selected
	QObject::connect(view->selectionModel(), &QItemSelectionModel::selectionChanged, this, &contactIndexUI::onSelectionChanged);



}
ERPDisplay* contactIndexUI::p_instance = 0;
/**
* A function.
* Calls the Main Window show function
* passing for the function this displays static instance
*/
void contactIndexUI::ShowUI() {
	if (p_instance == 0) {
		p_instance = new contactIndexUI(mainwindow::GetMainDisplay());
	}
	contactIndexUI::GetUI()->model->refresh();
	mainwindow::ShowDisplay(p_instance);
}

contactIndexUI* contactIndexUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (contactIndexUI*) p_instance;

}

void contactIndexUI::addRow(){
	ContactUI::ShowUI();
}
void contactIndexUI::removeRow()
{
	qDebug() << view->selectionModel()->selectedRows();
	foreach (const QModelIndex &index, view->selectionModel()->selectedRows()) {

		model->remove(index);

	}
}

void contactIndexUI::onSelectionChanged()
{
	remove->setEnabled(view->selectionModel()->selectedRows().count());
}


void contactIndexUI::showEvent(QShowEvent * event) {

	event->accept();
}
contactIndexUI::~contactIndexUI()
{
	delete ui;
}
