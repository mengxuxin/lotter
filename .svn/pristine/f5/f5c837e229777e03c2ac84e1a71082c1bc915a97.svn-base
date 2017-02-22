#pragma once
#include <QMainWindow>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QMainWindow * parent = Q_NULLPTR);
	~MainWindow();

protected:
	void keyPressEvent(QKeyEvent *event);
	void closeEvent(QCloseEvent *event);

private:
	Ui::MainWindow ui;
};
