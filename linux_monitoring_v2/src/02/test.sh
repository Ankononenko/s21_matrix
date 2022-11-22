#!/bin/bash

# find test -maxdepth 1 -mindepth 1 -type d -printf '%f\n'

for dir in $(find test -maxdepth 100 -mindepth 1 -type d); do
	if ! [[ $dir =~ \N*bin\N* ]]; then
		echo $dir;
	fi
done
