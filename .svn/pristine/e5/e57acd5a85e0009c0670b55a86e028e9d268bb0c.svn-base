#ifndef CCLOTTERY_H
#define CCLOTTERY_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QMap>
#include "LotterySettingsWin.h"
#include "lotteryData.h"
namespace Ui {
class CCLottery;
}


class CCLottery : public QWidget
{
    Q_OBJECT

public:
    explicit CCLottery(QWidget *parent = 0);
    ~CCLottery();

	void changeGeometry(bool bInc);

protected:
    void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void closeEvent(QCloseEvent *event);
private:
    void onStartlotteryBtnClicked();
    void onStoplotteryBtnClicked();
    void onShowSettings();
	void onMutilOprator();

	void showLotteryViews();
	void updateControlsPos(bool bInc);
private:
    int m_nlotteryCount;      //数量
    int m_curCount = 0;           //当前是抽取的第几个
	QString m_strLotteryItem;
	QString m_strBGPath = ":/background/resources/bg.png";
	QMap<int, SPeopleInfo> m_map;	//当前奖项的当前轮次的抽中的人
    Ui::CCLottery *ui;
	QTimer timer;
	bool m_bStartLottery = false;
	bool m_bVisbleSettings = false;
	bool m_bSmall = false;		//是否将分辨率变为1000*475
	LotterySettingsWin *m_settings;
};

#endif // CCLOTTERY_H
