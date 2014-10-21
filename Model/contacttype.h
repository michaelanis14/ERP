/**************************************************************************
**   File: contacttype.h
**   Created on: Sat Oct 18 13:10:05 EET 2014
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
	ContactType(QString Description);	int ContactTypeID;
	QString Description;
	QList<ContactType*> contacttypes;
	static bool init();
	bool save();
	bool remove();
	ContactType* get();
	static ContactType* get(int id);
	static ContactType* get(QString name);
	static QList<ContactType*> getAll();
	static QList<ContactType*> search(QString keyword);
	static QList<ContactType*> select(QString select);
	static QList<QString> GetStringList();
	static int GetIndex(QString title);
	static ContactType* GetInstance();

private:
	ContactType(int ContactTypeID,QString Description);
	static ContactType* p_instance;

};
#endif
