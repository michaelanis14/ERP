/**************************************************************************
**   File: languageui.h
**   Created on: Thu Dec 18 12:57:59 EET 2014
**   Author: Michael Bishara
**   Copyright: SphinxSolutions.
**************************************************************************/

#ifndef LANGUAGEUI_H
#define LANGUAGEUI_H
#include "../../erpdisplay.h"
#include "languageindexui.h"
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
#include <QDateEdit>
class LanguageUI : public ERPDisplay
{
	Q_OBJECT
public:
	explicit LanguageUI(QWidget *parent = 0);
	static void ShowUI();
	static LanguageUI* GetUI();
	ERPFormBlock* block0Layout;
	QLineEdit*title;
	QLineEdit*file;
	void fill(Language* language);
Language* language;
private:
	static ERPDisplay* p_instance;
private slots:
	void selectLanguage();
	void cancel();
	void clear();
public slots:
	bool save();
	bool updateModel();
};
#endif
