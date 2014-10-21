/**************************************************************************
**   File: contactclass.h
**   Created on: Sat Oct 18 13:10:05 EET 2014
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
	ContactClass(QString Description);	int ContactClassID;
	QString Description;
	QList<ContactClass*> contactclasss;
	static bool init();
	bool save();
	bool remove();
	ContactClass* get();
	static ContactClass* get(int id);
	static ContactClass* get(QString name);
	static QList<ContactClass*> getAll();
	static QList<ContactClass*> search(QString keyword);
	static QList<ContactClass*> select(QString select);
	static QList<QString> GetStringList();
	static int GetIndex(QString title);
	static ContactClass* GetInstance();

private:
	ContactClass(int ContactClassID,QString Description);
	static ContactClass* p_instance;

};
#endif
