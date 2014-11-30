/*************************************
**   Created on:  10/4/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "erpcombobox.h"
#include "QDebug"
#include "QCompleter"
#include <QHashIterator>

ERPComboBox::ERPComboBox(QWidget *parent) :
	QComboBox(parent)
{
	this->setEditable(true);
	this->setInsertPolicy(QComboBox::NoInsert);
	this->setAutoCompletion(true);
	this->items = QHash<int,QString>();
	this->addedItems = false;
}
void ERPComboBox::addItems(QHash<int,QString> items){

	this->addedItems = true;
	this->items = items;
	QList<QString> list;
	QHashIterator<int, QString> i(items);
	while (i.hasNext()) {
		i.next();
		list.append(i.value());
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
	int j = 0;
if(this->addedItems){
	QHashIterator<int, QString> i(items);
	while (i.hasNext()) {
		 i.next();
	if(j == currentIndex())
			return i.key();
		j++;
	}
}

	return 0;
}



