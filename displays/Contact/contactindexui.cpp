/*************************************
**   Created on:  10/3/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/



#include "contactindexui.h"
#include "ui_contactindexui.h"
#include "../MainWindow.h"


#include <QLineEdit>



contactIndexUI::contactIndexUI(QWidget *parent) :
	ERPDisplay(parent),
	ui(new Ui::contactIndexUI)
{
	ui->setupUi(this);
	boxLayout = new QVBoxLayout();
	//QHBoxLayout* line1Layout = new QHBoxLayout();
	flowLayout = new FlowLayout(this);
	flowLayout->setContentsMargins(0,0,0,0);
	for(int i =0;i<3 ;i++){
		ERPFormBlock* line1Layout = new ERPFormBlock;

		combo = new ERPComboBox();
		combo->addItem("One");
		combo->addItem("tOne");
		combo->addItem("Otne");
		combo->addItem("Ottne");
		combo->addItem("xfkjgjhfgdhfdhffjfjffe");
		combo->setEditable(true);
		combo->setAutoCompletion(true);



		QObject::connect(combo, SIGNAL(editTextChanged(QString)), this, SLOT(editTextChanged(QString)));
		//QObject::connect(combo, SIGNAL(focusOutEvent()), this, SLOT(focusOutEvent ()));



		line1Layout->addRow("COMBO"+QString::number(i),combo);
		//line1Layout->addWidget(combo);
		//flowLayout->addWidget(label1);
		flowLayout->addWidget(line1Layout);
		//flowLayout->addWidget(combo);
		//flowLayout->addItem();
	}


	//this->setLayout(flowLayout);
	//boxLayout->addLayout(flowLayout);


}
ERPDisplay* contactIndexUI::p_instance = 0;
/**
* A function.
* Calls the Main Window show function
* passing for the function this displays static instance
*/
void contactIndexUI::ShowUI() {
	if (p_instance == 0) {
		p_instance = new contactIndexUI(mainwindow::GetMainDisplay());
	}
	mainwindow::ShowDisplay(p_instance);
}

contactIndexUI* contactIndexUI::GetUI(){
	   if (p_instance == 0) {
		   p_instance = new ERPDisplay(mainwindow::GetMainDisplay());
	   }
	   return (contactIndexUI*) p_instance;

}




void contactIndexUI::showEvent(QShowEvent * event) {
	event->accept();
}
contactIndexUI::~contactIndexUI()
{
	delete ui;
}
