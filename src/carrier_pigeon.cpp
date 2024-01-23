#include "carrier_pigeon.h"
#include "common.h"
#include <QByteArray>
#include <QDebug>
#include <QDateTime>
#include <QNetworkInterface>
#include <QHostAddress>

Carrier_pigeon::Carrier_pigeon(Main_window *window) {
	this->window = window;
	this->ip_address_list = get_address_list();
}

Carrier_pigeon::~Carrier_pigeon() {

}

QList<QString> Carrier_pigeon::get_address_list() {
	QList<QString> ip_address_list;

	for (const auto &ip_address : QNetworkInterface::allAddresses()) {
		if (!ip_address.isLoopback() && ip_address.protocol() == QAbstractSocket::IPv4Protocol) ip_address_list.push_back(ip_address.toString());
	}

	return ip_address_list;
}

void Carrier_pigeon::configure() {
	bool first_set_up = !this->settings_manager.exists(); // If the settings file does not exist, then this is the first time the application has been launched

	this->settings_manager.create();

	if (first_set_up) {
		// Automatically choose the first IP address
		IP_INDEX = 0;
		IP_ADDRESS = this->ip_address_list.first();

		this->settings_manager.save();
		this->window->welcome();
	}
	else {
		this->settings_manager.load();
		IP_INDEX = this->ip_address_list.indexOf(IP_ADDRESS); // Search for the loaded IP address in the list. If the IP address is not in the list, then it is an old IP that is no longer valid and IP_INDEX is set to -1
	}
}

bool Carrier_pigeon::set_up() {
	if (this->ip_address_list.isEmpty()) { // No network interfaces
		qDebug() << "Carrier_pigeon::set_up: no network interfaces";
		this->window->print_current_ip("Error: no network interfaces");
		this->window->disable_gui();

		return false;
	}
	else { // There is at least one network interface
		for (const auto &ip_address : this->ip_address_list) {
			this->window->get_settings()->print_ip_addresses(ip_address);
		}

		configure();
		this->window->print_current_ip(IP_ADDRESS);

		connect(this->window->get_settings(), SIGNAL(apply_settings(int, unsigned short, int)), this, SLOT(on_apply_settings(int, unsigned short, int)));
		return true;
	}
}

void Carrier_pigeon::start_up() {
	connect(this->window, SIGNAL(send_message(QString, QString)), this, SLOT(on_send_message(QString, QString)));
	connect(&this->server, SIGNAL(message_received(QString, QString)), this, SLOT(on_message_received(QString, QString)));
	connect(&this->client, SIGNAL(message_sent(QString)), this, SLOT(on_message_sent(QString)));

	if (this->server.start_listening()) this->window->print_console("Server listening...");
	else this->window->print_console("Error: server not listening");
}

void Carrier_pigeon::on_send_message(QString destination_string, QString message_string) {
	QHostAddress ip_address(destination_string);
	QByteArray outgoing_message = message_string.toUtf8();

	if (ip_address.protocol() == QAbstractSocket::IPv4Protocol) { // Valid IPv4 address
		qDebug() << "Carrier_pigeon::on_send_message: valid IPv4 address. Trying to connect to " << destination_string << "...";
		this->window->print_console("Trying to connect to " + destination_string + "...");
		this->client.send_message(ip_address, outgoing_message);
	}
	else qDebug() << "Carrier_pigeon::on_send_message: unknown or invalid IPv4 address";
}

void Carrier_pigeon::on_message_received(QString sender_string, QString message_string) {
	qDebug() << "Carrier_pigeon::on_message_received: message received";
	QString timestamp = QDateTime::currentDateTime().toString(Qt::ISODate);
	this->window->print_ingoing(sender_string, timestamp, message_string);
}

void Carrier_pigeon::on_message_sent(QString result_string) {
	this->window->print_console(result_string);
}

void Carrier_pigeon::on_apply_settings(int ip_index, unsigned short port, int timeout) {
	IP_INDEX = ip_index;
	IP_ADDRESS = this->ip_address_list.at(ip_index);
	PORT = port;
	TIMEOUT = timeout;

	this->settings_manager.save();
}
