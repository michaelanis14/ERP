/**************************************************************************
**   File: projectfilecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTFILEUI_H
#define PROJECTFILEUI_H
#include "../../erpdisplay.h"
#include "projectfileui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/projectfile.h"
#include "../../Model/erpmodel.h"
#include "../../Model/projectfile.h"
#include "../../Model/project.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class ProjectFileCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectFileCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectFileCreatUI* GetUI();
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
	ERPComboBox*project;
	void fill(ProjectFile* projectfile);
ProjectFile* projectfile;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectProjectFile();
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
