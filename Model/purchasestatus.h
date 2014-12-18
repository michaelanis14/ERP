/**************************************************************************
**   File: purchasestatus.h
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PURCHASESTATUS_H
#define PURCHASESTATUS_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class PurchaseStatus  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	PurchaseStatus();
	PurchaseStatus(QString Description,QString CreatedOn,QString EditedOn);	int PurchaseStatusID;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	PurchaseStatus* get();
	PurchaseStatus* get(const QModelIndex &index);
	static PurchaseStatus* Get(int id);
	static PurchaseStatus* Get(QString name);
	static QList<PurchaseStatus*> GetAll();
	static QList<PurchaseStatus*> Search(QString keyword);
	static QList<PurchaseStatus*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<PurchaseStatus*> purchasestatuss);
	static int GetIndex(QString title);
	static PurchaseStatus* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	PurchaseStatus(int PurchaseStatusID,QString Description,QString CreatedOn,QString EditedOn);	static PurchaseStatus* p_instance;
	bool setDescription(int PurchaseStatusID, const QString &Description);
	bool setCreatedOn(int PurchaseStatusID, const QString &CreatedOn);
	bool setEditedOn(int PurchaseStatusID, const QString &EditedOn);

};
#endif
