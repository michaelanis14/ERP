/**************************************************************************
**   File: product.h
**   Created on: Sat Oct 18 13:10:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <QtGui>

class Product
{
public:
	Product();
	Product(QString Name,double SellingPrice,double NetPrice,double TradeMargine,QString Description,QString Barcode,double CriticalAmount,QString ProductNumber,QString MoreInfo,bool BarcodeOnly,bool isComposite,QString SpecialTaxDescription,double SpecialTaxValue,int TaxID,int UnitID,bool generateBarcode,QString ShortDescription);	int ProductID;
	QString Name;
	double SellingPrice;
	double NetPrice;
	double TradeMargine;
	QString Description;
	QString Barcode;
	double CriticalAmount;
	QString ProductNumber;
	QString MoreInfo;
	bool BarcodeOnly;
	bool isComposite;
	QString SpecialTaxDescription;
	double SpecialTaxValue;
	int TaxID;
	int UnitID;
	bool generateBarcode;
	QString ShortDescription;
	QList<Product*> products;
	static bool init();
	bool save();
	bool remove();
	Product* get();
	static Product* get(int id);
	static Product* get(QString name);
	static QList<Product*> getAll();
	static QList<Product*> search(QString keyword);
	static QList<Product*> select(QString select);
	static QList<QString> GetStringList();
	static int GetIndex(QString title);
	static Product* GetInstance();

private:
	Product(int ProductID,QString Name,double SellingPrice,double NetPrice,double TradeMargine,QString Description,QString Barcode,double CriticalAmount,QString ProductNumber,QString MoreInfo,bool BarcodeOnly,bool isComposite,QString SpecialTaxDescription,double SpecialTaxValue,int TaxID,int UnitID,bool generateBarcode,QString ShortDescription);
	static Product* p_instance;

};
#endif
