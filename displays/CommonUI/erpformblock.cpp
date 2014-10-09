/*************************************
**   Created on:  10/8/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "erpformblock.h"

ERPFormBlock::ERPFormBlock(QWidget *parent) :
	QWidget(parent)
{
	formLayout = new QFormLayout(this);
	this->setContentsMargins(0,0,0,0);
	formLayout->setContentsMargins(5,2,5,2);
	formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
	formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
}

void ERPFormBlock::addRow(const QString &labelText, QWidget *field){

	formLayout->addRow(labelText,field);
}
