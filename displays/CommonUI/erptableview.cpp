/*************************************
**   Created on:  12/4/2014
**   Author: michaelbishara
**   Copyright: Bishara©.
**************************************/

#include "erptableview.h"

ERPTableView::ERPTableView(QWidget *parent) :
	QWidget(parent)
{

	layout = new QVBoxLayout(this);

	tabel = new QTableView();
	tabel->hideColumn(0); // don't show the ID
	tabel->sortByColumn(0,Qt::DescendingOrder);
	tabel->setSortingEnabled(true);
//	tabel->resizeColumnsToContents();
//	tabel->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	tabel->setSelectionBehavior(QAbstractItemView::SelectRows);
	tabel->setSelectionMode(QAbstractItemView::SingleSelection);



	lblLayout = new QHBoxLayout();

	print = new QLabel("print",this);
	print->setObjectName("print");
	lblLayout->addWidget(print);
	layout->addItem(lblLayout);
	layout->addWidget(tabel);


}
void ERPTableView::mousePressEvent(QMouseEvent *event){

	QLabel * child = static_cast<QLabel*>(childAt(event->pos()));
	if(!child)
		return;
	else {
		if(child->objectName() == "print"){
			printTabel();
		}
		else if(child->objectName() == "remove"){
		}
	}
	QWidget::mousePressEvent(event);

}

void ERPTableView::printTabel(){
	tabel->hideColumn(0); // don't show the ID

	if(tabel->model()->headerData(tabel->model()->columnCount()-2, Qt::Horizontal).toString().contains("Created"))
		tabel->hideColumn(tabel->model()->columnCount()-2); // don't show Created On

	if(tabel->model()->headerData(tabel->model()->columnCount()-1, Qt::Horizontal).toString().contains("Edited"))
		tabel->hideColumn(tabel->model()->columnCount()-1); // don't show Edited On

	QString strStream;
	QTextStream out(&strStream);

	const int rowCount = tabel->model()->rowCount();
	const int columnCount = tabel->model()->columnCount();

	out <<  "<html>\n"
			"<head>\n"
			"<meta Content=\"Text/html; charset=Windows-1251\">\n"
		 <<  QString("<title>%1</title>\n").arg("strTitle")
		  <<  "</head>\n"
			  "<body bgcolor=#ffffff link=#5000A0>\n"
			  "<table border=1 cellspacing=0 cellpadding=2>\n";

	// headers
	out << "<thead><tr bgcolor=#f0f0f0>";
	for (int column = 0; column < columnCount; column++)
		if (!tabel->isColumnHidden(column))
			out << QString("<th>%1</th>").arg(tabel->model()->headerData(column, Qt::Horizontal).toString());
	out << "</tr></thead>\n";

	// data table
	for (int row = 0; row < rowCount; row++) {
		out << "<tr>";
		for (int column = 0; column < columnCount; column++) {
			if (!tabel->isColumnHidden(column)) {
				QString data = tabel->model()->data(tabel->model()->index(row, column)).toString().simplified();
				out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
			}
		}
		out << "</tr>\n";
	}
	out <<  "</table>\n"
			"</body>\n"
			"</html>\n";

	QTextDocument *document = new QTextDocument();
	document->setHtml(strStream);

	QPrinter printer;
	printer.setPageSize(printer.A4);
	printer.setPageMargins(10, 10, 0, 0, printer.Millimeter);
	//document->setPageSize(QSizeF(printer.pageRect().size()));

	QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
	if (dialog->exec() == QDialog::Accepted) {
		document->print(&printer);
	}
	if(tabel->model()->headerData(tabel->model()->columnCount()-2, Qt::Horizontal).toString().contains("Created"))
		tabel->showColumn(tabel->model()->columnCount()-2); // don't show Created On

	if(tabel->model()->headerData(tabel->model()->columnCount()-1, Qt::Horizontal).toString().contains("Edited"))
		tabel->showColumn(tabel->model()->columnCount()-1); // don't show Edited On


	delete document;

}
