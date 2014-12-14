/**************************************************************************
**   File: timebookingui.cpp
**   Created on: Sun Dec 14 22:39:13 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "timebookingui.h"
#include "../MainWindow.h"

TimeBookingUI::TimeBookingUI(QWidget *parent) :ERPDisplay(parent)
{

timebooking = new TimeBooking();
flowLayout = new FlowLayout(this);
flowLayout->setContentsMargins(0,0,0,0);

QPushButton* save = new QPushButton("Save");
 QObject::connect(save, SIGNAL(clicked()), this, SLOT(save()));
 save->setObjectName("save");
 QPushButton* cancel = new QPushButton("Cancel");
 cancel->setObjectName("cancel");
 QObject::connect(cancel, SIGNAL(clicked()), this, SLOT(cancel()));
 QPushButton* clear = new QPushButton("Clear");
 QObject::connect(clear, SIGNAL(clicked()), this, SLOT(clear()));
 clear->setObjectName("clear");
 this->controllers->addControllerButton(save); 
 this->controllers->addControllerButton(clear);  
 this->controllers->addControllerButton(cancel);
block0Layout = new ERPFormBlock;
if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel") 
 block0Layout->setMinimumWidth(330);
startdate = new QDateEdit(QDate::currentDate());
startdate->setCalendarPopup(true);
startdate->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow(QObject::tr("Start Date"),startdate);
enddate = new QDateEdit(QDate::currentDate());
enddate->setCalendarPopup(true);
enddate->setDisplayFormat("ddd dd/MM/yyyy");
block0Layout->addRow(QObject::tr("End Date"),enddate);
starttime = new QLineEdit();
block0Layout->addRow(QObject::tr("Start Time"),starttime);
endtime = new QLineEdit();
block0Layout->addRow(QObject::tr("End Time"),endtime);
breaktime = new QLineEdit();
block0Layout->addRow(QObject::tr("Break Time"),breaktime);
onlytimebooking = new QCheckBox();
block0Layout->addRow(QObject::tr("Only Time Booking"),onlytimebooking);
project = new ERPComboBox();
project->addItems(Project::GetPairList());
block0Layout->addRow(QObject::tr("Project"),project);
service = new ERPComboBox();
service->addItems(Service::GetPairList());
block0Layout->addRow(QObject::tr("Service"),service);
user = new ERPComboBox();
user->addItems(User::GetPairList());
block0Layout->addRow(QObject::tr("User"),user);
note = new QLineEdit();
block0Layout->addRow(QObject::tr("Note"),note);
flowLayout->addWidget(block0Layout);

}
ERPDisplay* TimeBookingUI::p_instance = 0;
void TimeBookingUI::ShowUI() { 
	if (p_instance != 0) 
	p_instance->deleteLater(); 
	p_instance = new TimeBookingUI(mainwindow::GetMainDisplay()); 
  mainwindow::ShowDisplay(p_instance); 
}
TimeBookingUI*TimeBookingUI::GetUI(){ 
 	if (p_instance == 0) { 
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay()); 
	} 
	return (TimeBookingUI*) p_instance; 
}
void TimeBookingUI::fill(TimeBooking* timebooking){ 
clear();
this->timebooking = timebooking;
startdate->setDate(QDate::fromString(timebooking->StartDate));
enddate->setDate(QDate::fromString(timebooking->EndDate));
starttime->setText(timebooking->StartTime);
endtime->setText(timebooking->EndTime);
breaktime->setText(timebooking->BreakTime);
onlytimebooking->setChecked(timebooking->OnlyTimeBooking);
project->setIndexByKey(timebooking->ProjectID);
service->setIndexByKey(timebooking->ServiceID);
user->setIndexByKey(timebooking->UserID);
note->setText(timebooking->Note);
} 
void TimeBookingUI::clear(){ 
delete this->timebooking;
startdate->setDate(QDate::currentDate());
enddate->setDate(QDate::currentDate());
starttime->setText("");
endtime->setText("");
breaktime->setText("");
onlytimebooking->setChecked(false);
note->setText("");
this->timebooking = new TimeBooking();
} 
void TimeBookingUI::selectTimeBooking(){ 
if(TimeBooking::GetStringList().contains(this->timebooking->StartDate))
{
TimeBooking* con = TimeBooking::Get(this->timebooking->StartDate);
if(this->timebooking->TimeBookingID != con->TimeBookingID){
fill(con);
}
}
else if(timebooking->TimeBookingID != 0)
clear();
}
bool TimeBookingUI::save(){ 
bool errors = false;
QString errorString =  "";
if(startdate->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Start Date Can't be Empty! \n");
startdate->setObjectName("error");
startdate->style()->unpolish(startdate);
startdate->style()->polish(startdate);
startdate->update();
}
else { 
startdate->setObjectName("startdate");
startdate->style()->unpolish(startdate);
startdate->style()->polish(startdate);
startdate->update();
timebooking->StartDate = startdate->text().trimmed();
}
if(enddate->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("End Date Can't be Empty! \n");
enddate->setObjectName("error");
enddate->style()->unpolish(enddate);
enddate->style()->polish(enddate);
enddate->update();
}
else { 
enddate->setObjectName("enddate");
enddate->style()->unpolish(enddate);
enddate->style()->polish(enddate);
enddate->update();
timebooking->EndDate = enddate->text().trimmed();
}
if(starttime->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Start Time Can't be Empty! \n");
starttime->setObjectName("error");
starttime->style()->unpolish(starttime);
starttime->style()->polish(starttime);
starttime->update();
}
else { 
starttime->setObjectName("starttime");
starttime->style()->unpolish(starttime);
starttime->style()->polish(starttime);
starttime->update();
timebooking->StartTime = starttime->text().trimmed();
}
if(endtime->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("End Time Can't be Empty! \n");
endtime->setObjectName("error");
endtime->style()->unpolish(endtime);
endtime->style()->polish(endtime);
endtime->update();
}
else { 
endtime->setObjectName("endtime");
endtime->style()->unpolish(endtime);
endtime->style()->polish(endtime);
endtime->update();
timebooking->EndTime = endtime->text().trimmed();
}
if(breaktime->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Break Time Can't be Empty! \n");
breaktime->setObjectName("error");
breaktime->style()->unpolish(breaktime);
breaktime->style()->polish(breaktime);
breaktime->update();
}
else { 
breaktime->setObjectName("breaktime");
breaktime->style()->unpolish(breaktime);
breaktime->style()->polish(breaktime);
breaktime->update();
timebooking->BreakTime = breaktime->text().trimmed();
}
timebooking->OnlyTimeBooking = onlytimebooking->text().trimmed().toInt();
if(!project->isHidden()) 
timebooking->ProjectID = project->getKey();
if(!service->isHidden()) 
timebooking->ServiceID = service->getKey();
if(!user->isHidden()) 
timebooking->UserID = user->getKey();
if(note->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Note Can't be Empty! \n");
note->setObjectName("error");
note->style()->unpolish(note);
note->style()->polish(note);
note->update();
}
else { 
note->setObjectName("note");
note->style()->unpolish(note);
note->style()->polish(note);
note->update();
timebooking->Note = note->text().trimmed();
}
if(!errors) {
timebooking->save();
if(!errors){
TimeBookingIndexUI::ShowUI();
return true;}
else return false;
}
else{ QMessageBox::warning(this, QObject::tr("TimeBooking"),errorString.trimmed());
return false; 
 }
}
void TimeBookingUI::cancel(){ 
TimeBookingIndexUI::ShowUI();
}
bool TimeBookingUI::updateModel(){ 
bool errors = false;
QString errorString =  "";
if(startdate->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Start Date Can't be Empty! \n");
startdate->setObjectName("error");
startdate->style()->unpolish(startdate);
startdate->style()->polish(startdate);
startdate->update();
}
else { 
startdate->setObjectName("startdate");
startdate->style()->unpolish(startdate);
startdate->style()->polish(startdate);
startdate->update();
timebooking->StartDate = startdate->text().trimmed();
}
if(enddate->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("End Date Can't be Empty! \n");
enddate->setObjectName("error");
enddate->style()->unpolish(enddate);
enddate->style()->polish(enddate);
enddate->update();
}
else { 
enddate->setObjectName("enddate");
enddate->style()->unpolish(enddate);
enddate->style()->polish(enddate);
enddate->update();
timebooking->EndDate = enddate->text().trimmed();
}
if(starttime->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Start Time Can't be Empty! \n");
starttime->setObjectName("error");
starttime->style()->unpolish(starttime);
starttime->style()->polish(starttime);
starttime->update();
}
else { 
starttime->setObjectName("starttime");
starttime->style()->unpolish(starttime);
starttime->style()->polish(starttime);
starttime->update();
timebooking->StartTime = starttime->text().trimmed();
}
if(endtime->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("End Time Can't be Empty! \n");
endtime->setObjectName("error");
endtime->style()->unpolish(endtime);
endtime->style()->polish(endtime);
endtime->update();
}
else { 
endtime->setObjectName("endtime");
endtime->style()->unpolish(endtime);
endtime->style()->polish(endtime);
endtime->update();
timebooking->EndTime = endtime->text().trimmed();
}
if(breaktime->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Break Time Can't be Empty! \n");
breaktime->setObjectName("error");
breaktime->style()->unpolish(breaktime);
breaktime->style()->polish(breaktime);
breaktime->update();
}
else { 
breaktime->setObjectName("breaktime");
breaktime->style()->unpolish(breaktime);
breaktime->style()->polish(breaktime);
breaktime->update();
timebooking->BreakTime = breaktime->text().trimmed();
}
timebooking->OnlyTimeBooking = onlytimebooking->text().trimmed().toInt();
if(timebooking->ProjectID == 0) 
timebooking->ProjectID = project->getKey();
if(timebooking->ServiceID == 0) 
timebooking->ServiceID = service->getKey();
if(timebooking->UserID == 0) 
timebooking->UserID = user->getKey();
if(note->text().trimmed().isEmpty()){
errors = true;
errorString += QObject::tr("Note Can't be Empty! \n");
note->setObjectName("error");
note->style()->unpolish(note);
note->style()->polish(note);
note->update();
}
else { 
note->setObjectName("note");
note->style()->unpolish(note);
note->style()->polish(note);
note->update();
timebooking->Note = note->text().trimmed();
}
if(!errors){
	return true;
}
else{ if(!errorString.trimmed().isEmpty()) QMessageBox::warning(this, QObject::tr("TimeBooking"),errorString.trimmed());
return false; 
 }
}
