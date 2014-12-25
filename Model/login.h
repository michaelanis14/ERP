/**************************************************************************
**   File: login.h
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef LOGIN_H
#define LOGIN_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Login  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Login();
	Login(QString UserName,QString Password,QString CreatedOn,QString EditedOn);	int LoginID;
	QString UserName;
	QString Password;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	Login* get();
	Login* get(const QModelIndex &index);
	static Login* Get(int id);
	static Login* Get(QString name);
	static QList<Login*> GetAll();
	static QList<Login*> Search(QString keyword);
	static QList<Login*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<Login*> logins);
	static int GetIndex(QString title);
	static Login* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Login(int LoginID,QString UserName,QString Password,QString CreatedOn,QString EditedOn);	static Login* p_instance;
	bool setUserName(int LoginID, const QString &UserName);
	bool setPassword(int LoginID, const QString &Password);
	bool setCreatedOn(int LoginID, const QString &CreatedOn);
	bool setEditedOn(int LoginID, const QString &EditedOn);

};
#endif
