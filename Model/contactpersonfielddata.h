/**************************************************************************
**   File: contactpersonfielddata.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTPERSONFIELDDATA_H
#define CONTACTPERSONFIELDDATA_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ContactPersonFieldData  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ContactPersonFieldData();
	ContactPersonFieldData(int ContactPersonID,int ContactPersonFieldID,QString Value,QString CreatedOn,QString EditedOn);	int ContactPersonFieldDataID;
	int ContactPersonID;
	int ContactPersonFieldID;
	QString Value;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ContactPersonFieldData* get();
	ContactPersonFieldData* get(const QModelIndex &index);
	static ContactPersonFieldData* Get(int id);
	static ContactPersonFieldData* Get(QString name);
	static QList<ContactPersonFieldData*> GetAll();
	static QList<ContactPersonFieldData*> Search(QString keyword);
	static QList<ContactPersonFieldData*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ContactPersonFieldData*> contactpersonfielddatas);
	static int GetIndex(QString title);
	static ContactPersonFieldData* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactPersonFieldData(int ContactPersonFieldDataID,int ContactPersonID,int ContactPersonFieldID,QString Value,QString CreatedOn,QString EditedOn);	static ContactPersonFieldData* p_instance;
	bool setContactPersonID(int ContactPersonFieldDataID, const QString &ContactPersonID);
	bool setContactPersonFieldID(int ContactPersonFieldDataID, const QString &ContactPersonFieldID);
	bool setValue(int ContactPersonFieldDataID, const QString &Value);
	bool setCreatedOn(int ContactPersonFieldDataID, const QString &CreatedOn);
	bool setEditedOn(int ContactPersonFieldDataID, const QString &EditedOn);

};
#endif
