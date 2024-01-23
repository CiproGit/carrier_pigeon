#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QString>

namespace Ui {
	class Settings;
}

class Settings : public QDialog {
	Q_OBJECT

private:
	Ui::Settings *ui;

private slots:
	void on_cancel();
	void on_ok();

public:
	Settings(QWidget *parent = nullptr);
	~Settings();
	void print_ip_addresses(QString string) const; // It appends the given string in the IP addresses panel
	void select_ip_address(int ip_index) const; // It highlights the ip address with the given index

signals:
	void apply_settings(const int ip_index);
};

#endif // SETTINGS_H
