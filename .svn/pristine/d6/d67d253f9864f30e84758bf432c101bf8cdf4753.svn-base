#include "CCLottery.h"
#include <QApplication>
#include <QMessageBox>
#include "MainWindow.hpp"
#include "DBUtil.h"
#include "Application.h"

int main(int argc, char *argv[])
{
    CApplication a(argc, argv);

    CLotteryData::instance();
    DBUtil::instance();
	MainWindow w;
    w.show();

    return a.exec();
}
