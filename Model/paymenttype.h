/**************************************************************************
**   File: paymenttype.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PAYMENTTYPE_H
#define PAYMENTTYPE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class PaymentType  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	PaymentType();
	PaymentType(QString Description,QString CreatedOn,QString EditedOn);	int PaymentTypeID;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	PaymentType* get();
	PaymentType* get(const QModelIndex &index);
	static PaymentType* Get(int id);
	static PaymentType* Get(QString name);
	static QList<PaymentType*> GetAll();
	static QList<PaymentType*> Search(QString keyword);
	static QList<PaymentType*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static PaymentType* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	PaymentType(int PaymentTypeID,QString Description,QString CreatedOn,QString EditedOn);	static PaymentType* p_instance;
	bool setDescription(int PaymentTypeID, const QString &Description);
	bool setCreatedOn(int PaymentTypeID, const QString &CreatedOn);
	bool setEditedOn(int PaymentTypeID, const QString &EditedOn);

};
#endif
