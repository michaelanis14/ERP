/**************************************************************************
**   File: contactclass.h
**   Created on: Sat Nov 15 20:33:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTCLASS_H
#define CONTACTCLASS_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ContactClass  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ContactClass();
	ContactClass(QString Description,QString CreatedOn,QString EditedOn);	int ContactClassID;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	QList<ContactClass*> contactclasss;
	static bool Init();
	bool save();
	bool remove();
	ContactClass* get();
	ContactClass* get(const QModelIndex &index);
	static ContactClass* Get(int id);
	static ContactClass* Get(QString name);
	static QList<ContactClass*> GetAll();
	static QList<ContactClass*> Search(QString keyword);
	static QList<ContactClass*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static ContactClass* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactClass(int ContactClassID,QString Description,QString CreatedOn,QString EditedOn);	static ContactClass* p_instance;
	bool setDescription(int ContactClassID, const QString &description);
	bool setCreatedOn(int ContactClassID, const QString &createdon);
	bool setEditedOn(int ContactClassID, const QString &editedon);

};
#endif
