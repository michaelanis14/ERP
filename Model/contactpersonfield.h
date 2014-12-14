/**************************************************************************
**   File: contactpersonfield.h
**   Created on: Sat Dec 13 21:50:44 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTPERSONFIELD_H
#define CONTACTPERSONFIELD_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ContactPersonField  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ContactPersonField();
	ContactPersonField(QString Description,int FieldTypeID,bool Defaults,QString CreatedOn,QString EditedOn);	int ContactPersonFieldID;
	QString Description;
	int FieldTypeID;
	bool Defaults;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ContactPersonField* get();
	ContactPersonField* get(const QModelIndex &index);
	static ContactPersonField* Get(int id);
	static ContactPersonField* Get(QString name);
	static QList<ContactPersonField*> GetAll();
	static QList<ContactPersonField*> Search(QString keyword);
	static QList<ContactPersonField*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ContactPersonField*> contactpersonfields);
	static int GetIndex(QString title);
	static ContactPersonField* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactPersonField(int ContactPersonFieldID,QString Description,int FieldTypeID,bool Defaults,QString CreatedOn,QString EditedOn);	static ContactPersonField* p_instance;
	bool setDescription(int ContactPersonFieldID, const QString &Description);
	bool setFieldTypeID(int ContactPersonFieldID, const QString &FieldTypeID);
	bool setDefaults(int ContactPersonFieldID, const QString &Defaults);
	bool setCreatedOn(int ContactPersonFieldID, const QString &CreatedOn);
	bool setEditedOn(int ContactPersonFieldID, const QString &EditedOn);

};
#endif
