/*************************************
**   Created on:  10/29/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "cmodel.h"

Cmodel::Cmodel()
{
}
bool Cmodel::setFirstName(int personId, const QString &firstName)
{
	QSqlQuery query;
	query.prepare("update Contact set firstname = ? where id = ?");
	query.addBindValue(firstName);
	query.addBindValue(personId);
	return query.exec();
}

bool Cmodel::setData(const QModelIndex &index, const QVariant &value, int /* role */)
{
	qDebug() << "Edit";
	if (index.column() < 1 || index.column() > 2)
		return false;

//	QModelIndex primaryKeyIndex = QSqlQueryModel::index(index.row(), 0);
//	int id = data(primaryKeyIndex).toInt();

	//clear();

	bool ok;
	if (index.column() == 1) {
		ok = setFirstName(1, value.toString());
	} else {
		//ok = setLastName(id, value.toString());
	}
	//refresh();
	return ok;
}
