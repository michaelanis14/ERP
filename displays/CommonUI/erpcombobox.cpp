/*************************************
**   Created on:  10/4/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "erpcombobox.h"
#include "QDebug"
#include "QCompleter"

ERPComboBox::ERPComboBox(QWidget *parent) :
	QComboBox(parent)
{

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
