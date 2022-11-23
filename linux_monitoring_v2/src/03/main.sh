#!/bin/bash/

. ./check_input
. ./check_empty_space
. ./create_folders
. ./create_files

check_input $@


free_space=$(check_empty_space)
if [[ $free_space == "Enough free space" ]]; then

	path=test
	folder_names=$1
	#create_folders $path $folder_names
	file_names=$2
	file_size=$3
	create_files $path $file_names $file_size
else
	echo "There isn't enough free space left"
	echo "Should be over 1GB left to run the script"
fi
