/**************************************************************************
**   File: productfield.h
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PRODUCTFIELD_H
#define PRODUCTFIELD_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ProductField  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ProductField();
	ProductField(QString Description,int FieldTypeID,bool Defaults,QString CreatedOn,QString EditedOn);	int ProductFieldID;
	QString Description;
	int FieldTypeID;
	bool Defaults;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	ProductField* get();
	ProductField* get(const QModelIndex &index);
	static ProductField* Get(int id);
	static ProductField* Get(QString name);
	static QList<ProductField*> GetAll();
	static QList<ProductField*> Search(QString keyword);
	static QList<ProductField*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static ProductField* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ProductField(int ProductFieldID,QString Description,int FieldTypeID,bool Defaults,QString CreatedOn,QString EditedOn);	static ProductField* p_instance;
	bool setDescription(int ProductFieldID, const QString &Description);
	bool setFieldTypeID(int ProductFieldID, const QString &FieldTypeID);
	bool setDefaults(int ProductFieldID, const QString &Defaults);
	bool setCreatedOn(int ProductFieldID, const QString &CreatedOn);
	bool setEditedOn(int ProductFieldID, const QString &EditedOn);

};
#endif
