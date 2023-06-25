#ifndef LOOP_H_SENTRY
#define LOOP_H_SENTRY

#include "ModBusTcp.h"
#include "DataBaseMySql.h"

class Loop {
	uint32_t loop_time_sec;
	ModBusTcp<uint16_t> * holdings;
	ModBusTcp<uint8_t> * coils;
	DataBaseMySql * dbmysql;
public:
	Loop
	(ModBusTcp<uint16_t> * h, ModBusTcp<uint8_t> * c,
	 DataBaseMySql * d, uint32_t lts)
	: holdings(h), coils(c), dbmysql(d), loop_time_sec(lts) {}
	void Run();
};

#endif
