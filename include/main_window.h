#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "about.h"
#include "settings.h"
#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Main_window; }
QT_END_NAMESPACE

class Main_window : public QMainWindow {
	Q_OBJECT

private:
	Ui::Main_window *ui;
	About about;
	Settings settings;

private slots:
	void on_send();

public:
	Main_window(QWidget *parent = nullptr);
	~Main_window();
	Settings *get_settings();
	void disable_gui() const;
	void welcome() const; // It shows the chosen IP address
	void print_current_ip(QString string) const; // It prints the given string in the IP address panel
	void print_console(QString string) const; // It appends the given string in the console panel
	void print_ingoing(QString sender_string, QString timestamp, QString message_string) const; // It prints the ingoing message with date, time and sender in the ingoing messages panel

public slots:
	void show_about();
	void show_settings();

signals:
	void send_message(QString destination_string, QString message_string);
};

#endif // MAIN_WINDOW_H
