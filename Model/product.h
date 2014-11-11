/**************************************************************************
**   File: product.h
**   Created on: Tue Nov 11 17:36:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Product  : public QSqlRelationalTableModel
{
	Q_OBJECT
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
	static QList<Product*> querySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Product* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Product(int ProductID,QString Name,double SellingPrice,double NetPrice,double TradeMargine,QString Description,QString Barcode,double CriticalAmount,QString ProductNumber,QString MoreInfo,bool BarcodeOnly,bool isComposite,QString SpecialTaxDescription,double SpecialTaxValue,int TaxID,int UnitID,bool generateBarcode,QString ShortDescription);	static Product* p_instance;
	bool setName(int ProductID, const QString &name);
	bool setSellingPrice(int ProductID, const QString &sellingprice);
	bool setNetPrice(int ProductID, const QString &netprice);
	bool setTradeMargine(int ProductID, const QString &trademargine);
	bool setDescription(int ProductID, const QString &description);
	bool setBarcode(int ProductID, const QString &barcode);
	bool setCriticalAmount(int ProductID, const QString &criticalamount);
	bool setProductNumber(int ProductID, const QString &productnumber);
	bool setMoreInfo(int ProductID, const QString &moreinfo);
	bool setBarcodeOnly(int ProductID, const QString &barcodeonly);
	bool setisComposite(int ProductID, const QString &iscomposite);
	bool setSpecialTaxDescription(int ProductID, const QString &specialtaxdescription);
	bool setSpecialTaxValue(int ProductID, const QString &specialtaxvalue);
	bool setTaxID(int ProductID, const QString &taxid);
	bool setUnitID(int ProductID, const QString &unitid);
	bool setgenerateBarcode(int ProductID, const QString &generatebarcode);
	bool setShortDescription(int ProductID, const QString &shortdescription);

};
#endif
