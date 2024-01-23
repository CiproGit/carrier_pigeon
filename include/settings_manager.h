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
	void create();
	void destroy();
	bool exists() const;
	void save() const;
	void load() const;
};

#endif // SETTINGS_MANAGER_H
