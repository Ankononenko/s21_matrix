#!/bin/bash

. ./display_info
display_info

white_font='\033[0;37m'
white_bg='\033[0;47m'
red_font='\033[031;m'
red_bg='\033[041;m'
green_font='\033[032;m'
green_bg='\033[042;m'
blue_font='\033[034;m'
blue_bg='\033[044;m'
purple_font='\033[035;m'
purple_bg='\033[045;m'
black_font='\033[030;m'
black_bg='\033[040;m'

clear='\033[0m'

case $1 in
	1)
		background_value_names=$white_bg
		printf "${background_value_names}Test${clear}\n"
		printf "${white_bg}Test${clear}\n"
		;;
	2)
		echo 2
		;;
	3)
		echo 3
		;;
	*)
		echo "unknown"
		;;
esac
