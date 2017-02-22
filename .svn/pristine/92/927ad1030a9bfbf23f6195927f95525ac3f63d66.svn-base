#include "MainWindow.hpp"
#include <QDialog>
#include <QKeyEvent>
#include <QMessageBox>
MainWindow::MainWindow(QMainWindow * parent) : QMainWindow(parent) {
	ui.setupUi(this);
	setWindowTitle(QStringLiteral("年会抽奖"));
}

MainWindow::~MainWindow() {
	
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

	// 响应Esc键以退出程序
	if (event->key() == Qt::Key_F1)
	{
		showFullScreen();  //窗口最大化
		//updateControlsPos(false);
	}
	else if (event->key() == Qt::Key_F2)
	{
		showNormal();
		//onShowSettings();
	}
	else if (event->key() == Qt::Key_Minus && (event->modifiers() & Qt::AltModifier))
	{
		ui.widget->setFixedSize(1000, 475);
		ui.widget->changeGeometry(true);
	}
	else if (event->key() == Qt::Key_Plus)
	{
		ui.widget->setFixedSize(1280, 608);
	}
	QWidget::keyPressEvent(event);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	QMessageBox msgBox;
	msgBox.setInformativeText("Do you want to close?");
	msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	msgBox.setDefaultButton(QMessageBox::Ok);
	int ret = msgBox.exec();
	if (ret == QMessageBox::Ok)
		close();
	else
	{
		event->ignore();
		return;
	}
	//QMainWindow::closeEvent(event);
}
