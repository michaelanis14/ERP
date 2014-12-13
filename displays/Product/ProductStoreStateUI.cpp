/*************************************
**   Created on:  12/1/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "ProductStoreStateUI.h"

#include "../MainWindow.h"
#include "../../Model/erpmodel.h"
#include "../../Model/product.h"
#include "../../Model/store.h"
#include "../../Model/purchasestoreproduct.h"
#include "../../Model/deliveryorderstoreproduct.h"




ProductStoreStateUI::ProductStoreStateUI(QWidget *parent) :
	ERPDisplay(parent)
{
	this->setObjectName("ProductStoreStateUI");

	flowLayout = new FlowLayout(formPanel);
	flowLayout->setContentsMargins(0,0,0,0);
	ERPFormBlock* block0Layout = new ERPFormBlock;
	store = new ERPComboBox();
	store->addItems(Store::GetPairList());
	QObject::connect(store, SIGNAL(currentIndexChanged(QString)), this, SLOT(selectionChanged(QString)));
	block0Layout->addRow("Store",store);

	tabel = new ERPTableView();
//
	refreshTabel();
	//tabel->tabel->hideColumn(0);
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("Store"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("Barcode"));
	model->setHeaderData(3, Qt::Horizontal, QObject::tr("Name"));
	model->setHeaderData(4, Qt::Horizontal, QObject::tr("Amount"));


	block0Layout->addRow("",tabel);



	flowLayout->addWidget(block0Layout);
}
ERPDisplay* ProductStoreStateUI::p_instance = 0;
void ProductStoreStateUI::ShowUI() {

	if (p_instance != 0)
		p_instance->deleteLater();
		p_instance = new ProductStoreStateUI(mainwindow::GetMainDisplay());
//	}
	//ProductStoreStateUI::GetUI()->model->refresh();
	mainwindow::ShowDisplay(p_instance);
}
ProductStoreStateUI*ProductStoreStateUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (ProductStoreStateUI*) p_instance;
}

void ProductStoreStateUI::showEvent(QShowEvent * event){
	if(this->parent() != 0){
		tabel->setMinimumWidth(mainwindow::GetMainDisplay()->width() - mainwindow::GetMainDisplay()->navigation->width() - 50);
		tabel->setMinimumHeight(mainwindow::GetMainDisplay()->height() - mainwindow::GetMainDisplay()->inNavContacts->height() - 100);
	}
	event->accept();
}
void ProductStoreStateUI::refreshTabel(){
	QList<Product*> products = Product::GetAll();
	model = new QStandardItemModel(products.count(),3,0);

	int row = 0; //row

	foreach(Product* p,products){
		QList<PurchaseStoreProduct*> purchases = PurchaseStoreProduct::QuerySelect("ProductID ="+ QString::number(p->ProductID)+" AND StoreID = " +QString::number(store->getKey()));
		int purchasesSum = 0;
		for(int i = 0; i < purchases.size();i++){
			purchasesSum += (purchases[i]->Amount);
		}

		QList<DeliveryOrderStoreProduct*> deliveries = DeliveryOrderStoreProduct::QuerySelect("ProductID = "+ QString::number(p->ProductID)+" AND StoreID = " +QString::number(store->getKey()));
		int deliveriesSum = 0;
		for(int i = 0; i < deliveries.size();i++){
			deliveriesSum += (deliveries[i]->Amount);
		}

		model->setItem(row,0,new QStandardItem(QString::number(p->ProductID)));
		model->setItem(row,1,new QStandardItem(store->currentText()));

		model->setItem(row,2,new QStandardItem(p->Barcode));
		model->setItem(row,3,new QStandardItem(p->Name));
		model->setItem(row,4,new QStandardItem(QString::number(purchasesSum - deliveriesSum)));

		row++;
	}
	tabel->tabel->hideColumn(0);

	tabel->tabel->setModel(model);
	//tabel->sortByColumn(0,Qt::DescendingOrder);

	tabel->repaint();
}
void ProductStoreStateUI::selectionChanged(QString){
	refreshTabel();
}

