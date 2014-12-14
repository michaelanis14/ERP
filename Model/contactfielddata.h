/**************************************************************************
**   File: contactfielddata.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTFIELDDATA_H
#define CONTACTFIELDDATA_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ContactFieldData  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ContactFieldData();
	ContactFieldData(int ContactID,int ContactFieldID,QString Value,QString CreatedOn,QString EditedOn);	int ContactFieldDataID;
	int ContactID;
	int ContactFieldID;
	QString Value;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ContactFieldData* get();
	ContactFieldData* get(const QModelIndex &index);
	static ContactFieldData* Get(int id);
	static ContactFieldData* Get(QString name);
	static QList<ContactFieldData*> GetAll();
	static QList<ContactFieldData*> Search(QString keyword);
	static QList<ContactFieldData*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ContactFieldData*> contactfielddatas);
	static int GetIndex(QString title);
	static ContactFieldData* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactFieldData(int ContactFieldDataID,int ContactID,int ContactFieldID,QString Value,QString CreatedOn,QString EditedOn);	static ContactFieldData* p_instance;
	bool setContactID(int ContactFieldDataID, const QString &ContactID);
	bool setContactFieldID(int ContactFieldDataID, const QString &ContactFieldID);
	bool setValue(int ContactFieldDataID, const QString &Value);
	bool setCreatedOn(int ContactFieldDataID, const QString &CreatedOn);
	bool setEditedOn(int ContactFieldDataID, const QString &EditedOn);

};
#endif
