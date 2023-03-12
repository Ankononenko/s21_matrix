#!/bin/bash

FILE=config

if [ -f "$FILE" ]
then

	source $FILE

	. ./pick_color
	. ./check_color
	. ./display_os_info
	. ./display_color_info
else
	echo "Configuration file doesn't exist"
fi

