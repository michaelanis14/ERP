/**************************************************************************
**   File: user.h
**   Created on: Sat Oct 18 13:10:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef USER_H
#define USER_H

#include <QtGui>

class User
{
public:
	User();
	User(QString Name,QString Username,QString Password,QString LastLogin,int EmployeeID,bool active,QString lastIP);	int UserID;
	QString Name;
	QString Username;
	QString Password;
	QString LastLogin;
	int EmployeeID;
	bool active;
	QString lastIP;
	QList<User*> users;
	static bool init();
	bool save();
	bool remove();
	User* get();
	static User* get(int id);
	static User* get(QString name);
	static QList<User*> getAll();
	static QList<User*> search(QString keyword);
	static QList<User*> select(QString select);
	static QList<QString> GetStringList();
	static int GetIndex(QString title);
	static User* GetInstance();

private:
	User(int UserID,QString Name,QString Username,QString Password,QString LastLogin,int EmployeeID,bool active,QString lastIP);
	static User* p_instance;

};
#endif
