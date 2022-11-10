#!/bin/bash/

. ./check_input

check_result=$( check_input $@ )
echo $check_result

sum_result=$((check_result+check_result))
echo $sum_result
