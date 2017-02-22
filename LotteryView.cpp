#include "LotteryView.hpp"
#include <QPainter>

LotteryView::LotteryView(const QString &strName, const QImage &image, bool bDoubleView, bool bIsSmall, QWidget * parent)
	: QWidget(parent) ,
	m_strName(strName),
	m_image(image),
	m_bDoubleView(bDoubleView)
{
	setupUi(this);
	if (!bIsSmall)
	{
		if (m_bDoubleView)
			setFixedSize(86, 96);
		else
			setFixedSize(141, 158);
	}
	else
	{
		if (m_bDoubleView)
			setFixedSize(68, 75);
		else
			setFixedSize(111, 124);
		namelabel->setStyleSheet("QLabel{border-radius:0px 0px 6px 6px;border: 0px; background:rgba(51,51,51,150); color: white; font-size:14px;font-family:MicrosoftYaHei; font: bold;}");
	}
	namelabel->setText(strName);
}

LotteryView::~LotteryView() {
	
}

void LotteryView::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing);

	p.drawImage(this->rect(), m_image);
}
