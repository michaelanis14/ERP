/**************************************************************************
**   File: productimage.h
**   Created on: Sun Dec 07 15:14:08 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef PRODUCTIMAGE_H
#define PRODUCTIMAGE_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class ProductImage  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	ProductImage();
	ProductImage(QString Description,int ProductID,QString CreatedOn,QString EditedOn);	int ProductImageID;
	QString Description;
	int ProductID;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool remove();
	ProductImage* get();
	ProductImage* get(const QModelIndex &index);
	static ProductImage* Get(int id);
	static ProductImage* Get(QString name);
	static QList<ProductImage*> GetAll();
	static QList<ProductImage*> Search(QString keyword);
	static QList<ProductImage*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static ProductImage* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	ProductImage(int ProductImageID,QString Description,int ProductID,QString CreatedOn,QString EditedOn);	static ProductImage* p_instance;
	bool setDescription(int ProductImageID, const QString &Description);
	bool setProductID(int ProductImageID, const QString &ProductID);
	bool setCreatedOn(int ProductImageID, const QString &CreatedOn);
	bool setEditedOn(int ProductImageID, const QString &EditedOn);

};
#endif
