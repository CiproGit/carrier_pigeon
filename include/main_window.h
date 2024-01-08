#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Main_window; }
QT_END_NAMESPACE

class Main_window : public QMainWindow {
	Q_OBJECT

private:
	Ui::Main_window *ui;

private slots:
	void on_clicked();

public:
	Main_window(QWidget *parent = nullptr);
	~Main_window();
	void disable_gui() const;
	void print_ip_addresses(QString string) const; // It appends the given string in the IP addresses panel
	void print_console(QString string) const; // It appends the given string in the console panel
	void print_ingoing(QString sender_string, QString timestamp, QString message_string) const; // It prints the ingoing message with date, time and sender in the ingoing messages panel

signals:
	void send_message(const QString destination_string, const QString message_string);
};

#endif // MAIN_WINDOW_H
