#!/bin/bash

. ./display_info

white_font='37'
white_bg='47'
red_font='31'
red_bg='41'
green_font='32'
green_bg='42'
blue_font='34'
blue_bg='44'
purple_font='35'
purple_bg='45'
black_font='30'
black_bg='40'

case $1 in
	1)
		bg1=$white_bg
		;;
	2)
		bg1=$red_bg
		;;
	3)
		bg1=$green_bg
		;;
	4)
		bg1=$blue_bg
		;;
	5)
		bg1=$purple_bg
		;;
	6)
		bg1=$black_bg
		;;
esac

case $2 in
	1)
		f1=$white_font
		;;
	2)
		f1=$red_font
		;;
	3)
		f1=$green_font
		;;
	4)
		f1=$blue_font
		;;
	5)
		f1=$purple_font
		;;
	6)
		f1=$black_font
		;;
esac


case $3 in
	1)
		bg2=$white_bg
		;;
	2)
		bg2=$red_bg
		;;
	3)
		bg2=$green_bg
		;;
	4)
		bg2=$blue_bg
		;;
	5)
		bg2=$purple_bg
		;;
	6)
		bg2=$black_bg
		;;
esac


case $4 in
	1)
		f2=$white_font
		;;
	2)
		f2=$red_font
		;;
	3)
		f2=$green_font
		;;
	4)
		f2=$blue_font
		;;
	5)
		f2=$purple_font
		;;
	6)
		f2=$black_font
		;;
esac

#clear='\033[0m'
#printf "\033[0;${f1};${bg1}mFinal test${clear}\n"
#echo -e "\033[9;${f2};${bg2}mTest test${clear}\n"

display_info
