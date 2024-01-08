#include "client.h"
#include "sender_thread.h"
#include <QDebug>

Client::Client() {

}

Client::~Client() {

}

void Client::send_message(QHostAddress ip_address, QByteArray outgoing_message) const {
	Sender_thread *sender_thread = new Sender_thread(ip_address, outgoing_message);
	connect(sender_thread, &Sender_thread::finished, sender_thread, &QObject::deleteLater);
	connect(sender_thread, SIGNAL(message_sent(QString)), this, SIGNAL(message_sent(QString)));
	sender_thread->start();
}
