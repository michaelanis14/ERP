/**************************************************************************
**   File: contactstatus.h
**   Created on: Sat Dec 13 13:51:04 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTSTATUS_H
#define CONTACTSTATUS_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ContactStatus  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ContactStatus();
	ContactStatus(QString Description,QString CreatedOn,QString EditedOn);	int ContactStatusID;
	QString Description;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ContactStatus* get();
	ContactStatus* get(const QModelIndex &index);
	static ContactStatus* Get(int id);
	static ContactStatus* Get(QString name);
	static QList<ContactStatus*> GetAll();
	static QList<ContactStatus*> Search(QString keyword);
	static QList<ContactStatus*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ContactStatus*> contactstatuss);
	static int GetIndex(QString title);
	static ContactStatus* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactStatus(int ContactStatusID,QString Description,QString CreatedOn,QString EditedOn);	static ContactStatus* p_instance;
	bool setDescription(int ContactStatusID, const QString &Description);
	bool setCreatedOn(int ContactStatusID, const QString &CreatedOn);
	bool setEditedOn(int ContactStatusID, const QString &EditedOn);

};
#endif
