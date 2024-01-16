#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class About; }
QT_END_NAMESPACE

class About : public QDialog {
	Q_OBJECT

private:
	Ui::About *ui;

public:
	About(QWidget *parent = nullptr);
	~About();
};

#endif // ABOUT_H
