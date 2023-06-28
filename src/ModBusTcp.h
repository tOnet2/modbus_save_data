#ifndef MB_H_SENTRY
#define MB_H_SENTRY

#include <inttypes.h>
#include <modbus/modbus.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <syslog.h>
<<<<<<< HEAD
=======
#include <string.h>
#include <unistd.h>
>>>>>>> 134f1da (upd)

#define RES_SIZE 256

template <class T>
class ModBusTcp {
	modbus_t * mbcon;
	uint16_t start;
	uint16_t amount;
	T res[256];
	int32_t last_res_amount;
public:
	ModBusTcp
	(const char * ip, uint16_t port, uint16_t s, uint16_t a,
	 uint32_t rt_usec, uint32_t rt_sec);
	~ModBusTcp();
	inline T * GetRes() { return res; }
	inline int32_t GetLastResAmount() const { return last_res_amount; }
	inline uint16_t GetStart() const { return start; }
	inline uint16_t GetAmount() const { return amount; }
	void EraseRes();
	bool ReadInputs();
	bool ReadOutputs();
private:
	ModBusTcp(const ModBusTcp&) {}
};

template <class T>
ModBusTcp<T>::ModBusTcp
(const char * ip, uint16_t port, uint16_t s, uint16_t a,
 uint32_t rt_usec, uint32_t rt_sec)
	: start(s), amount(a)
{
	mbcon = modbus_new_tcp(ip, port);
<<<<<<< HEAD
	if (modbus_connect(mbcon) < -1) {
		fprintf(stderr, "ModBus: %s", modbus_strerror(errno));
		exit(1);
=======
	int32_t mc_r;
	if (mbcon == NULL) {
		syslog(LOG_CRIT, "ModBus new tcp: %s\n", modbus_strerror(errno));
		exit(EXIT_FAILURE);
	}
	mc_r = modbus_connect(mbcon);
	while (mc_r < 0) {
		syslog(LOG_CRIT, "ModBus connect: %s\n", modbus_strerror(errno));
		if (errno == ECONNREFUSED) {
			errno = 0;
			mc_r = modbus_connect(mbcon);
			sleep(5);
		} else
			exit(EXIT_FAILURE);
>>>>>>> 134f1da (upd)
	}
	modbus_set_response_timeout(mbcon, rt_sec, rt_usec);
}

template <class T>
ModBusTcp<T>::~ModBusTcp()
{
<<<<<<< HEAD
	modbus_close(mbcon);
	modbus_free(mbcon);
=======
	if (mbcon) {
		modbus_close(mbcon);
		modbus_free(mbcon);
	}
>>>>>>> 134f1da (upd)
}

template <class T>
void ModBusTcp<T>::EraseRes()
{
	size_t i;
	last_res_amount = 0;
<<<<<<< HEAD
	for (i = 0; i < RES_SIZE; i++)
		res[i] = 0;
=======
	for (i = 0; i < last_res_amount; i++)
		res[i] = 0;
	last_res_amount = 0;
>>>>>>> 134f1da (upd)
}

#endif
