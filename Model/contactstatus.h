/**************************************************************************
**   File: contactstatus.h
**   Created on: Sat Nov 15 20:33:04 EET 2014
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
	QList<ContactStatus*> contactstatuss;
	static bool Init();
	bool save();
	bool remove();
	ContactStatus* get();
	ContactStatus* get(const QModelIndex &index);
	static ContactStatus* Get(int id);
	static ContactStatus* Get(QString name);
	static QList<ContactStatus*> GetAll();
	static QList<ContactStatus*> Search(QString keyword);
	static QList<ContactStatus*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static ContactStatus* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactStatus(int ContactStatusID,QString Description,QString CreatedOn,QString EditedOn);	static ContactStatus* p_instance;
	bool setDescription(int ContactStatusID, const QString &description);
	bool setCreatedOn(int ContactStatusID, const QString &createdon);
	bool setEditedOn(int ContactStatusID, const QString &editedon);

};
#endif
