#!/bin/bash

. ./display_info

white_font='\033[0;37;'
white_bg='47m'
red_font='\033[0;31;'
red_bg='41m'
green_font='\033[0;32;'
green_bg='42m'
blue_font='\033[0;34;'
blue_bg='44m'
purple_font='\033[0;35;'
purple_bg='45m'
black_font='\033[0;30;'
black_bg='40m'

bg1_result=0
f1_result=0
bg2_result=0
f2_result=0

case $1 in
	1)
		bg1=$white_bg
		bg1_result=1
		;;
	2)
		bg1=$red_bg
		bg1_result=2
		;;
	3)
		bg1=$green_bg
		bg1_result=3
		;;
	4)
		bg1=$blue_bg
		bg1_result=4
		;;
	5)
		bg1=$purple_bg
		bg1_result=5
		;;
	6)
		bg1=$black_bg
		bg1_result=6
		;;
esac

case $2 in
	1)
		f1=$white_font
		f1_result=1
		;;
	2)
		f1=$red_font
		f1_result=2
		;;
	3)
		f1=$green_font
		f1_result=3
		;;
	4)
		f1=$blue_font
		f1_result=4
		;;
	5)
		f1=$purple_font
		f1_result=5
		;;
	6)
		f1=$black_font
		f1_result=6
		;;
esac


case $3 in
	1)
		bg2=$white_bg
		bg2_result=1
		;;
	2)
		bg2=$red_bg
		bg2_result=2
		;;
	3)
		bg2=$green_bg
		bg2_result=3
		;;
	4)
		bg2=$blue_bg
		bg2_result=4
		;;
	5)
		bg2=$purple_bg
		bg2_result=5
		;;
	6)
		bg2=$black_bg
		bg2_result=6
		;;
esac


case $4 in
	1)
		f2=$white_font
		f2_result=1
		;;
	2)
		f2=$red_font
		f2_result=2
		;;
	3)
		f2=$green_font
		f2_result=3
		;;
	4)
		f2=$blue_font
		f2_result=4
		;;
	5)
		f2=$purple_font
		f2_result=5
		;;
	6)
		f2=$black_font
		f2_result=6
		;;
esac

# If there are more parameters than 4 or one of the four parameters don't exist
if [ ! -z "$5" ] || [ -z "$1" ] || [ -z "$2" ] || [ -z "$3" ] || [ -z "$4" ]
then 
	echo "There should be only 4 colors. No more, no less"
	exit
fi

if [ $f1_result = $bg1_result ] || [ $f2_result = $bg2_result ]
then
	echo "Font color can't be the same as the background color - you won't be able to read text"
	echo "Also font color should be only a number"
	echo "Run the script again? (Y/N)"
	read answer

	if [ $answer = y ] || [ $answer = Y ]
	then
		# Shoud replace that part of code - clean the previous colors and ask the input again
		printf "\033[0m"
		read -p "Please enter the color for the output again"  bg1 f1 bg2 f2

	else
		exit
	fi

fi

if [ $f1_result = 0 ] || [ $f2_result = 0 ] || [ $bg1_result = 0 ] || [ $bg2_result = 0 ]
then
	echo "Values of color should be in range of 1-6"
	echo "Where 1 - white, 2 - ted, 3 - green, 4 - blue, 5 - purple, 5 - black"
	exit
fi

display_info
