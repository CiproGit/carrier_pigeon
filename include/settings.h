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

	void select_ip_address() const; // It highlights the current IP address, if available

private slots:
	void on_cancel();
	void on_ok();

protected:
	void showEvent(QShowEvent *event) override;

public:
	Settings(QWidget *parent = nullptr);
	~Settings();
	void print_ip_addresses(QString string) const; // It appends the given string in the IP addresses panel

signals:
	void apply_settings(int ip_index, unsigned short port, int timeout);
};

#endif // SETTINGS_H
