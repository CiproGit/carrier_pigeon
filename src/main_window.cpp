#include "main_window.h"
#include "common.h"
#include "ui_main_window.h"
#include <QMessageBox>

Main_window::Main_window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Main_window) {
	ui->setupUi(this);

	this->setWindowTitle(APPLICATION_NAME);

	connect(ui->about_action, SIGNAL(triggered()), this, SLOT(show_about()));
	connect(ui->settings_action, SIGNAL(triggered()), this, SLOT(show_settings()));
	connect(ui->send_button, SIGNAL(clicked()), this, SLOT(on_send()));
}

Main_window::~Main_window() {
	delete ui;
}

void Main_window::on_send() {
	QString message_string = ui->message_textedit->toPlainText();
	QString destination_string = QString::number(ui->destination_spinbox_1->value()) + '.' +
								 QString::number(ui->destination_spinbox_2->value()) + '.' +
								 QString::number(ui->destination_spinbox_3->value()) + '.' +
								 QString::number(ui->destination_spinbox_4->value());

	if (message_string.isEmpty()) {
		QMessageBox messageBox;
		messageBox.setWindowTitle("Error");
		messageBox.setIcon(QMessageBox::Warning);
		messageBox.setText("Empty message");
		messageBox.exec();
	}
	else emit send_message(destination_string, message_string);
}

void Main_window::show_about() {
	this->about.show();
}

void Main_window::show_settings() {
	this->settings.show();
}

Settings *Main_window::get_settings() {
	return &this->settings;
}

void Main_window::disable_gui() const {
	ui->settings_action->setEnabled(false);
	ui->send_button->setEnabled(false);
}

void Main_window::welcome() const {
	QString message = "The following IP address has been chosen: " + IP_ADDRESS + "\nYou can change it in settings";

	QMessageBox messageBox;
	messageBox.setWindowTitle("Information");
	messageBox.setIcon(QMessageBox::Information);
	messageBox.setText(message);
	messageBox.exec();
}

void Main_window::print_current_ip(QString string) const {
	ui->ip_lineedit->setText(string);
}

void Main_window::print_console(QString string) const {
	ui->console_textedit->appendPlainText(string);
}

void Main_window::print_ingoing(QString sender_string, QString timestamp, QString message_string) const {
	ui->ingoing_textedit->append("<html><b>From " + sender_string + " --- " + timestamp + "</b</html>");
	ui->ingoing_textedit->append(message_string);
}
