/*************************************
**   Created on:  9/11/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef ERPMODEL_H
#define ERPMODEL_H

#include <QSqlQuery>
#include <QPair>


class ErpModel
{
public:
	ErpModel();
	QSqlDatabase db;
	static ErpModel* GetInstance();
	QSqlQuery qeryExec(QString q);
	bool createTable(QString table,QString query,QList<QPair<QString,QString> >variables);
	bool init();
private:
	static ErpModel* p_instance;
};

#endif // ERPMODEL_H
