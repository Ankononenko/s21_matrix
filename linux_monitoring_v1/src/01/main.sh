#!/bin/bash

# If there is more than a one parameter, 
if [ ! -z "$2" ]
then
	echo "There should be only one parameter"
	exit 1
else
	# Flag -z returns true if the lenght of the string is zero
	# Here I use ! -z to return true if string is not empty
	if [ ! -z "$1" ]
	then
	# If input is a decimal number or a float output "Invalid input"
	# Positive or negative numbers considered
		if [[ $1 =~ ^[+-]?[0-9]+$ ]] || [[ $1 =~ ^[+-]?[0-9]+\.?[0-9]*$ ]]; then
			echo "Invalid input"
	# If input is text, output it's value
		else
			echo "Input parameter was: $1"
		fi
	# If there was no parameter
	else
		echo "No parameter was entered"
	fi
fi
