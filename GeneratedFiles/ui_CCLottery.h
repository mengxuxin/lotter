/********************************************************************************
** Form generated from reading UI file 'CCLottery.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCLOTTERY_H
#define UI_CCLOTTERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "lotteryingWin.h"

QT_BEGIN_NAMESPACE

class Ui_CCLottery
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *mainWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    ClotteryingWin *lotterywidget;
    QWidget *doubleItem;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *topLayout;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *bottomLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QWidget *oneItem;
    QVBoxLayout *verticalLayout_3;
    QWidget *OnlyViews;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QPushButton *mutilOperatorBtn;
    QLabel *label;
    QLabel *lotteryInfoLabel;
    QLabel *lotteryPicture;

    void setupUi(QWidget *CCLottery)
    {
        if (CCLottery->objectName().isEmpty())
            CCLottery->setObjectName(QStringLiteral("CCLottery"));
        CCLottery->resize(1280, 608);
        centralWidget = new QWidget(CCLottery);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setGeometry(QRect(0, 0, 1282, 650));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mainWidget = new QWidget(centralWidget);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        mainWidget->setMinimumSize(QSize(1280, 608));
        mainWidget->setMaximumSize(QSize(1280, 608));
        mainWidget->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-image: url(:/background/resources/button_begin_nor.png);\n"
"}\n"
"QPushButton:hover{\n"
"	border-image: url(:/background/resources/button_begin_hov.png);\n"
"}\n"
"QPushButton:clicked{\n"
"	border-image: url(:/background/resources/button_begin_click.png);\n"
"}"));
        stackedWidget = new QStackedWidget(mainWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(316, 106, 650, 268));
        stackedWidget->setMinimumSize(QSize(0, 0));
        stackedWidget->setMaximumSize(QSize(16777215, 16777215));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        lotterywidget = new ClotteryingWin(page);
        lotterywidget->setObjectName(QStringLiteral("lotterywidget"));
        lotterywidget->setGeometry(QRect(212, 0, 230, 250));
        lotterywidget->setMinimumSize(QSize(0, 0));
        lotterywidget->setMaximumSize(QSize(16777215, 16777215));
        stackedWidget->addWidget(page);
        doubleItem = new QWidget();
        doubleItem->setObjectName(QStringLiteral("doubleItem"));
        doubleItem->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(doubleItem);
        verticalLayout_2->setSpacing(9);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 12, 0, 10);
        widget = new QWidget(doubleItem);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 100));
        widget->setMaximumSize(QSize(16777215, 100));
        widget->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        topLayout = new QHBoxLayout();
        topLayout->setSpacing(30);
        topLayout->setObjectName(QStringLiteral("topLayout"));
        topLayout->setContentsMargins(-1, 2, 0, -1);

        horizontalLayout_3->addLayout(topLayout);


        verticalLayout_2->addWidget(widget);

        widget_2 = new QWidget(doubleItem);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 100));
        widget_2->setMaximumSize(QSize(16777215, 100));
        widget_2->setStyleSheet(QStringLiteral(""));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        bottomLayout = new QHBoxLayout();
        bottomLayout->setSpacing(30);
        bottomLayout->setObjectName(QStringLiteral("bottomLayout"));
        bottomLayout->setContentsMargins(107, 4, 2, -1);

        horizontalLayout_4->addLayout(bottomLayout);


        verticalLayout_2->addWidget(widget_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        label_2 = new QLabel(doubleItem);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setStyleSheet(QLatin1String("font-family:MicrosoftYaHei;\n"
"font-size:20px;\n"
"color:#ffffff;\n"
"letter-spacing:2px;\n"
"line-height:20px;\n"
"font: bold;\n"
"text-align:center;"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        stackedWidget->addWidget(doubleItem);
        oneItem = new QWidget();
        oneItem->setObjectName(QStringLiteral("oneItem"));
        verticalLayout_3 = new QVBoxLayout(oneItem);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        OnlyViews = new QWidget(oneItem);
        OnlyViews->setObjectName(QStringLiteral("OnlyViews"));
        verticalLayout_4 = new QVBoxLayout(OnlyViews);
        verticalLayout_4->setSpacing(35);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(9, 30, -1, 4);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(18);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        verticalLayout_4->addLayout(horizontalLayout);

        label_3 = new QLabel(OnlyViews);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 20));
        label_3->setMaximumSize(QSize(16777215, 20));
        label_3->setStyleSheet(QLatin1String("font-family:MicrosoftYaHei;\n"
"font-size:20px;\n"
"color:#ffffff;\n"
"letter-spacing:2px;\n"
"line-height:20px;\n"
"font: bold;\n"
"text-align:center;"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);


        verticalLayout_3->addWidget(OnlyViews);

        stackedWidget->addWidget(oneItem);
        mutilOperatorBtn = new QPushButton(mainWidget);
        mutilOperatorBtn->setObjectName(QStringLiteral("mutilOperatorBtn"));
        mutilOperatorBtn->setGeometry(QRect(562, 427, 155, 78));
        mutilOperatorBtn->setMinimumSize(QSize(0, 0));
        mutilOperatorBtn->setMaximumSize(QSize(16777215, 16777215));
        mutilOperatorBtn->setStyleSheet(QLatin1String("QPushButton#start{\n"
"	border-image: url(:/background/resources/button_begin_nor.png);\n"
"}\n"
"QPushButton#start:hover{\n"
"	border-image: url(:/background/resources/button_begin_hov.png);\n"
"}\n"
"QPushButton#start:pressed{\n"
"	border-image: url(:/background/resources/button_begin_click.png);\n"
"}\n"
"\n"
"QPushButton#stop{\n"
"	border-image: url(:/background/resources/button_stop_nor.png);\n"
"}\n"
"QPushButton#stop:hover{\n"
"	border-image: url(:/background/resources/button_stop_hov.png);\n"
"}\n"
"QPushButton#stop:pressed{\n"
"	border-image: url(:/background/resources/button_stop_click.png);\n"
"}\n"
"QPushButton#continue{\n"
"	border-image: url(:/background/resources/button_continue_nor.png);\n"
"}\n"
"QPushButton#continue:hover{\n"
"	border-image: url(:/background/resources/button_continue_hov.png);\n"
"}\n"
"QPushButton#continue:pressed{\n"
"	border-image: url(:/background/resources/button_continue_click.png);\n"
"}\n"
"\n"
"QPushButton#takeLottery{\n"
"	border-image: url(:/background/resources/bu"
                        "tton_finish_nor.png);\n"
"}\n"
"QPushButton#takeLottery:hover{\n"
"	border-image: url(:/background/resources/button_finish_hov.png);\n"
"}\n"
"QPushButton#takeLottery:pressed{\n"
"	border-image: url(:/background/resources/button_finish_click.png);\n"
"}"));
        label = new QLabel(mainWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(544, 44, 201, 21));
        label->setStyleSheet(QLatin1String("font-family:MicrosoftYaHei;\n"
"font-size:18px;\n"
"color:#ffffff;\n"
"line-height:19px;\n"
"font: bold;\n"
"text-shadow:0px 2px 4px #b01b00;"));
        lotteryInfoLabel = new QLabel(mainWidget);
        lotteryInfoLabel->setObjectName(QStringLiteral("lotteryInfoLabel"));
        lotteryInfoLabel->setGeometry(QRect(570, 533, 141, 16));
        lotteryInfoLabel->setStyleSheet(QLatin1String("font-family:MicrosoftYaHei;\n"
"font-size:18px;\n"
"color:#ffffff;\n"
"font: bold;\n"
"line-height:18px;\n"
"text-shadow:0px 2px 4px #b01b00;\n"
"text-align:center;"));
        lotteryInfoLabel->setAlignment(Qt::AlignCenter);
        lotteryPicture = new QLabel(mainWidget);
        lotteryPicture->setObjectName(QStringLiteral("lotteryPicture"));
        lotteryPicture->setGeometry(QRect(778, 340, 266, 192));
        lotteryPicture->setMinimumSize(QSize(0, 0));
        lotteryPicture->setMaximumSize(QSize(16777215, 16777215));
        lotteryPicture->setStyleSheet(QStringLiteral(""));

        verticalLayout->addWidget(mainWidget);


        retranslateUi(CCLottery);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CCLottery);
    } // setupUi

    void retranslateUi(QWidget *CCLottery)
    {
        CCLottery->setWindowTitle(QApplication::translate("CCLottery", "CCLottery", 0));
        label_2->setText(QApplication::translate("CCLottery", "\346\234\211\350\257\267\344\270\255\345\245\226\347\232\204\345\260\217\344\274\231\344\274\264\344\270\212\345\217\260\351\242\206\345\245\226", 0));
        label_3->setText(QApplication::translate("CCLottery", "\346\234\211\350\257\267\344\270\255\345\245\226\347\232\204\345\260\217\344\274\231\344\274\264\344\270\212\345\217\260\351\242\206\345\245\226", 0));
        mutilOperatorBtn->setText(QString());
        label->setText(QApplication::translate("CCLottery", "2017\345\271\264CC\350\247\206\351\242\221\345\271\264\344\274\232\346\212\275\345\245\226", 0));
        lotteryInfoLabel->setText(QApplication::translate("CCLottery", "%1\357\274\210%2/%3\357\274\211", 0));
        lotteryPicture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CCLottery: public Ui_CCLottery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCLOTTERY_H
