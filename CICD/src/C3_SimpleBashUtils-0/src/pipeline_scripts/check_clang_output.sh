#!/ bin / bash

if [ -s clang_output.txt ];
then
	exit 1
else
	echo "No style errors were found"
	echo "Code is clang-formatted"
fi
