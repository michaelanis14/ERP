/**************************************************************************
**   File: contacttype.h
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTTYPE_H
#define CONTACTTYPE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ContactType  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ContactType();
	ContactType(QString Description,QString CreatedOn,QString EditedOn);	int ContactTypeID;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ContactType* get();
	ContactType* get(const QModelIndex &index);
	static ContactType* Get(int id);
	static ContactType* Get(QString name);
	static QList<ContactType*> GetAll();
	static QList<ContactType*> Search(QString keyword);
	static QList<ContactType*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ContactType*> contacttypes);
	static int GetIndex(QString title);
	static ContactType* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactType(int ContactTypeID,QString Description,QString CreatedOn,QString EditedOn);	static ContactType* p_instance;
	bool setDescription(int ContactTypeID, const QString &Description);
	bool setCreatedOn(int ContactTypeID, const QString &CreatedOn);
	bool setEditedOn(int ContactTypeID, const QString &EditedOn);

};
#endif
