/**************************************************************************
**   File: language.h
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Language  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Language();
	Language(QString Title,QString File,QString CreatedOn,QString EditedOn);	int LanguageID;
	QString Title;
	QString File;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	Language* get();
	Language* get(const QModelIndex &index);
	static Language* Get(int id);
	static Language* Get(QString name);
	static QList<Language*> GetAll();
	static QList<Language*> Search(QString keyword);
	static QList<Language*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<Language*> languages);
	static int GetIndex(QString title);
	static Language* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Language(int LanguageID,QString Title,QString File,QString CreatedOn,QString EditedOn);	static Language* p_instance;
	bool setTitle(int LanguageID, const QString &Title);
	bool setFile(int LanguageID, const QString &File);
	bool setCreatedOn(int LanguageID, const QString &CreatedOn);
	bool setEditedOn(int LanguageID, const QString &EditedOn);

};
#endif
