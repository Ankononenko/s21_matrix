#!/ bin / bash

if [ -f "../cat/log.txt" ];
then
	if [ -z "$(cat ../cat/log.txt)" ];
	then
		echo "Tests for cat utility have passed successfully"
	else
		echo "Tests for cat utility have failed"
		echo "List of failed tests:"
		cat ../cat/log.txt
		exit 1
	fi
else
	echo "Log file for cat tests doesn't exist"
	echo "Run the tests first - make test_cat"
	exit 1
fi


if [ -f "../grep/log.txt" ];
then
	if [ -z "$(cat ../grep/log.txt)" ];
	then
		echo "Tests for grep utility have passed successfully"
	else
		echo "Tests for grep utility have failed"
		echo "List of failed tests:"
		cat ../grep/log.txt
		exit 1
	fi
else
	echo "Log file for grep tests doesn't exist"
	echo "Run the tests first - make test_grep"
	exit 1
fi
