/**************************************************************************
**   File: company.h
**   Created on: Thu Dec 18 12:57:58 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef COMPANY_H
#define COMPANY_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Company  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Company();
	Company(QString Name,QString Header,QString Footer,QString CreatedOn,QString EditedOn);	int CompanyID;
	QString Name;
	QString Header;
	QString Footer;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	Company* get();
	Company* get(const QModelIndex &index);
	static Company* Get(int id);
	static Company* Get(QString name);
	static QList<Company*> GetAll();
	static QList<Company*> Search(QString keyword);
	static QList<Company*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<Company*> companys);
	static int GetIndex(QString title);
	static Company* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Company(int CompanyID,QString Name,QString Header,QString Footer,QString CreatedOn,QString EditedOn);	static Company* p_instance;
	bool setName(int CompanyID, const QString &Name);
	bool setHeader(int CompanyID, const QString &Header);
	bool setFooter(int CompanyID, const QString &Footer);
	bool setCreatedOn(int CompanyID, const QString &CreatedOn);
	bool setEditedOn(int CompanyID, const QString &EditedOn);

};
#endif
