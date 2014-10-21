/*************************************
**   Created on:  10/8/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "erpformblock.h"

ERPFormBlock::ERPFormBlock(QWidget *parent) :
	QWidget(parent)
{
	this->setObjectName("ERPFormBlock");
	formLayout = new QFormLayout(this);
	formLayout->setObjectName("formPanelk");
	this->setContentsMargins(0,0,0,0);
	//	formLayout->setContentsMargins(5,2,5,2);
	//	formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
	//	formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
	formLayout->setLabelAlignment(Qt::AlignLeft);
	this->setAutoFillBackground(true);
	formLayout->setRowWrapPolicy(QFormLayout::WrapAllRows);
	//formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);

}

void ERPFormBlock::addRow(const QString &labelText, QWidget *field){

	formLayout->addRow(labelText,field);
}
