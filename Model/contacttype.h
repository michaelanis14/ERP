/**************************************************************************
**   File: contacttype.h
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTTYPE_H
#define CONTACTTYPE_H

#include <QtGui>

class ContactType
{
public:
	ContactType();
	ContactType(QString Description);
	static bool init();
	bool save();
	bool remove();
	ContactType* get();
	static ContactType* get(int id);
	static ContactType* get(QString name);
	static QList<ContactType*> getAll();
	static QList<ContactType*> search(QString keyword);
	static QList<ContactType*> select(QString select);
private:
	ContactType(int ContactTypeID,QString Description);
	int ContactTypeID;
	QString Description;
};
#endif
