cmake_minimum_required(VERSION 3.0)

project(MODBUS_SAVE_DATA LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 98)

set (SRC
	src/DataBaseMySql.cpp
	src/Loop.cpp
	src/ModBusTcp.cpp
	src/init_daemon.cpp
	src/init_logging.cpp
	src/main.cpp
	)

set (SRC_HEADERS
	src/DataBaseMySql.h
	src/Loop.h
	src/ModBusTcp.h
	src/init_daemon.h
	src/init_logging.h
	src/main.h
	)

set (CONF
	src/config.h
	)

add_executable(exe ${SRC} ${SRC_HEADERS} ${CONF})
target_link_libraries(exe PRIVATE mysqlcppconn modbus)
