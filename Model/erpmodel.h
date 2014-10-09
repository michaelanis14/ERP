/*************************************
**   Created on:  9/11/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef ERPMODEL_H
#define ERPMODEL_H

#include <QSqlQuery>

class ErpModel
{
public:
	ErpModel();
	QSqlDatabase db;
	static ErpModel* GetInstance();
	QSqlQuery qeryExec(QString q);
	bool createTable(QString table,QString query);
	bool init();
private:
	static ErpModel* p_instance;
};

#endif // ERPMODEL_H
