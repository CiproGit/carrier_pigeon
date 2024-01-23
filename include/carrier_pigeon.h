#ifndef CARRIER_PIGEON_H
#define CARRIER_PIGEON_H

#include "main_window.h"
#include "server.h"
#include "client.h"
#include "settings_manager.h"
#include <QString>
#include <QList>
#include <QHostAddress>

class Carrier_pigeon : public QObject {
	Q_OBJECT

private:
	Main_window *window; // GUI
	QList<QHostAddress> ip_address_list; // List of all host IP addresses (loopback and IPv6 excluded)

	Server server;
	Client client;

	Settings_manager settings_manager;

	QList<QHostAddress> get_address_list(); // Get the list of all host IP addresses (loopback and IPv6 excluded)
	void configure();

public:
	Carrier_pigeon(Main_window *window);
	virtual ~Carrier_pigeon();
	bool set_up();
	void start_up();

public slots:
	void on_send_message(QString destination_string, QString message_string);
	void on_message_received(QString sender_string, QString message_string);
	void on_message_sent(QString result_string);
	void on_apply_settings(int ip_index);
};

#endif // CARRIER_PIGEON_H
