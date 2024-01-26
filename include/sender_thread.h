#ifndef SENDER_THREAD_H
#define SENDER_THREAD_H

#include <QThread>
#include <QHostAddress>
#include <QByteArray>
#include <QString>

class Sender_thread : public QThread {
	Q_OBJECT

private:
	QHostAddress ip_address;
	QByteArray outgoing_message;

public:
	Sender_thread(QHostAddress ip_address, QByteArray outgoing_message);
	virtual ~Sender_thread() override;
	void run() override;

signals:
	void message_sent(QString result_string);
};

#endif // SENDER_THREAD_H
