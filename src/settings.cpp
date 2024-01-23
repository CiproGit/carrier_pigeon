#include "settings.h"
#include "common.h"
#include "ui_settings.h"
#include <QMessageBox>
#include <QList>
#include <QListWidgetItem>

Settings::Settings(QWidget *parent) : QDialog(parent), ui(new Ui::Settings) {
	ui->setupUi(this);

	connect(ui->cancel_button, SIGNAL(clicked()), this, SLOT(on_cancel()));
	connect(ui->ok_button, SIGNAL(clicked()), this, SLOT(on_ok()));
}

Settings::~Settings() {
	delete ui;
}

void Settings::select_ip_address() const {
	if (IP_INDEX == IP_NOT_AVAILABLE) { // IP not available
		// Clear the IP address selection
		QList<QListWidgetItem *> selected_items = ui->ip_listwidget->selectedItems();
		for (const auto &selected_item : selected_items) {
			selected_item->setSelected(false);
		}
	}
	else ui->ip_listwidget->setCurrentRow(IP_INDEX);
}

void Settings::on_cancel() {
	this->close();
}

void Settings::on_ok() {
	int ip_index = ui->ip_listwidget->currentRow(); // QListWidget without selection automatically chooses the first item (with index 0) in the list
	unsigned short port = ui->port_spinbox->value();
	int timeout = ui->timeout_spinbox->value();

	QMessageBox messageBox;
	messageBox.setWindowTitle("Information");
	messageBox.setIcon(QMessageBox::Information);
	messageBox.setText("Please close and reopen the application to apply the changes");
	messageBox.exec();

	this->close();
	emit apply_settings(ip_index, port, timeout);
}

void Settings::showEvent(QShowEvent *event) {
	QDialog::showEvent(event);

	select_ip_address();
	ui->port_spinbox->setValue(PORT);
	ui->timeout_spinbox->setValue(TIMEOUT);
}

void Settings::print_ip_addresses(QString string) const {
	ui->ip_listwidget->addItem(string);
}
