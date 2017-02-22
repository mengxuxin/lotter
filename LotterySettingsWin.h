#ifndef LOTTERYSETTINGSWIN_H
#define LOTTERYSETTINGSWIN_H

#include <QDialog>

namespace Ui {
class LotterySettingsWin;
}

class LotterySettingsWin : public QDialog
{
    Q_OBJECT

public:
    explicit LotterySettingsWin(QWidget *parent = 0);
    ~LotterySettingsWin();

    int getPeopelCount();
    QString getLotteryItem();
	QString getDBTableName();

private:
    Ui::LotterySettingsWin *ui;
};

#endif // LOTTERYSETTINGSWIN_H
