/**************************************************************************
**   File: fieldtype.h
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef FIELDTYPE_H
#define FIELDTYPE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class FieldType  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	FieldType();
	FieldType(QString Description,QString CreatedOn,QString EditedOn);	int FieldTypeID;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	FieldType* get();
	FieldType* get(const QModelIndex &index);
	static FieldType* Get(int id);
	static FieldType* Get(QString name);
	static QList<FieldType*> GetAll();
	static QList<FieldType*> Search(QString keyword);
	static QList<FieldType*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<FieldType*> fieldtypes);
	static int GetIndex(QString title);
	static FieldType* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	FieldType(int FieldTypeID,QString Description,QString CreatedOn,QString EditedOn);	static FieldType* p_instance;
	bool setDescription(int FieldTypeID, const QString &Description);
	bool setCreatedOn(int FieldTypeID, const QString &CreatedOn);
	bool setEditedOn(int FieldTypeID, const QString &EditedOn);

};
#endif
