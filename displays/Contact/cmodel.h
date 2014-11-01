/*************************************
**   Created on:  10/29/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef CMODEL_H
#define CMODEL_H

#include <QSqlRelationalDelegate>
#include <QSqlRelationalTableModel>
#include <QtSql>
#include <QSqlQueryModel>
#include <QModelIndex>

class Cmodel
{
public:
	Cmodel();
	bool setData(const QModelIndex &index, const QVariant &value, int role) Q_DECL_OVERRIDE;
	bool setFirstName(int personId, const QString &firstName);

};

#endif // CMODEL_H
