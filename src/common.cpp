#include "common.h"

const int IP_NOT_AVAILABLE = -1;

const QString DEFAULT_IP_ADDRESS = "127.0.0.1";
const unsigned short DEFAULT_PORT = 50000;
const int DEFAULT_TIMEOUT = 10000; // 10 s

int IP_INDEX = IP_NOT_AVAILABLE;

QString IP_ADDRESS = DEFAULT_IP_ADDRESS;
unsigned short PORT = DEFAULT_PORT;
int TIMEOUT = DEFAULT_TIMEOUT;
