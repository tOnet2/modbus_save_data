#include "main.h"

int32_t main(int32_t argc, char ** argv)
{
	ModBusTcp<uint8_t> * coils = new ModBusTcp<uint8_t>
		(MB_IP, MB_PORT, MB_START_COILS, MB_AMOUNT_COILS,
		 MB_TIMEOUT_USEC, MB_TIMEOUT_SEC);

	ModBusTcp<uint16_t> * holdings = new ModBusTcp<uint16_t>
		(MB_IP, MB_PORT, MB_START_HOLDINGS, MB_AMOUNT_HOLDINGS,
		 MB_TIMEOUT_USEC, MB_TIMEOUT_SEC);

	DataBaseMySql * dbmysql =
		new DataBaseMySql(DB_IP_PORT, DB_USER, DB_PASS, DB_SCHEMA);

	start_process_as_daemon();

	Loop * loop = new Loop(holdings, coils, dbmysql, LOOP_TIME_SEC);
	loop->Run();
	exit(EXIT_SUCCESS);
}
