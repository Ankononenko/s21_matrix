#!/bin/bash

. ./sort_by_response_code

regex="../04/[0-9]{2}-[0-9]{2}-[0-9]{4}.log"

choice=$1

case $choice in

	1)
		name_of_dir="sorted_by_response_code"
		mkdir $name_of_dir

		for dir in ../04/*; do
			if [[ $dir =~ $regex ]]; then
			sort_by_response_code $dir $name_of_dir
		fi
	done
	;;

	2)
		echo "Second option"
	;;

esac	
