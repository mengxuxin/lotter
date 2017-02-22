#include "LotterySettingsWin.h"
#include "ui_LotterySettingsWiningswin.h"
#include <QComboBox>
#include <QSpinBox>

LotterySettingsWin::LotterySettingsWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LotterySettingsWin)
{
    ui->setupUi(this);
	ui->comboBox->setItemData(0, "four");
    ui->comboBox->setItemData(1, "thrid");
    ui->comboBox->setItemData(2, "second");
    ui->comboBox->setItemData(3, "first");
    ui->comboBox->setItemData(4, "special");
    ui->comboBox->setItemData(5, "luck");
}

LotterySettingsWin::~LotterySettingsWin()
{
    delete ui;
}

int LotterySettingsWin::getPeopelCount()
{
    return ui->spinBox->value();
}

QString LotterySettingsWin::getLotteryItem()
{
    return ui->comboBox->currentText();
}

QString LotterySettingsWin::getDBTableName()
{
	return ui->comboBox->itemData(ui->comboBox->currentIndex()).toString();
}
