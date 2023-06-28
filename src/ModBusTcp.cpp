#include "ModBusTcp.h"

template <>
bool ModBusTcp<uint16_t>::ReadInputs()
{
	 last_res_amount =
		 modbus_read_input_registers(mbcon, start, amount, res);
	 if (last_res_amount < 0) {
		 syslog(LOG_INFO, "ModBusTcp read input holdings: %s",
				 modbus_strerror(errno));
		 return false;
<<<<<<< HEAD
=======
		 last_res_amount = 0;
>>>>>>> 134f1da (upd)
	 }
	 return true;
}

template <>
bool ModBusTcp<uint16_t>::ReadOutputs()
{
	last_res_amount = 
		modbus_read_registers(mbcon, start, amount, res);
	 if (last_res_amount < 0) {
		 syslog(LOG_INFO, "ModBusTcp read output holdings: %s",
				 modbus_strerror(errno));
		 return false;
<<<<<<< HEAD
=======
		 last_res_amount = 0;
>>>>>>> 134f1da (upd)
	 }
	 return true;
}

template <>
bool ModBusTcp<uint8_t>::ReadInputs()
{
	last_res_amount =
		modbus_read_input_bits(mbcon, start, amount, res);
	if (last_res_amount < 0) {
		syslog(LOG_INFO, "ModBusTcp read input coils: %s",
				modbus_strerror(errno));
		return false;
<<<<<<< HEAD
=======
		last_res_amount = 0;
>>>>>>> 134f1da (upd)
	}
	return true;
}

template <>
bool ModBusTcp<uint8_t>::ReadOutputs()
{
	last_res_amount =
		modbus_read_input_bits(mbcon, start, amount, res);
	if (last_res_amount < 0) {
		syslog(LOG_INFO, "ModBusTcp read output coils: %s",
				modbus_strerror(errno));
		return false;
<<<<<<< HEAD
=======
		last_res_amount = 0;
>>>>>>> 134f1da (upd)
	}
	return true;
}
