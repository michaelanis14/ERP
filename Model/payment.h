/**************************************************************************
**   File: payment.h
**   Created on: Sat Dec 20 02:32:00 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PAYMENT_H
#define PAYMENT_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Payment  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Payment();
	Payment(int PaymentTypeID,int ContactID,int ProjectID,QDate Date,double NetAmount,double GrossAmount,QString Comment,QString CreatedOn,QString EditedOn);	int PaymentID;
	int PaymentTypeID;
	int ContactID;
	int ProjectID;
	QDate Date;
	double NetAmount;
	double GrossAmount;
	QString Comment;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	Payment* get();
	Payment* get(const QModelIndex &index);
	static Payment* Get(int id);
	static Payment* Get(QString name);
	static QList<Payment*> GetAll();
	static QList<Payment*> Search(QString keyword);
	static QList<Payment*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<Payment*> payments);
	static int GetIndex(QString title);
	static Payment* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Payment(int PaymentID,int PaymentTypeID,int ContactID,int ProjectID,QDate Date,double NetAmount,double GrossAmount,QString Comment,QString CreatedOn,QString EditedOn);	static Payment* p_instance;
	bool setPaymentTypeID(int PaymentID, const QString &PaymentTypeID);
	bool setContactID(int PaymentID, const QString &ContactID);
	bool setProjectID(int PaymentID, const QString &ProjectID);
	bool setDate(int PaymentID, const QString &Date);
	bool setNetAmount(int PaymentID, const QString &NetAmount);
	bool setGrossAmount(int PaymentID, const QString &GrossAmount);
	bool setComment(int PaymentID, const QString &Comment);
	bool setCreatedOn(int PaymentID, const QString &CreatedOn);
	bool setEditedOn(int PaymentID, const QString &EditedOn);

};
#endif
