#include "Application.h"
#include <QDebug>

CApplication::CApplication(int &argc, char *argv[])
	: QApplication(argc,argv)
{
}

CApplication::~CApplication()
{
}

#include <QKeyEvent>
bool CApplication::notify(QObject *receiver, QEvent *event)
{
	//qDebug() << "receiver:" << receiver->objectName() << "  type" << event->type();
	if (event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease)
	{
		QKeyEvent *keyevent = static_cast<QKeyEvent *>(event);
		if (keyevent && keyevent->key() == Qt::Key_Escape)
		{
			emit showNormal();
			return true;
		}
	}
	return QApplication::notify(receiver, event);
}
