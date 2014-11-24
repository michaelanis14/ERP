/**************************************************************************
**   File: tax.h
**   Created on: Sun Nov 23 14:11:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef TAX_H
#define TAX_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Tax  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Tax();
	Tax(double Ratio,QString Description,QString CreatedOn,QString EditedOn);	int TaxID;
	double Ratio;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	QList<Tax*> taxs;
	static bool Init();
	bool save();
	bool remove();
	Tax* get();
	Tax* get(const QModelIndex &index);
	static Tax* Get(int id);
	static Tax* Get(QString name);
	static QList<Tax*> GetAll();
	static QList<Tax*> Search(QString keyword);
	static QList<Tax*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Tax* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Tax(int TaxID,double Ratio,QString Description,QString CreatedOn,QString EditedOn);	static Tax* p_instance;
	bool setRatio(int TaxID, const QString &ratio);
	bool setDescription(int TaxID, const QString &description);
	bool setCreatedOn(int TaxID, const QString &createdon);
	bool setEditedOn(int TaxID, const QString &editedon);

};
#endif
