#include "main_window.h"
#include "carrier_pigeon.h"
#include <QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	QCoreApplication::setOrganizationName("Cipro");
	QCoreApplication::setOrganizationDomain("cipro.com");
	QCoreApplication::setApplicationName(APPLICATION_NAME);

	Main_window w;
	w.show();

	Carrier_pigeon carrier_pigeon(&w);
	if (carrier_pigeon.set_up()) carrier_pigeon.start_up();

	return a.exec();
}
