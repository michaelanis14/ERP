/**************************************************************************
**   File: contactstatus.h
**   Created on: Tue Nov 11 17:36:07 EET 2014
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
	ContactStatus(QString Description);	int ContactStatusID;
	QString Description;
	QList<ContactStatus*> contactstatuss;
	static bool init();
	bool save();
	bool remove();
	ContactStatus* get();
	static ContactStatus* get(int id);
	static ContactStatus* get(QString name);
	static QList<ContactStatus*> getAll();
	static QList<ContactStatus*> search(QString keyword);
	static QList<ContactStatus*> querySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static ContactStatus* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactStatus(int ContactStatusID,QString Description);	static ContactStatus* p_instance;
	bool setDescription(int ContactStatusID, const QString &description);

};
#endif
