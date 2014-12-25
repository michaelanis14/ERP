/**************************************************************************
**   File: loginui.cpp
**   Created on: Mon Dec 15 12:06:35 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#include "loginui.h"

#include "../MainWindow.h"

LoginUI::LoginUI(QWidget *parent) :ERPDisplay(parent)
{

	login = new Login();
	flowLayout = new FlowLayout(this);
	flowLayout->setContentsMargins(0,0,0,0);

	QPushButton* save = new QPushButton("Login");
	QObject::connect(save, SIGNAL(clicked()), this, SLOT(save()));
	save->setObjectName("save");

	ErpModel::GetInstance()->LoggedUser->UserID = 0;

	block0Layout = new ERPFormBlock;
	if(this->flowLayout && this->flowLayout->parent()->objectName() == "formPanel")
		block0Layout->setMinimumWidth(330);
	username = new QLineEdit();
	block0Layout->addRow(QObject::tr("User Name"),username);
	password = new QLineEdit();
	password->setEchoMode(QLineEdit::Password);
	password->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);

	block0Layout->addRow(QObject::tr("Password"),password);
	block0Layout->addRow("",save);

	flowLayout->addWidget(block0Layout);


}
ERPDisplay* LoginUI::p_instance = 0;
void LoginUI::ShowUI() {
	if (p_instance != 0)
		p_instance->deleteLater();
	p_instance = new LoginUI(mainwindow::GetMainDisplay());
	mainwindow::ShowDisplay(p_instance);
}
LoginUI*LoginUI::GetUI(){
	if (p_instance == 0) {
		p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	}
	return (LoginUI*) p_instance;
}


bool LoginUI::save(){
	bool errors = false;
	QString errorString =  "";
	if(username->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("User Name Can't be Empty! \n");
		username->setObjectName("error");
		username->style()->unpolish(username);
		username->style()->polish(username);
		username->update();
	}
	else {
		username->setObjectName("username");
		username->style()->unpolish(username);
		username->style()->polish(username);
		username->update();
		login->UserName = username->text().trimmed();
	}
	if(password->text().trimmed().isEmpty()){
		errors = true;
		errorString += QObject::tr("Password Can't be Empty! \n");
		password->setObjectName("error");
		password->style()->unpolish(password);
		password->style()->polish(password);
		password->update();
	}
	else {
		password->setObjectName("password");
		password->style()->unpolish(password);
		password->style()->polish(password);
		password->update();
		login->Password = password->text().trimmed();
	}
	if(!errors) {
		QList<User*> users =User::QuerySelect(" username ='"+login->UserName+"' AND password ='"+login->Password+"'");
		if(users.length() > 1){
			errors = true;
			errorString += QObject::tr("Duplicate Users Contact System Admin");
			ErpModel::GetInstance()->LoggedUser = users.at(0);
			ErpModel::GetInstance()->UserAccessList = Access::QuerySelect(" UserID ="+QString::number( ErpModel::GetInstance()->LoggedUser->UserID ));

		}else if(users.length() == 1 && users.at(0)->UserID != 0){
				ErpModel::GetInstance()->LoggedUser = users.at(0);
				ErpModel::GetInstance()->UserAccessList = Access::QuerySelect(" UserID ="+QString::number( ErpModel::GetInstance()->LoggedUser->UserID ));
				mainwindow::GetMainDisplay()->navigation->setHidden(false);
				mainwindow::GetMainDisplay()->btnContacts->click();
		}
		else {

			errors = true;
			errorString += QObject::tr("Username or Password is incorrect");

		}
		if(errors){
			QMessageBox::warning(this, QObject::tr("Login"),errorString.trimmed());
			return false;
		}
	}
	if(errors)
		QMessageBox::warning(this, QObject::tr("Login"),errorString.trimmed());

	return false;

}
void LoginUI::resizeEvent(QResizeEvent * event){

	if((event->size().height() - this->controllers->height()) > 50 && event->size().width() > 50){
		mainwindow::GetMainDisplay()->navigation->setHidden(true);
		this->controllers->setGeometry(0,this->height()-200,this->width(),40);
	}
}
void LoginUI::showEvent(QShowEvent * event){
	if(this->parent() != 0){
		mainwindow::GetMainDisplay()->navigation->setHidden(true);
		this->controllers->setGeometry(0,this->height()-200,this->width(),40);
		mainwindow::GetMainDisplay()->innerNavigation->removeAll();
	}
	event->accept();
}

void LoginUI::keyPressEvent(QKeyEvent *event)
{
	if(event->key() == Qt::Key_Enter || (event->key() == Qt::Key_Return))
	{
	save();
	}

}
