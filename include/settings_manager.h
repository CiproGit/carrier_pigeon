#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H

#include <QString>
#include <QSettings>

class Settings_manager {
private:
	const QString FIRST_RUN_HEADER = "CARRIER_PIGEON/FIRST_RUN";
	const bool DEFAULT_FIRST_RUN = true;

	const QString IP_ADDRESS_HEADER = "CARRIER_PIGEON/IP_ADDRESS";
	const QString PORT_HEADER = "CARRIER_PIGEON/PORT";
	const QString TIMEOUT_HEADER = "CARRIER_PIGEON/TIMEOUT";

	QSettings settings;

public:
	Settings_manager();
	virtual ~Settings_manager();
	bool check_first_run(); // It checks if the application is launched for the first time and it updates the state in the settings file
	void save(); // It saves IP address, port and timeout to the settings file
	void load(); // It loads IP address, port and timeout from the settings file
};

#endif // SETTINGS_MANAGER_H
