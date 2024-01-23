#include "settings_manager.h"
#include "common.h"
#include <QFile>
#include <QDebug>

Settings_manager::Settings_manager() {
	this->settings = nullptr;
}

Settings_manager::~Settings_manager() {
	delete this->settings;
}

void Settings_manager::create() {
	this->settings = new QSettings(SETTINGS_FILE, QSettings::IniFormat);
	qDebug() << "Settings_manager::create: settings in " << SETTINGS_FILE << "file";
}

void Settings_manager::destroy() {
	delete this->settings;
	this->settings = nullptr;
}

bool Settings_manager::exists() const {
	return QFile::exists(SETTINGS_FILE);
}

void Settings_manager::save() const {
	this->settings->setValue(IP_ADDRESS_HEADER, IP_ADDRESS);
	this->settings->setValue(PORT_HEADER, PORT);
	this->settings->setValue(TIMEOUT_HEADER, TIMEOUT);
	qDebug() << "Settings_manager::save: settings saved";
}

void Settings_manager::load() const {
	IP_ADDRESS = this->settings->value(IP_ADDRESS_HEADER, DEFAULT_IP_ADDRESS).toString();
	PORT = this->settings->value(PORT_HEADER, DEFAULT_PORT).toUInt();
	TIMEOUT = this->settings->value(TIMEOUT_HEADER, DEFAULT_TIMEOUT).toUInt();
	qDebug() << "Settings_manager::load: settings loaded";
}
