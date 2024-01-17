#include "settings.h"
#include "ui_settings.h"
#include <QMessageBox>

Settings::Settings(QWidget *parent) : QDialog(parent), ui(new Ui::Settings) {
	ui->setupUi(this);

	connect(ui->cancel_button, SIGNAL(clicked()), this, SLOT(on_cancel()));
	connect(ui->ok_button, SIGNAL(clicked()), this, SLOT(on_ok()));
}

Settings::~Settings() {
	delete ui;
}

void Settings::on_cancel() {
	this->close();
}

void Settings::on_ok() {
	QMessageBox messageBox;
	messageBox.setWindowTitle("Information");
	messageBox.setIcon(QMessageBox::Information);
	messageBox.setText("Please close and reopen the application to apply the changes");
	messageBox.exec();

	this->close();
}

void Settings::print_ip_addresses(QString string) const {
	ui->ip_listwidget->addItem(string);
}

void Settings::select_ip_address(int index) const {
	ui->ip_listwidget->setCurrentRow(index);
}
