#!/bin/bash/

. ./check_input
. ./check_empty_space
. ./create_folders

check_input $@


free_space=$(check_empty_space)
if [[ $free_space == "Enough free space" ]]; then

	num_folders=$2
	folder_names=$3
	create_folders $num_folders $folder_names
else
	echo "There isn't enough free space left"
	echo "Should be over 1GB left to run the script"
fi
