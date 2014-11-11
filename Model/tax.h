/**************************************************************************
**   File: tax.h
**   Created on: Tue Nov 11 17:36:07 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef TAX_H
#define TAX_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class Tax  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	Tax();
	Tax(double Ratio,QString Description);	int TaxID;
	double Ratio;
	QString Description;
	QList<Tax*> taxs;
	static bool init();
	bool save();
	bool remove();
	Tax* get();
	static Tax* get(int id);
	static Tax* get(QString name);
	static QList<Tax*> getAll();
	static QList<Tax*> search(QString keyword);
	static QList<Tax*> querySelect(QString select);
	static QList<QString> GetStringList();
	static QHash<int,QString> GetHashList();
	static int GetIndex(QString title);
	static Tax* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	Tax(int TaxID,double Ratio,QString Description);	static Tax* p_instance;
	bool setRatio(int TaxID, const QString &ratio);
	bool setDescription(int TaxID, const QString &description);

};
#endif
