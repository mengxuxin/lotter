#include "CCLottery.h"
#include "ui_CCLottery.h"
#include <QFile>
#include <QPainter>
#include <QDialog>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTableView>
#include "DBUtil.h"
#include "LotterySettingsWin.h"
#include "LotteryView.hpp"

QString strLotteryInfo = "%1 (%2/%3)";

CCLottery::CCLottery(QWidget *parent) :
	QWidget(parent),
    ui(new Ui::CCLottery)
{
    ui->setupUi(this);

    //connect(ui->settingBtn, &QPushButton::clicked, this, &CCLottery::onShowSettings);
	connect(ui->mutilOperatorBtn, &QPushButton::clicked, this, &CCLottery::onMutilOprator);
    setFixedSize(1280, 608);
	onShowSettings();

	//ui->widgetTitle->setVisible(false);
	
	timer.setInterval(50);
	connect(&timer, &QTimer::timeout, [this] {
		if (!m_bStartLottery)
		{
			if (m_strBGPath.compare(":/background/resources/bg.png") == 0)
			{
				m_strBGPath = ":/background/resources/bg2.png";
			}
			else
			{
				m_strBGPath = ":/background/resources/bg.png";
			}
		}
		else
		{
			if (m_strBGPath.compare(":/background/resources/startLotteryBG1.png") == 0)
			{
				m_strBGPath = ":/background/resources/startLotteryBG12.png";
			}
			else
			{
				m_strBGPath = ":/background/resources/startLotteryBG1.png";
			}

		}
		update();
	});
	timer.start();
	//ui->stackedWidget->setGeometry(287, 119, 706, 324);
	ui->stackedWidget->setCurrentWidget(ui->page);

	ui->mutilOperatorBtn->setObjectName("start");
	//ui->lotteryLabel->setVisible(false);

	//由于目前没有全屏，先将其屏蔽掉
	//ui->widgetTitle->setVisible(false);
	updateControlsPos(true);

	ui->mutilOperatorBtn->setStyleSheet("QPushButton#start{\
	border-image: url(:/background/resources/button_begin_nor.png);\
}\
QPushButton#start:hover{\
	border-image: url(:/background/resources/button_begin_hov.png);\
}\
QPushButton#start:pressed{\
	border-image: url(:/background/resources/button_begin_click.png);\
}\
QPushButton#takeLottery{\
	border-image: url(:/background/resources/button_finish_nor.png);\
}\
QPushButton#takeLottery:hover{\
	border-image: url(:/background/resources/button_finish_hov.png);\
}\
QPushButton#takeLottery:pressed{\
	border-image: url(:/background/resources/button_finish_click.png);}");
}

CCLottery::~CCLottery()
{
    DBUtil::releaseInstance();
    delete ui;
}

void CCLottery::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    QFile f;
    f.setFileName(m_strBGPath);
    f.open(QIODevice::ReadOnly);
    QByteArray imgData=f.readAll();
    f.close();

    QImage pixmap=QImage::fromData(imgData);

   p.drawImage(this->rect(), pixmap);
}

void initializeModel(QSqlQueryModel *model, const QString &strTableName)
{
	QString str = QString("select username, lotteryItem, time from %1").arg(strTableName);
	model->setQuery(str, DBUtil::instance()->db);
	model->setHeaderData(0, Qt::Horizontal, QObject::tr("username"));
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("lotteryItem"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("time"));
}

QTableView* createView(QSqlQueryModel *model, const QString &title = "")
{
	QTableView *view = new QTableView;
	view->setModel(model);
	static int offset = 0;

	view->setWindowTitle(title);
	view->move(100 + offset, 100 + offset);
	offset += 20;
	view->show();

	return view;
}

void CCLottery::keyPressEvent(QKeyEvent *event)
{
	// 响应Esc键以退出程序
	if (event->key() == Qt::Key_Escape)
	{
		showNormal();  //窗口最大化
		//updateControlsPos(false);
	}
	else if (!m_bVisbleSettings && event->key() == Qt::Key_Backspace)
	{
		onShowSettings();
	}
	else if (event->key() == Qt::Key_F3)
	{
			QSqlQueryModel *plainModel = new QSqlQueryModel;
			initializeModel(plainModel, "lotterys");
			createView(plainModel, "lotteryUsers");
	}
	QWidget::keyPressEvent(event);
}

void CCLottery::closeEvent(QCloseEvent *event)
{
	QMessageBox msgBox;
	msgBox.setInformativeText("Do you want to close?");
	msgBox.setStandardButtons(QMessageBox::Ok |  QMessageBox::Cancel);
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

void CCLottery::onStartlotteryBtnClicked()
{
	ui->lotterywidget->setVisible(true);
	if (ui->lotterywidget->startLottery() < 0)
	{
		return;
	}
	m_bStartLottery = true;
	m_bVisbleSettings = true;
    m_curCount++;
	//ui->lotteryLabel->setVisible(false);
	ui->lotteryInfoLabel->setText(strLotteryInfo.arg(m_strLotteryItem).arg(QString::number(m_curCount)).arg(QString::number(m_nlotteryCount)));
}
QString str = "恭喜%1获得%2";
void CCLottery::onStoplotteryBtnClicked()
{
    ui->lotterywidget->stopLottery();
	SPeopleInfo curLotteryPeople = ui->lotterywidget->getLotteredPeople();
	m_map.insert(m_curCount, curLotteryPeople);
	//ui->lotteryLabel->setText(str.arg(curLotteryPeople.m_strName).arg(m_strLotteryItem));
	//ui->lotteryLabel->setVisible(true);
}

void CCLottery::onShowSettings()
{
	m_settings = new LotterySettingsWin(this);
	QString curDBTableName;
	if (m_settings->exec() == QDialog::Accepted)
	{
		m_strLotteryItem = m_settings->getLotteryItem();
		m_nlotteryCount = m_settings->getPeopelCount();
		curDBTableName = m_settings->getDBTableName();

		ui->stackedWidget->setCurrentWidget(ui->page);
		//ui->lotteryLabel->setVisible(false);
		ui->mutilOperatorBtn->setStyleSheet("QPushButton#start{\
	border-image: url(:/background/resources/button_begin_nor.png);\
}\
QPushButton#start:hover{\
	border-image: url(:/background/resources/button_begin_hov.png);\
}\
QPushButton#start:pressed{\
	border-image: url(:/background/resources/button_begin_click.png);\
}");
		ui->mutilOperatorBtn->setObjectName("start");
		m_bStartLottery = false;
		ui->lotterywidget->setVisible(false);
		ui->lotteryInfoLabel->setText(strLotteryInfo.arg(m_strLotteryItem).arg(QString::number(0)).arg(QString::number(m_nlotteryCount)));
		ui->lotterywidget->setLotteryItem(curDBTableName);
		ui->lotteryPicture->setStyleSheet(QString("QLabel{image: url(:/background/%1)}").arg(curDBTableName));
		//由于目前先不使用全屏，暂时屏蔽掉
	// 	ui->widgetTitle->setVisible(false);
	// 	updateControlsPos(true);
	}
}

void CCLottery::onMutilOprator()
{
	
	QString strText = ui->mutilOperatorBtn->objectName();
	if (strText.compare("start") == 0 || strText.compare("continue") == 0)
	{
		/*ui->mutilOperatorBtn->setEnabled(false);
		QTimer::singleShot(1000, [this] {
			ui->mutilOperatorBtn->setEnabled(true);
			ui->mutilOperatorBtn->setFocus();
		});*/
		//开始逻辑
		onStartlotteryBtnClicked();
		ui->mutilOperatorBtn->setObjectName("stop");
		ui->mutilOperatorBtn->setStyleSheet("QPushButton{\
	border-image: url(:/background/resources/button_stop_nor.png);\
}\
QPushButton:hover{\
	border-image: url(:/background/resources/button_stop_hov.png);\
}\
QPushButton:pressed{\
	border-image: url(:/background/resources/button_stop_click.png);\
}");
	}
	else if (strText.compare("stop") == 0)
	{
		
		onStoplotteryBtnClicked();
		
		if (m_nlotteryCount == m_curCount)
		{
			m_curCount = 0;
			ui->mutilOperatorBtn->setObjectName("takeLottery");
			ui->mutilOperatorBtn->setStyleSheet("QPushButton{\
	border-image: url(:/background/resources/button_finish_nor.png);\
}\
QPushButton:hover{\
	border-image: url(:/background/resources/button_finish_hov.png);\
}\
QPushButton:pressed{\
	border-image: url(:/background/resources/button_finish_click.png);}");
		}
		else
		{
			ui->mutilOperatorBtn->setObjectName("continue");
			ui->mutilOperatorBtn->setStyleSheet("QPushButton{\
	border-image: url(:/background/resources/button_continue_nor.png);\
}\
QPushButton:hover{\
	border-image: url(:/background/resources/button_continue_hov.png);\
}\
QPushButton:pressed{\
	border-image: url(:/background/resources/button_continue_click.png);\
}");
		}
	}
	else if (strText.compare("takeLottery") == 0)
	{
		m_bVisbleSettings = false;
		ui->mutilOperatorBtn->setObjectName("no");
		//当前一轮抽奖结束
		//拿到当前轮的获奖人员,进行展示
		showLotteryViews();
	}
	else if (strText.compare("no") == 0)
	{
		m_bVisbleSettings = false;
	}
}

void CCLottery::showLotteryViews()
{
	while (ui->topLayout->count())
	{
		QWidget *p = ui->topLayout->itemAt(0)->widget();
		if (p)
		{
			p->setParent(NULL);
			ui->topLayout->removeWidget(p);
			delete p;
		}
	}
	while (ui->bottomLayout->count())
	{
		qDebug() << ui->bottomLayout->count();
		QWidget *p = ui->bottomLayout->itemAt(0)->widget();
		if (p)
		{
			p->setParent(NULL);
			ui->bottomLayout->removeWidget(p);
			delete p;
		}
		else
		{
			QSpacerItem* pS = ui->bottomLayout->itemAt(0)->spacerItem();
			if (pS)
			{
				ui->bottomLayout->removeItem(pS);
				delete pS;
			}
		}
	}
	while (ui->horizontalLayout->count())
	{
		QWidget *p = ui->horizontalLayout->itemAt(0)->widget();
		if (p)
		{
			p->setParent(NULL);
			ui->horizontalLayout->removeWidget(p);
			delete p;
		}
		else if (ui->horizontalLayout->count())
		{
			QSpacerItem* pS = ui->horizontalLayout->itemAt(0)->spacerItem();
			if (pS)
			{
				ui->horizontalLayout->removeItem(pS);
				delete pS;
			}
		}
	}
	int nCount = m_map.count();
	if (nCount > 4)
	{
		ui->stackedWidget->setCurrentWidget(ui->doubleItem);
		for (auto i = 1; i <= nCount; ++i)
		{
			SPeopleInfo people = m_map.value(i);
			bool b = nCount >= 4;
			LotteryView *view = new LotteryView(people.m_strName, people.m_image, b, m_bSmall, this);
			if (i <= 4)
			{
				ui->topLayout->addWidget(view);
			}
			else
			{
				ui->bottomLayout->addWidget(view);
			}
			
		}
		if (nCount > 4 && nCount < 8)
		{
			ui->bottomLayout->addStretch();
			if (m_bSmall)
			{
				ui->bottomLayout->setContentsMargins(70, 4, 2, 0);
			}
			else
				ui->bottomLayout->setContentsMargins(107, 4, 2, 0);
		}
		else if (nCount)
		{
			ui->bottomLayout->setContentsMargins(0, 4, 2, 0);
		}
	}
	else
	{
		if (nCount == 2 || nCount == 3)
		{
			ui->horizontalLayout->addStretch();
		}
		ui->stackedWidget->setCurrentWidget(ui->oneItem);
		for (auto i = 1; i <= nCount; ++i)
		{
			SPeopleInfo people = m_map.value(i);
			bool b = false;
			LotteryView *view = new LotteryView(people.m_strName, people.m_image, false, m_bSmall, this);
			ui->horizontalLayout->addWidget(view);
		}
		if (nCount == 2|| nCount == 3)
		{
			ui->horizontalLayout->addStretch();
		}
	}
	m_map.clear();
}

void CCLottery::updateControlsPos(bool bInc)
{
	int incHeight = 18;
	if (bInc)
	{
		QRect rect = ui->label->geometry();
		ui->label->setGeometry(rect.x(), rect.y()+ incHeight, rect.width(), rect.height());
		rect = ui->lotterywidget->geometry();
		ui->lotterywidget->setGeometry(rect.x(), rect.y() + 10, rect.width(), rect.height());
		//rect = ui->lotteryLabel->geometry();
		//ui->lotteryLabel->setGeometry(rect.x(), rect.y() + incHeight, rect.width(), rect.height());
		rect = ui->mutilOperatorBtn->geometry();
		ui->mutilOperatorBtn->setGeometry(rect.x(), rect.y() + incHeight, rect.width(), rect.height());
		rect = ui->lotteryInfoLabel->geometry();
		ui->lotteryInfoLabel->setGeometry(rect.x(), rect.y() + incHeight, rect.width(), rect.height());

		rect = ui->stackedWidget->geometry();
		ui->stackedWidget->setGeometry(rect.x(), rect.y() + incHeight, rect.width(), rect.height());
		rect = ui->OnlyViews->geometry();
		ui->OnlyViews->setGeometry(rect.x(), rect.y() + incHeight, rect.width(), rect.height());
		rect = ui->widget->geometry();
		ui->widget->setGeometry(rect.x(), rect.y() + incHeight, rect.width(), rect.height());
		rect = ui->widget_2->geometry();
		ui->widget_2->setGeometry(rect.x(), rect.y() + incHeight, rect.width(), rect.height());
	}
	else
	{
		QRect rect = ui->label->geometry();
		ui->label->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
		rect = ui->lotterywidget->geometry();
		ui->lotterywidget->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
		//rect = ui->lotteryLabel->geometry();
		//ui->lotteryLabel->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
		rect = ui->mutilOperatorBtn->geometry();
		ui->mutilOperatorBtn->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
		rect = ui->lotteryInfoLabel->geometry();
		ui->lotteryInfoLabel->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());

		rect = ui->OnlyViews->geometry();
		ui->OnlyViews->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
		rect = ui->widget->geometry();
		ui->widget->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
		rect = ui->widget_2->geometry();
		ui->widget_2->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
	}
}

void CCLottery::changeGeometry(bool bInc)
{
	int incHeight = 18;
	int incWidget = 119;
	float changeSize = 0.78125;
	m_bSmall = bInc;
	if (bInc)
	{
		QRect rect = ui->label->geometry();
		ui->label->setGeometry(rect.x() - incWidget, rect.y() - incHeight, rect.width() * changeSize, rect.height() * changeSize);
		ui->label->setStyleSheet("QLabel{font-family:MicrosoftYaHei;font-size:14px;font: bold;line-height:19px;color:#ffffff;}");
		rect = ui->lotterywidget->geometry();
		
		ui->lotterywidget->setGeometry(rect.x() - 55, rect.y(), rect.width() * changeSize, rect.height() * changeSize);
		//rect = ui->lotteryLabel->geometry();
		//ui->lotteryLabel->setGeometry(rect.x() - 62, rect.y() - 56, rect.width(), rect.height());
		//ui->lotteryLabel->setStyleSheet("QLabel{font-family:MicrosoftYaHei;font-size:16px;font: bold;line-height:19px;color:#ffffff;}");
		
		rect = ui->mutilOperatorBtn->geometry();
		ui->mutilOperatorBtn->setGeometry(rect.x() - 125, rect.y() - 101, rect.width() * changeSize, rect.height() * changeSize);
		rect = ui->lotteryInfoLabel->geometry();
		ui->lotteryInfoLabel->setGeometry(rect.x() - 127, rect.y() - 128, rect.width() * changeSize, rect.height());
		ui->lotteryInfoLabel->setStyleSheet("QLabel{font-family:MicrosoftYaHei;font-size:14px;font: bold;line-height:19px;color:#ffffff;}");
		
		rect = ui->lotteryPicture->geometry();
		ui->lotteryPicture->setGeometry(rect.x() - 185, rect.y() - 81, 208, 150);

		rect = ui->stackedWidget->geometry();
		ui->stackedWidget->setGeometry(rect.x() - 70, rect.y() - 36, rect.width() * changeSize, rect.height() * changeSize);
		
		ui->verticalLayout_2->setContentsMargins(0, 5, 0, 2);
		//ui->verticalLayout_4->setContentsMargins(0, 5, 0, 10);
		rect = ui->label_2->geometry();
		ui->label_2->setGeometry(rect.x(), rect.y() + 32, rect.width(), rect.height());
		ui->verticalLayout_2->setSpacing(4);
		/*ui->verticalLayout_2->setSpacing(5);
		ui->verticalLayout_4->setSpacing(30);
		
		rect = ui->label_2->geometry();
		ui->label_2->setGeometry(rect.x(), rect.y() + 11, rect.width(), rect.height());
		rect = ui->label_3->geometry();
		ui->label_3->setGeometry(rect.x(), rect.y() + 11, rect.width(), rect.height());*/
		ui->label_2->setStyleSheet("QLabel{font-family:MicrosoftYaHei;font-size:16px;font: bold;line-height:19px;color:#ffffff;}");
		ui->label_3->setStyleSheet("QLabel{font-family:MicrosoftYaHei;font-size:16px;font: bold;line-height:19px;color:#ffffff;}");

		/*rect = ui->OnlyViews->geometry();
		ui->OnlyViews->setGeometry(rect.x() - incWidget, rect.y() - incHeight, rect.width() * changeSize, rect.height() * changeSize);
		rect = ui->widget->geometry();
		ui->widget->setGeometry(rect.x() - incWidget, rect.y() - incHeight, rect.width() * changeSize, rect.height() * changeSize);
		rect = ui->widget_2->geometry();
		ui->widget_2->setGeometry(rect.x() - incWidget, rect.y() - incHeight, rect.width() * changeSize, rect.height() * changeSize);*/
	}
	else
	{
		QRect rect = ui->label->geometry();
		ui->label->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
		rect = ui->lotterywidget->geometry();
		ui->lotterywidget->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
		//rect = ui->lotteryLabel->geometry();
		//ui->lotteryLabel->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
		rect = ui->mutilOperatorBtn->geometry();
		ui->mutilOperatorBtn->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
		rect = ui->lotteryInfoLabel->geometry();
		ui->lotteryInfoLabel->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());

		rect = ui->OnlyViews->geometry();
		ui->OnlyViews->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
		rect = ui->widget->geometry();
		ui->widget->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
		rect = ui->widget_2->geometry();
		ui->widget_2->setGeometry(rect.x(), rect.y() - incHeight, rect.width(), rect.height());
	}
}


