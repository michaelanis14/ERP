/**************************************************************************
**   File: user.h
**   Created on: Sun Nov 23 14:11:12 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef USER_H
#define USER_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class User  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	User();
	User(QString Name,QString Username,QString Password,QString LastLogin,int EmployeeID,bool active,QString lastIP,QString CreatedOn,QString EditedOn);	int UserID;
	QString Name;
	QString Username;
	QString Password;
	QString LastLogin;
	int EmployeeID;
	bool active;
	QString lastIP;
	QString CreatedOn;
	QString EditedOn;
	QList<User*> users;
	static bool Init();
	bool save();
	bool remove();
	User* get();
	User* get(const QModelIndex &index);
	static User* Get(int id);
	static User* Get(QString name);
	static QList<User*> GetAll();
	static QList<User*> Search(QString keyword);
	static QList<User*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static User* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	User(int UserID,QString Name,QString Username,QString Password,QString LastLogin,int EmployeeID,bool active,QString lastIP,QString CreatedOn,QString EditedOn);	static User* p_instance;
	bool setName(int UserID, const QString &name);
	bool setUsername(int UserID, const QString &username);
	bool setPassword(int UserID, const QString &password);
	bool setLastLogin(int UserID, const QString &lastlogin);
	bool setEmployeeID(int UserID, const QString &employeeid);
	bool setactive(int UserID, const QString &active);
	bool setlastIP(int UserID, const QString &lastip);
	bool setCreatedOn(int UserID, const QString &createdon);
	bool setEditedOn(int UserID, const QString &editedon);

};
#endif
