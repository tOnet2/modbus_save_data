#ifndef DATABASEMYSQL_H_SENTRY
#define DATABASEMYSQL_H_SENTRY

#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

class DataBaseMySql {
	sql::Connection *c;
	sql::Driver *d;
	sql::PreparedStatement *ps;
public:
	DataBaseMySql
	(const char * ip_port, const char * user,
	 const char * pass, const char * schema);
	~DataBaseMySql();

	template <class T>
	bool InsertInputs
	(T * data, int32_t len, uint16_t start, uint16_t amount);

	template <class T>
	bool InsertOutputs
	(T * data, int32_t len, uint16_t start, uint16_t amount);
private:
	DataBaseMySql(const DataBaseMySql &) {}
};

template <class T>
bool DataBaseMySql::InsertInputs
(T * data, int32_t len, uint16_t start, uint16_t amount)
{
	if (len < 1)
		return false;
	std::string d;
	d.assign((char *) data, (char *) data + sizeof(T) * len);
	if (sizeof(T) == 2)
		ps = c->prepareStatement
			("insert into input_holdings (start, amount, data) values (?, ?, ?)");
	else
		ps = c->prepareStatement
			("insert into input_coils (start, amount, data) values (?, ?, ?)");
	ps->setUInt(1, start);
	ps->setUInt(2, amount);
	ps->setString(3, d);
	ps->execute();
	return true;
}

template <class T>
bool DataBaseMySql::InsertOutputs
(T *data, int32_t len, uint16_t start, uint16_t amount)
{
	if (len < 1)
		return false;
	std::string d;
	d.assign((char *) data, (char *) data + sizeof(T) * len);
	if (sizeof(T) == 2)
		ps = c->prepareStatement
			("insert into output_holdings (start, amount, data) values (?, ?, ?)");
	else
		ps = c->prepareStatement
			("insert into output_coils (start, amount, data) values (?, ?, ?)");
	ps->setUInt(1, start);
	ps->setUInt(2, amount);
	ps->setString(3, d);
	ps->execute();
	return true;
}

#endif
