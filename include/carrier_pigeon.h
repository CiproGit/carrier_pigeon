#ifndef CARRIER_PIGEON_H
#define CARRIER_PIGEON_H

#include "main_window.h"
#include "server.h"
#include "client.h"
#include "settings_manager.h"
#include <QString>
#include <QList>

class Carrier_pigeon : public QObject {
	Q_OBJECT

private:
	Main_window *window; // GUI
	QList<QString> ip_address_list; // List of all host IP addresses (loopback and IPv6 excluded)

	Server server;
	Client client;

	Settings_manager settings_manager; // To save and load IP, port and timeout settings

	QList<QString> get_address_list(); // It gets the list of all host IP addresses (loopback and IPv6 excluded)
	void configure(); // It creates settings file if it doesn't exist and configures IP address, port and timeout

private slots:
	void on_send_message(QString destination_string, QString message_string);
	void on_message_received(QString sender_string, QString message_string);
	void on_message_sent(QString result_string);
	void on_apply_settings(int ip_index, unsigned short port, int timeout);

public:
	Carrier_pigeon(Main_window *window);
	virtual ~Carrier_pigeon();
	bool set_up();
	void start_up();
};

#endif // CARRIER_PIGEON_H
