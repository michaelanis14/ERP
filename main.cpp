
#include <QtWidgets/QApplication>
#include <QtGui>
#include <QtWidgets/QWidget>

#include <QtCore/QCoreApplication>

#include "displays/mainwindow.h"
#include "displays/Contact/contactindexui.h"
#include "Model/erpmodel.h"

class BeepingApplication : public QApplication
{
public:
	//	QProcess* p0;
	//	Gestures* gestures;
	BeepingApplication(int & argc, char** argv) : QApplication(argc, argv) {
		//	p0 = new QProcess();
		//	gestures= new Gestures(272,480);
	}
	virtual ~BeepingApplication() {}

	/*   bool notify(QObject *obj, QEvent *ev)
	{

	//    if (mainwindow::GetMainDisplay()) {
	//		gestures->mouseMove(mainwindow::GetMainDisplay()->mapFromGlobal(QCursor::pos()));
   // }
		// MouseButtonPress, MouseButtonDblClick (Reihenfolge beim schnellen clicken:  mousbuttonpress, mousbuttonrelease, mousebuttonDblClick)
		if ((ev->type() == QEvent::MouseButtonPress) || (ev->type() == QEvent::MouseButtonDblClick)) {

			QLineEdit *lineEdit = qobject_cast< QLineEdit * >( obj );
			QPushButton* pushButton = qobject_cast<QPushButton*>( obj );
			QCheckBox* checkBox = qobject_cast< QCheckBox * >( obj );
			QComboBox* comboBox = qobject_cast< QComboBox * >( obj );
			QTableView* tableView = qobject_cast< QTableView*> ( obj->parent() );
			QScrollBar* scrollbar = qobject_cast< QScrollBar*> ( obj );
			QLabel* label = qobject_cast< QLabel*> ( obj );

			// Sound abspielen beim runterdrücken eines Display-Controls
			if ( (lineEdit && lineEdit->isEnabled())
				 || (pushButton && pushButton->isEnabled())
				 || (checkBox && checkBox->isEnabled())
				 || (comboBox && comboBox->isEnabled())
				 || (tableView)
				 || (scrollbar)
				 || (label)
				 ){


				if((mainwindow::GetMainDisplay())) {
					if(mainwindow::GetCurrentDisplay())
						if(	(mainwindow::GetCurrentDisplay()->objectName() == "UISetup") ||
								(mainwindow::GetCurrentDisplay()->objectName() == "ChooseSetting")||
								(mainwindow::GetCurrentDisplay()->objectName() == "UIUserSetup")||
								(mainwindow::GetCurrentDisplay()->objectName() == "UIUserEdit")||
								(mainwindow::GetCurrentDisplay()->objectName() == "UIUserSelect")||
								(mainwindow::GetCurrentDisplay()->objectName() == "UISystemSelect")||
								(mainwindow::GetCurrentDisplay()->objectName() == "UIProgramsEdit")||
								(mainwindow::GetCurrentDisplay()->objectName() == "UISystemEdit"))
						{
							//ProgramModel::GetInstance()->setupUIPressed = QDateTime::currentDateTime();
						}
				}


			  if(ProgramModel::GetInstance()->sound){

#ifndef Q_OS_WIN32
					//  qDebug() << QDateTime::currentDateTime().toMSecsSinceEpoch() << endl;
					if(p0->isOpen()) p0->close();
					p0->start("aplay pos_ack_short.wav" );
					//p0->waitForFinished(-1);
					// qDebug() << QDateTime::currentDateTime().toMSecsSinceEpoch() << endl;
#endif
#ifdef Q_OS_WIN32
					//  qDebug() << QDateTime::currentDateTime().toMSecsSinceEpoch() << endl;
					QSound::play("pos_ack_short.wav");
					this->processEvents(QEventLoop::ExcludeUserInputEvents,100);
					//  qDebug() << QDateTime::currentDateTime().toMSecsSinceEpoch() << endl;
#endif

				}
			} else {
				// wenn der user kein Control trifft, dann ein brummen spielen
				// this->processEvents(QEventLoop::ExcludeUserInputEvents,100);  // audio file is about 40ms long
			}



		}


		return QApplication::notify(obj, ev);
	}

};
*/


};
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ErpModel::GetInstance()->init();

	mainwindow w;
	//w.show();
	ContactIndexUI::ShowUI();
	ContactIndexUI::ShowUI();
	return a.exec();
}
