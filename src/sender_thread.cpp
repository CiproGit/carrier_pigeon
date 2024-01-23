#include "sender_thread.h"
#include "common.h"
#include <QDebug>
#include <QTcpSocket>

Sender_thread::Sender_thread(QHostAddress ip_address, QByteArray outgoing_message) {
	this->ip_address = ip_address;
	this->outgoing_message = outgoing_message;
}

Sender_thread::~Sender_thread() = default;

void Sender_thread::run() {
	QTcpSocket *socket = new QTcpSocket();
	socket->connectToHost(this->ip_address, PORT);

	QString result_string;

	if (socket->waitForConnected(TIMEOUT)) {
		qDebug() << "Sender_thread::run: connected to " << this->ip_address;

		if (socket->write(this->outgoing_message) != -1) {
			qDebug() << "Sender_thread::run: message sent";
			result_string = "Message sent";
		}
		else {
			qDebug() << "Sender_thread::run: message not sent";
			result_string = "Error: message not sent";
		}
	}
	else {
		qDebug() << "Sender_thread::run:" << socket->errorString();
		result_string = socket->errorString();
	}

	//delete socket;
	emit message_sent(result_string);
	exec();
}
