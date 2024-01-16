#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QHostAddress>
#include <QByteArray>
#include <QString>

class Client : public QObject {
	Q_OBJECT

private:	

public:
	Client();
	virtual ~Client();
	void send_message(QHostAddress ip_address, QByteArray outgoing_message) const;

signals:
	void message_sent(const QString result_string);
};

#endif // CLIENT_H
