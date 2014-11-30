/**************************************************************************
**   File: contactpersonemail.h
**   Created on: Sun Nov 30 23:37:06 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTPERSONEMAIL_H
#define CONTACTPERSONEMAIL_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ContactPersonEmail  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ContactPersonEmail();
	ContactPersonEmail(QString Description,QString Email,int ContactPersonID,QString CreatedOn,QString EditedOn);	int ContactPersonEmailID;
	QString Description;
	QString Email;
	int ContactPersonID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	ContactPersonEmail* get();
	ContactPersonEmail* get(const QModelIndex &index);
	static ContactPersonEmail* Get(int id);
	static ContactPersonEmail* Get(QString name);
	static QList<ContactPersonEmail*> GetAll();
	static QList<ContactPersonEmail*> Search(QString keyword);
	static QList<ContactPersonEmail*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static ContactPersonEmail* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactPersonEmail(int ContactPersonEmailID,QString Description,QString Email,int ContactPersonID,QString CreatedOn,QString EditedOn);	static ContactPersonEmail* p_instance;
	bool setDescription(int ContactPersonEmailID, const QString &Description);
	bool setEmail(int ContactPersonEmailID, const QString &Email);
	bool setContactPersonID(int ContactPersonEmailID, const QString &ContactPersonID);
	bool setCreatedOn(int ContactPersonEmailID, const QString &CreatedOn);
	bool setEditedOn(int ContactPersonEmailID, const QString &EditedOn);

};
#endif
