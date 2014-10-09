/**************************************************************************
**   File: contactstatus.h
**   Created on: Fri Sep 26 22:51:30 EET 2014
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
	ContactStatus(QString Description);
	static bool init();
	bool save();
	bool remove();
	ContactStatus* get();
	static ContactStatus* get(int id);
	static ContactStatus* get(QString name);
	static QList<ContactStatus*> getAll();
	static QList<ContactStatus*> search(QString keyword);
	static QList<ContactStatus*> select(QString select);
private:
	ContactStatus(int ContactStatusID,QString Description);
	int ContactStatusID;
	QString Description;
};
#endif
