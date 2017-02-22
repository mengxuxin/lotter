#include "lotteryingWin.h"
#include <QTimer>
#include <QPainter>
#include <QImage>
#include <QHBoxLayout>
#include "DBUtil.h"

ClotteryingWin::ClotteryingWin(QWidget *parent):
    QWidget(parent)
{
	//this->setWindowFlags(Qt::FramelessWindowHint | Qt::Window | Qt::Tool);

    m_lotteryTimer = new QTimer(this);
    m_lotteryTimer->setInterval(3);

    connect(m_lotteryTimer, SIGNAL(timeout()), this, SLOT(slotLotteryTimer()));

	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->setContentsMargins(2, 0, 2, 2);
	mainLayout->setSpacing(0);
	m_nameLabel = new QLabel(this);
	m_nameLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	m_nameLabel->setFixedHeight(50);
	mainLayout->addStretch();
	mainLayout->addWidget(m_nameLabel);
	m_nameLabel->setVisible(false);
	m_nameLabel->setStyleSheet("QLabel{ font-family:MicrosoftYaHei;font: bold;background:rgba(51,51,51,150); color: white; font-size:22px;}");
	this->setLayout(mainLayout);
}

void ClotteryingWin::setLotteryItem(const QString &strLottery)
{
	m_strLotteryItem = strLottery;
}

int ClotteryingWin::startLottery()
{
	qDebug() << "enter startLottery";
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	m_waitLotteryPeoples = CLotteryData::instance()->getWaitLotteryPeoples();
	qDebug() << "start lottery peoples count:" << m_waitLotteryPeoples.count();
	if (m_waitLotteryPeoples.count() > 0)
	{
		m_curIndex = m_waitLotteryPeoples.count() - 1;
		m_curPeole = m_waitLotteryPeoples.back();
		m_lotteryTimer->start();
	}
	else
	{
		qDebug() << "leave startLottery -1";
		return -1;
	}
	qDebug() << "leave startLottery 1";
	return 1;
}

#include <QDebug>
void ClotteryingWin::stopLottery()
{
	qDebug() << "enter stopLottery";
    m_lotteryTimer->stop();
	CLotteryData::instance()->removeOnePeople(m_curPeole);
    qDebug() << m_curPeole.m_strName;
    QVariantMap params, updateMaps;
	updateMaps["name"] = m_curPeole.m_strName;
    params["name"] = m_curPeole.m_strName;
    params["lotteryItem"] = m_strLotteryItem;
	params["time"] = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	DBUtil::instance()->update(QString("update Users set bLottery = 1 WHERE username = :name").arg(m_strLotteryItem), updateMaps);
    DBUtil::instance()->insert(QString("INSERT INTO lotterys (username, lotteryItem, time) VALUES (:name, :lotteryItem, :time)"), params);
	m_waitLotteryPeoples.clear();
	qDebug() << "leave stopLottery";
}

SPeopleInfo ClotteryingWin::getLotteredPeople()
{
	return m_curPeole;
}

void ClotteryingWin::slotLotteryTimer()
{
	if (!m_waitLotteryPeoples.isEmpty())
	{
		m_curIndex = qrand() % m_waitLotteryPeoples.count();
		m_curPeole = m_waitLotteryPeoples.at(m_curIndex);
		m_nameLabel->setText(m_curPeole.m_strName);
		m_nameLabel->setVisible(true);
		update();
	}
}

void ClotteryingWin::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    if (!m_curPeole.m_pictureba.isEmpty())
    {
        p.drawImage(this->rect(), m_curPeole.m_image);
    }
}
