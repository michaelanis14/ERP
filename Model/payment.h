/**************************************************************************
**   File: payment.h
**   Created on: Fri Dec 05 14:22:26 EET 2014
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
	Payment(int InvoiceID,QString Title,double TotalAmount,QString Comment,int PaymentTypeID,QString CreatedOn,QString EditedOn);	int PaymentID;
	int InvoiceID;
	QString Title;
	double TotalAmount;
	QString Comment;
	int PaymentTypeID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	Payment* get();
	Payment* get(const QModelIndex &index);
	static Payment* Get(int id);
	static Payment* Get(QString name);
	static QList<Payment*> GetAll();
	static QList<Payment*> Search(QString keyword);
	static QList<Payment*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Payment* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Payment(int PaymentID,int InvoiceID,QString Title,double TotalAmount,QString Comment,int PaymentTypeID,QString CreatedOn,QString EditedOn);	static Payment* p_instance;
	bool setInvoiceID(int PaymentID, const QString &InvoiceID);
	bool setTitle(int PaymentID, const QString &Title);
	bool setTotalAmount(int PaymentID, const QString &TotalAmount);
	bool setComment(int PaymentID, const QString &Comment);
	bool setPaymentTypeID(int PaymentID, const QString &PaymentTypeID);
	bool setCreatedOn(int PaymentID, const QString &CreatedOn);
	bool setEditedOn(int PaymentID, const QString &EditedOn);

};
#endif
