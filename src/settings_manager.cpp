#include "settings_manager.h"
#include "common.h"
#include <QDebug>

Settings_manager::Settings_manager() {
	qDebug() << "Settings_manager::Settings_manager: settings located in" << this->settings.fileName();
}

Settings_manager::~Settings_manager() = default;

bool Settings_manager::check_first_run() {
	bool first_run = this->settings.value(FIRST_RUN_HEADER, DEFAULT_FIRST_RUN).toBool();
	this->settings.setValue(FIRST_RUN_HEADER, false); // It is no longer the first launch of the application

	return first_run;
}

void Settings_manager::save() {
	this->settings.setValue(IP_ADDRESS_HEADER, IP_ADDRESS);
	this->settings.setValue(PORT_HEADER, PORT);
	this->settings.setValue(TIMEOUT_HEADER, TIMEOUT);
	qDebug() << "Settings_manager::save: settings saved";
}

void Settings_manager::load() {
	IP_ADDRESS = this->settings.value(IP_ADDRESS_HEADER, DEFAULT_IP_ADDRESS).toString();
	PORT = this->settings.value(PORT_HEADER, DEFAULT_PORT).toUInt();
	TIMEOUT = this->settings.value(TIMEOUT_HEADER, DEFAULT_TIMEOUT).toUInt();
	qDebug() << "Settings_manager::load: settings loaded";
}
