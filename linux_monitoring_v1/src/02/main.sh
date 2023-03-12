#!/bin/bash

. ./display_info
display_info

read -p "Do you want to save the data to a file? (Y/N)" input


if [[ $input = y ]] || [[ $input = Y ]]
then
	file=$(date +'%d_%m_%y_%H_%M_%S.txt')
	touch $file
	display_info > "$file"
	echo "File saved"
else
	echo "File wasn't saved"
fi
