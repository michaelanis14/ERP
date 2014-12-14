/*************************************
**   Created on:  10/4/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "erpcombobox.h"
#include "QDebug"
#include "QCompleter"
#include <QPair>

ERPComboBox::ERPComboBox(QWidget *parent) :
	QComboBox(parent)
{
	this->setEditable(true);
	this->setInsertPolicy(QComboBox::NoInsert);
	this->setAutoCompletion(true);
	this->items = QList<QPair<int, QString> >();
	this->addedItems = false;
}
void ERPComboBox::addItems(QList<QPair<int, QString> > pairList){


	this->items = pairList;
	QList<QString> list;
	for(int i = 0; i < pairList.length();i++) {
		this->addedItems = true;


		list.append(pairList.at(i).second);
	}
	QComboBox::addItems(list);
}

void ERPComboBox::focusOutEvent(QFocusEvent *e)
{
if(this->addedItems){

	QRegExp re("\\d*");
	if(this->currentText()==""){
		//qDebug() <<"EMP";
		this->clearEditText();
		this->setCurrentText(this->itemText(this->currentIndex()));
	}
	else if (re.exactMatch(this->currentText())){
		int index = this->currentText().toInt()-1;

		if(index > -1 && index < this->count() )
			this->setCurrentIndex(index);
		else
			this->setCurrentText(this->itemText(this->currentIndex()));
	}
	else if(this->completer()->currentCompletion() ==""){
		//qDebug()  <<"noComp";
		this->clearEditText();
		this->setCurrentText(this->itemText(this->currentIndex()));
	}
	else{
		this->clearEditText();
		this->setCurrentText(this->itemText(this->currentIndex()));

	}

	this->clearFocus();
	this->clearMask();
}
	QWidget::focusOutEvent(e);

}

int ERPComboBox::getKey(){
if(this->addedItems){
//	qDebug() << currentIndex()<< items.at(currentIndex()).first << items.at(currentIndex()).second;
return items.at(currentIndex()).first;
}
	return 0;
}

void ERPComboBox::setIndexByKey(int key){
	for(int i = 0; i < items.length();i++){
		if(items.at(i).first == key){
			this->setCurrentIndex(i);
			this->repaint();
			break;
		}
	}

}



