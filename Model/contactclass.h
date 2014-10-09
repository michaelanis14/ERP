/**************************************************************************
**   File: contactclass.h
**   Created on: Fri Sep 26 22:51:30 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTCLASS_H
#define CONTACTCLASS_H

#include <QtGui>

class ContactClass
{
public:
	ContactClass();
	ContactClass(QString Description);
	static bool init();
	bool save();
	bool remove();
	ContactClass* get();
	static ContactClass* get(int id);
	static ContactClass* get(QString name);
	static QList<ContactClass*> getAll();
	static QList<ContactClass*> search(QString keyword);
	static QList<ContactClass*> select(QString select);
private:
	ContactClass(int ContactClassID,QString Description);
	int ContactClassID;
	QString Description;
};
#endif
