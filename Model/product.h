/**************************************************************************
**   File: product.h
**   Created on: Sun Nov 16 16:19:26 EET 2014
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
	Product(QString Name,double SellingPrice,double NetPrice,double TradeMargine,QString Description,QString Barcode,double CriticalAmount,QString ProductNumber,QString MoreInfo,bool BarcodeOnly,bool isComposite,QString SpecialTaxDescription,double SpecialTaxValue,int TaxID,int UnitID,bool generateBarcode,QString ShortDescription,QString CreatedOn,QString EditedOn);	int ProductID;
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
	QString CreatedOn;
	QString EditedOn;
	QList<Product*> products;
	static bool Init();
	bool save();
	bool remove();
	Product* get();
	Product* get(const QModelIndex &index);
	static Product* Get(int id);
	static Product* Get(QString name);
	static QList<Product*> GetAll();
	static QList<Product*> Search(QString keyword);
	static QList<Product*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Product* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Product(int ProductID,QString Name,double SellingPrice,double NetPrice,double TradeMargine,QString Description,QString Barcode,double CriticalAmount,QString ProductNumber,QString MoreInfo,bool BarcodeOnly,bool isComposite,QString SpecialTaxDescription,double SpecialTaxValue,int TaxID,int UnitID,bool generateBarcode,QString ShortDescription,QString CreatedOn,QString EditedOn);	static Product* p_instance;
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
	bool setCreatedOn(int ProductID, const QString &createdon);
	bool setEditedOn(int ProductID, const QString &editedon);

};
#endif
