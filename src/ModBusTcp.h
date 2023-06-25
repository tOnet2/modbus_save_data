#ifndef MB_H_SENTRY
#define MB_H_SENTRY

#include <inttypes.h>
#include <modbus/modbus.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <syslog.h>

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
	if (modbus_connect(mbcon) < -1) {
		fprintf(stderr, "ModBus: %s", modbus_strerror(errno));
		exit(1);
	}
	modbus_set_response_timeout(mbcon, rt_sec, rt_usec);
}

template <class T>
ModBusTcp<T>::~ModBusTcp()
{
	modbus_close(mbcon);
	modbus_free(mbcon);
}

template <class T>
void ModBusTcp<T>::EraseRes()
{
	size_t i;
	last_res_amount = 0;
	for (i = 0; i < RES_SIZE; i++)
		res[i] = 0;
}

#endif
