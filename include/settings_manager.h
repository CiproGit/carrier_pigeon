#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H

#include <QString>
#include <QSettings>

class Settings_manager {
private:
	const QString SETTINGS_FILE = "settings.ini";

	const QString IP_ADDRESS_HEADER = "CARRIER_PIGEON/IP_ADDRESS";
	const QString PORT_HEADER = "CARRIER_PIGEON/PORT";
	const QString TIMEOUT_HEADER = "CARRIER_PIGEON/TIMEOUT";

	QSettings *settings;

public:
	Settings_manager();
	virtual ~Settings_manager();
	void create(); // It creates the QSettings for the settings file
	void destroy(); // It destroys the QSettings
	bool exists() const; // It checks the existence of the settings file
	void save() const; // It saves IP address, port and timeout to the settings file
	void load() const; // It loads IP address, port and timeout from the settings file
};

#endif // SETTINGS_MANAGER_H
