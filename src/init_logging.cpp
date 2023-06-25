#include "init_logging.h"

void start_logging()
{
	openlog("modbus-save-data", LOG_PID, 0);
	syslog(LOG_INFO, "ModBus save data daemon started");
}
