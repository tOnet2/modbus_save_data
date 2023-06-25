#!/bin/bash

cat /var/log/syslog | grep modbus-save-data | tail -20
