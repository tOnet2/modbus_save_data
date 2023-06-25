#include "DataBaseMySql.h"

DataBaseMySql::DataBaseMySql
(const char * ip_port, const char * user,
 const char * pass, const char * schema)
{
	d = sql::mysql::get_mysql_driver_instance();
	c = d->connect(ip_port, user, pass);
	if (c->isValid())
		c->setSchema(schema);
}

DataBaseMySql::~DataBaseMySql()
{
	delete c;
	delete ps;
}
