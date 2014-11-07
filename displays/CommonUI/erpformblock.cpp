/*************************************
**   Created on:  10/8/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "erpformblock.h"
#include <QPushButton>
#include <QLabel>

ERPFormBlock::ERPFormBlock(QWidget *parent) :
	QWidget(parent)
{


	baseWidget= new QWidget();
	baseWidget->setObjectName("baseWidget");
	boxLayout = new QVBoxLayout(this);
	formLayout = new QFormLayout(baseWidget);

	formLayout->setObjectName("formPanel");
	this->setContentsMargins(0,0,0,0);

	//	formLayout->setContentsMargins(5,2,5,2);
	//	formLayout->setRowWrapPolicy(QFormLayout::WrapLongRows);
	//	formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
	formLayout->setLabelAlignment(Qt::AlignLeft);
	//this->setAutoFillBackground(true);
	formLayout->setRowWrapPolicy(QFormLayout::WrapAllRows);
	//this->setMinimumWidth(190);
	//this->setMinimumHeight(190);
	//formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
	this->baseWidget->setHidden(true);

	boxLayout->addWidget(baseWidget);
	//boxLayout->addStretch(1);
	//this->setLayout(boxLayout);
}

void ERPFormBlock::addRow(const QString &labelText, QWidget *field){

	formLayout->addRow(labelText,field);
	this->baseWidget->setHidden(false);
	//this->repaint();
}

void ERPFormBlock::removeRow(QWidget* field){
	QWidget* label = formLayout->labelForField(field);
	  if (label)
		  label->deleteLater();
	  field->deleteLater();
}

void ERPFormBlock::addWidget(QWidget *widget){

	boxLayout->addWidget(widget);
	//boxLayout->addStretch(1);
}
