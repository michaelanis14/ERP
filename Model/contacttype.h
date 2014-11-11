/**************************************************************************
**   File: contacttype.h
**   Created on: Tue Nov 11 17:36:07 EET 2014
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
	ContactType(QString Description);	int ContactTypeID;
	QString Description;
	QList<ContactType*> contacttypes;
	static bool init();
	bool save();
	bool remove();
	ContactType* get();
	static ContactType* get(int id);
	static ContactType* get(QString name);
	static QList<ContactType*> getAll();
	static QList<ContactType*> search(QString keyword);
	static QList<ContactType*> querySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static ContactType* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactType(int ContactTypeID,QString Description);	static ContactType* p_instance;
	bool setDescription(int ContactTypeID, const QString &description);

};
#endif
