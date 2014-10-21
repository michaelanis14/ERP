/**************************************************************************
**   File: contactstatus.h
**   Created on: Sat Oct 18 13:10:05 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTSTATUS_H
#define CONTACTSTATUS_H

#include <QtGui>

class ContactStatus
{
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
	static QList<ContactStatus*> select(QString select);
	static QList<QString> GetStringList();
	static int GetIndex(QString title);
	static ContactStatus* GetInstance();

private:
	ContactStatus(int ContactStatusID,QString Description);
	static ContactStatus* p_instance;

};
#endif
