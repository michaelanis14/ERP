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
}
void ERPComboBox::addItems(QHash<int,QString> items){
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

	QWidget::focusOutEvent(e);




	//qDebug() << ;
	//QLineEdit::focusOutEvent(e);
	//emit(focussed(false));
}


int ERPComboBox::getKey(){
	int j = 0;
	QHashIterator<int, QString> i(items);
	while (i.hasNext()) {
		 i.next();
	if(j == currentIndex())
			return i.key();
		j++;
	}
	return 0;
}



