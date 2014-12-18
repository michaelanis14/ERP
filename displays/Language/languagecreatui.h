/**************************************************************************
**   File: languagecreatui.h
**   Created on: Wed Dec 17 18:31:01 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef LANGUAGEUI_H
#define LANGUAGEUI_H
#include "../../erpdisplay.h"
#include "languageui.h"
#include "../CommonUI/erpformblock.h"
#include "../CommonUI/erpcombobox.h"
#include "../CommonUI/addremovebuttons.h"
#include "../CommonUI/RemovebtnWidgets.h"
#include "../../Model/language.h"
#include "../../Model/erpmodel.h"
#include "../../Model/language.h"


#include <QWidget>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QCompleter>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QDateEdit>
class LanguageCreatUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit LanguageCreatUI(QWidget *parent = 0);
	static void ShowUI();
	static LanguageCreatUI* GetUI();
	ERPFormBlock* block0Layout;
	ERPTableView *tabel; 
	QStandardItemModel *model; 
	QPushButton *remove; 
	ERPFormBlock *tabelLayout;
	QLineEdit*title;
	QLineEdit*file;
	void fill(Language* language);
Language* language;
private:
	static ERPDisplay* p_instance;
	void refreshTabel();
private slots:
	void selectLanguage();
	void cancel();
	void clear();
	void removeRow();
public slots:
	bool save();
	bool updateModel();
	void onSelectionChanged();
protected:
void showEvent(QShowEvent * event);
};
#endif
