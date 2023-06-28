#include "DataBaseMySql.h"

DataBaseMySql::DataBaseMySql
(const char * ip_port, const char * user,
 const char * pass, const char * schema)
{
<<<<<<< HEAD
	d = sql::mysql::get_mysql_driver_instance();
	c = d->connect(ip_port, user, pass);
	if (c->isValid())
		c->setSchema(schema);
=======
	try {
		d = sql::mysql::get_mysql_driver_instance();
		c = d->connect(ip_port, user, pass);
		c->setSchema(schema);
	} catch (sql::SQLException &e) {
		std::string error_str = e.what();
		syslog(LOG_CRIT, "DataBaseMySql constructor: %s", error_str.c_str());
		exit(EXIT_FAILURE);
	}
>>>>>>> 134f1da (upd)
}

DataBaseMySql::~DataBaseMySql()
{
<<<<<<< HEAD
	delete c;
	delete ps;
=======
	if (c)
		delete c;
	if (ps)
		delete ps;
>>>>>>> 134f1da (upd)
}
