#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

class CApplication : public QApplication
{
	Q_OBJECT

public:
	CApplication(int &argc, char *argv[]);
	~CApplication();

signals:
	void showNormal();

protected:
	bool notify(QObject *receiver, QEvent *event) override;
private:
	
};

#endif // APPLICATION_H
