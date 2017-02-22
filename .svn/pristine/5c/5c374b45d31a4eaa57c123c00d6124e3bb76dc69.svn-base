#ifndef CLOTTERYINGWIN_H
#define CLOTTERYINGWIN_H

#include "lotteryData.h"
#include <QWidget>
#include <QLabel>

/**
 * @brief 抽奖界面每次抽取一个人出来
 */
class ClotteryingWin : public QWidget
{
    Q_OBJECT
public:
    ClotteryingWin(QWidget *parent = NULL);

	void setLotteryItem(const QString &strLottery);

    /**
     * @brief 开启抽奖timer
     * 开始抽奖
     */
	int startLottery();

    /**
     * @brief 结束抽奖
     *
     */
    void stopLottery();

    SPeopleInfo getLotteredPeople();

private slots:
    void slotLotteryTimer();

protected:
    void paintEvent(QPaintEvent *event);

private:
    QTimer *m_lotteryTimer; //抽奖
    QVector<SPeopleInfo> m_waitLotteryPeoples;  //待抽奖人员列表
	//QMap<int, QSharedPointer<SPeopleInfo>> m_map;
    SPeopleInfo m_curPeole; //当前人员
    int m_curIndex;
    QString m_strLotteryItem; //人员
	QLabel *m_nameLabel;
};

#endif // CLOTTERYINGWIN_H
