#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
	class About;
}

class About : public QDialog {
	Q_OBJECT

private:
	Ui::About *ui;

public:
	About(QWidget *parent = nullptr);
	~About();
};

#endif // ABOUT_H
