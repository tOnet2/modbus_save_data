#!/bin/bash

kill -15 $(./check_log.sh | tail -1 | sed 's|.*\[||' | sed -r 's/\].+//')
