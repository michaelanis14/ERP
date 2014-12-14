/**************************************************************************
**   File: contactemail.h
**   Created on: Sun Dec 14 22:39:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTEMAIL_H
#define CONTACTEMAIL_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ContactEmail  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ContactEmail();
	ContactEmail(QString Description,QString Email,int ContactID,QString CreatedOn,QString EditedOn);	int ContactEmailID;
	QString Description;
	QString Email;
	int ContactID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ContactEmail* get();
	ContactEmail* get(const QModelIndex &index);
	static ContactEmail* Get(int id);
	static ContactEmail* Get(QString name);
	static QList<ContactEmail*> GetAll();
	static QList<ContactEmail*> Search(QString keyword);
	static QList<ContactEmail*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ContactEmail*> contactemails);
	static int GetIndex(QString title);
	static ContactEmail* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactEmail(int ContactEmailID,QString Description,QString Email,int ContactID,QString CreatedOn,QString EditedOn);	static ContactEmail* p_instance;
	bool setDescription(int ContactEmailID, const QString &Description);
	bool setEmail(int ContactEmailID, const QString &Email);
	bool setContactID(int ContactEmailID, const QString &ContactID);
	bool setCreatedOn(int ContactEmailID, const QString &CreatedOn);
	bool setEditedOn(int ContactEmailID, const QString &EditedOn);

};
#endif
