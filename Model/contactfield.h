/**************************************************************************
**   File: contactfield.h
**   Created on: Sun Nov 30 23:37:06 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTFIELD_H
#define CONTACTFIELD_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ContactField  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ContactField();
	ContactField(int FieldTypeID,QString Description,bool Defaults,QString CreatedOn,QString EditedOn);	int ContactFieldID;
	int FieldTypeID;
	QString Description;
	bool Defaults;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	ContactField* get();
	ContactField* get(const QModelIndex &index);
	static ContactField* Get(int id);
	static ContactField* Get(QString name);
	static QList<ContactField*> GetAll();
	static QList<ContactField*> Search(QString keyword);
	static QList<ContactField*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static ContactField* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactField(int ContactFieldID,int FieldTypeID,QString Description,bool Defaults,QString CreatedOn,QString EditedOn);	static ContactField* p_instance;
	bool setFieldTypeID(int ContactFieldID, const QString &FieldTypeID);
	bool setDescription(int ContactFieldID, const QString &Description);
	bool setDefaults(int ContactFieldID, const QString &Defaults);
	bool setCreatedOn(int ContactFieldID, const QString &CreatedOn);
	bool setEditedOn(int ContactFieldID, const QString &EditedOn);

};
#endif
