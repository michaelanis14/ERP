/**************************************************************************
**   File: productimagecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PRODUCTIMAGEUI_H
#define PRODUCTIMAGEUI_H
#include "../../erpdisplay.h"
#include "productimageui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/productimage.h"
#include "../../Model/erpmodel.h"
#include "../../Model/productimage.h"
#include "../../Model/product.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ProductImageCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProductImageCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ProductImageCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*name;
 QLabel* imageLabel;
 QLineEdit* fileName;
 QPushButton* Add;
QByteArray bytes;
	QVariant* imagedata;
	ERPComboBox*product;
	void fill(ProductImage* productimage);
ProductImage* productimage;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectProductImage();
	void cancel();
	void clear();
	void removeRow();
public slots:
	bool save();
	bool updateModel();
	void onSelectionChanged();
void on_loadImageButton_clicked(); 
protected:
void showEvent(QShowEvent * event);
};
#endif
