/*************************************
**   Created on:  12/4/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#ifndef ERPTABLEVIEW_H
#define ERPTABLEVIEW_H

#include <QtGui>
#include <QWidget>
#include <QFileDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <QTableView>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class ERPTableView : public QWidget
{
	Q_OBJECT
public:
	explicit ERPTableView(QWidget *parent = 0);
	QTableView* tabel;
private:
	QVBoxLayout* layout;
	QHBoxLayout* lblLayout;
	QLabel* print;

signals:
protected:
	void mousePressEvent(QMouseEvent *event);

public slots:
	void printTabel();

};

#endif // ERPTABLEVIEW_H
