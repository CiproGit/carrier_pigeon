#include "server.h"
#include "common.h"
#include <QDebug>
#include <QHostAddress>
#include <QByteArray>

Server::Server() {
	connect(&this->server, SIGNAL(newConnection()), this, SLOT(on_newConnection()));

	this->socket = nullptr;
}

Server::~Server() {
	this->server.close();
	qDebug() << "Server::~Server: server closed";
}

void Server::on_newConnection() {
	this->socket = this->server.nextPendingConnection();
	connect(this->socket, SIGNAL(readyRead()), this, SLOT(on_new_message()));
	connect(this->socket, &QAbstractSocket::disconnected, this->socket, &QObject::deleteLater);
}

void Server::on_new_message() {
	QByteArray ingoing_message = this->socket->readAll();
	QHostAddress ip_address = this->socket->peerAddress();
	this->socket->close();

	QString sender_string = ip_address.toString();
	QString message_string = QString(ingoing_message);

	emit message_received(sender_string, message_string);
}

 bool Server::start_listening() {
	 if (this->server.listen(QHostAddress(IP_ADDRESS), PORT)) {
		qDebug() << "Server::start_listening: server listening...";
		return true;
	}
	else {
		qDebug() << "Server::start_listening: server not listening";
		return false;
	}
}
