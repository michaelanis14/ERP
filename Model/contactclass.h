/**************************************************************************
**   File: contactclass.h
**   Created on: Tue Nov 11 17:36:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef CONTACTCLASS_H
#define CONTACTCLASS_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ContactClass  : public QSqlRelationalTableModel
{
	Q_OBJECT
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
	static QList<ContactClass*> querySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static ContactClass* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ContactClass(int ContactClassID,QString Description);	static ContactClass* p_instance;
	bool setDescription(int ContactClassID, const QString &description);

};
#endif
