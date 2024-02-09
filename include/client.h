#ifndef CLIENT_H
#define CLIENT_H

#include <QHostAddress>
#include <QByteArray>
#include <QString>

class Client : public QObject {
	Q_OBJECT

public:
	Client();
	virtual ~Client();
	void send_message(QHostAddress ip_address, QByteArray outgoing_message) const; // It creates a thread to send the given message to the given IP address

signals:
	void message_sent(QString result_string);
};

#endif // CLIENT_H
