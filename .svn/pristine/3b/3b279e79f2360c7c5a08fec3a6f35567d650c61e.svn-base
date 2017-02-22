#pragma once
#include <QWidget>
#include <QImage>
#include "ui_lotteryview.h"

class LotteryView : public QWidget, public Ui::LotteryView {
	Q_OBJECT

public:
	LotteryView(const QString &strName, const QImage &image, bool bDoubleView, bool bIsSmall, QWidget * parent = Q_NULLPTR);
	~LotteryView();

protected:
	void paintEvent(QPaintEvent *event);

private:
	QImage m_image;
	QString m_strName;
	bool m_bDoubleView = false;
};
