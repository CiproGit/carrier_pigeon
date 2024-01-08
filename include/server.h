#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QHostAddress>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>

class Server : public QObject {
	Q_OBJECT

private:
	QTcpServer server;
	QTcpSocket *socket;

private slots:
	void on_newConnection();
	void on_new_message();

public:
	Server();
	virtual ~Server();
	bool start_listening();

signals:
	void message_received(const QString sender_string, const QString message_string);
};

#endif // SERVER_H
