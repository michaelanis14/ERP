/**************************************************************************
**   File: projectfile.h
**   Created on: Thu Dec 18 10:59:52 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PROJECTFILE_H
#define PROJECTFILE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ProjectFile  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ProjectFile();
	ProjectFile(QString Name,QVariant imageData,int ProjectID,QString CreatedOn,QString EditedOn);	int ProjectFileID;
	QString Name;
	QVariant imageData;
	int ProjectID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	ProjectFile* get();
	ProjectFile* get(const QModelIndex &index);
	static ProjectFile* Get(int id);
	static ProjectFile* Get(QString name);
	static QList<ProjectFile*> GetAll();
	static QList<ProjectFile*> Search(QString keyword);
	static QList<ProjectFile*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<ProjectFile*> projectfiles);
	static int GetIndex(QString title);
	static ProjectFile* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ProjectFile(int ProjectFileID,QString Name,QVariant imageData,int ProjectID,QString CreatedOn,QString EditedOn);	static ProjectFile* p_instance;
	bool setName(int ProjectFileID, const QString &Name);
	bool setimageData(int ProjectFileID, const QString &imageData);
	bool setProjectID(int ProjectFileID, const QString &ProjectID);
	bool setCreatedOn(int ProjectFileID, const QString &CreatedOn);
	bool setEditedOn(int ProjectFileID, const QString &EditedOn);

};
#endif
