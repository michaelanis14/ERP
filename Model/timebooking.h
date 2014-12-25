/**************************************************************************
**   File: timebooking.h
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/
#ifndef TIMEBOOKING_H
#define TIMEBOOKING_H

#include <QSqlRelationalTableModel>
#include <QSqlError>
#include <QtGui>

class TimeBooking  : public QSqlRelationalTableModel
{
	Q_OBJECT
public:
	TimeBooking();
	TimeBooking(QString Title,QDate StartDate,QDate EndDate,QString StartTime,QString EndTime,QString BreakTime,bool OnlyTimeBooking,int ProjectID,int ServiceID,int UserID,QString Note,QString CreatedOn,QString EditedOn);	int TimeBookingID;
	QString Title;
	QDate StartDate;
	QDate EndDate;
	QString StartTime;
	QString EndTime;
	QString BreakTime;
	bool OnlyTimeBooking;
	int ProjectID;
	int ServiceID;
	int UserID;
	QString Note;
	QString CreatedOn;
	QString EditedOn;
	static bool Init();
	bool save();
	bool save(QSqlRecord &record);
	bool remove();
	TimeBooking* get();
	TimeBooking* get(const QModelIndex &index);
	static TimeBooking* Get(int id);
	static TimeBooking* Get(QString name);
	static QList<TimeBooking*> GetAll();
	static QList<TimeBooking*> Search(QString keyword);
	static QList<TimeBooking*> QuerySelect(QString select);
	static QList<QString> GetStringList();
	static QList<QPair< int,QString > > GetPairList();
	static QList<QPair< int,QString > > GetPairList(QList<TimeBooking*> timebookings);
	static int GetIndex(QString title);
	static TimeBooking* GetInstance();
	Qt::ItemFlags flags(const QModelIndex &index) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	void refresh();
	bool remove(const QModelIndex &index);

private:
	TimeBooking(int TimeBookingID,QString Title,QDate StartDate,QDate EndDate,QString StartTime,QString EndTime,QString BreakTime,bool OnlyTimeBooking,int ProjectID,int ServiceID,int UserID,QString Note,QString CreatedOn,QString EditedOn);	static TimeBooking* p_instance;
	bool setTitle(int TimeBookingID, const QString &Title);
	bool setStartDate(int TimeBookingID, const QString &StartDate);
	bool setEndDate(int TimeBookingID, const QString &EndDate);
	bool setStartTime(int TimeBookingID, const QString &StartTime);
	bool setEndTime(int TimeBookingID, const QString &EndTime);
	bool setBreakTime(int TimeBookingID, const QString &BreakTime);
	bool setOnlyTimeBooking(int TimeBookingID, const QString &OnlyTimeBooking);
	bool setProjectID(int TimeBookingID, const QString &ProjectID);
	bool setServiceID(int TimeBookingID, const QString &ServiceID);
	bool setUserID(int TimeBookingID, const QString &UserID);
	bool setNote(int TimeBookingID, const QString &Note);
	bool setCreatedOn(int TimeBookingID, const QString &CreatedOn);
	bool setEditedOn(int TimeBookingID, const QString &EditedOn);

};
#endif
