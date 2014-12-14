/**************************************************************************
**   File: service.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef SERVICE_H
#define SERVICE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Service  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Service();
	Service(QString Name,QString ShortDescription,double SellingPrice,double NetCoast,double TradeMarginRate,int TaxID,QString Barcode,QString CreatedOn,QString EditedOn);	int ServiceID;
	QString Name;
	QString ShortDescription;
	double SellingPrice;
	double NetCoast;
	double TradeMarginRate;
	int TaxID;
	QString Barcode;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	Service* get();
	Service* get(const QModelIndex &index);
	static Service* Get(int id);
	static Service* Get(QString name);
	static QList<Service*> GetAll();
	static QList<Service*> Search(QString keyword);
	static QList<Service*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<Service*> services);
	static int GetIndex(QString title);
	static Service* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Service(int ServiceID,QString Name,QString ShortDescription,double SellingPrice,double NetCoast,double TradeMarginRate,int TaxID,QString Barcode,QString CreatedOn,QString EditedOn);	static Service* p_instance;
	bool setName(int ServiceID, const QString &Name);
	bool setShortDescription(int ServiceID, const QString &ShortDescription);
	bool setSellingPrice(int ServiceID, const QString &SellingPrice);
	bool setNetCoast(int ServiceID, const QString &NetCoast);
	bool setTradeMarginRate(int ServiceID, const QString &TradeMarginRate);
	bool setTaxID(int ServiceID, const QString &TaxID);
	bool setBarcode(int ServiceID, const QString &Barcode);
	bool setCreatedOn(int ServiceID, const QString &CreatedOn);
	bool setEditedOn(int ServiceID, const QString &EditedOn);

};
#endif
