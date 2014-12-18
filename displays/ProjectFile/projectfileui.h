/**************************************************************************
**   File: projectfileui.h
**   Created on: Wed Dec 17 16:42:29 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef PROJECTFILEUI_H
#define PROJECTFILEUI_H
#include "../../erpdisplay.h"
#include "projectfileindexui.h"
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
#include <QDateEdit>
class ProjectFileUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit ProjectFileUI(QWidget *parent = 0);
	static void ShowUI();
	static ProjectFileUI* GetUI();
	ERPFormBlock* block0Layout;
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
private slots:
	void selectProjectFile();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
void on_loadImageButton_clicked(); 
};
#endif
