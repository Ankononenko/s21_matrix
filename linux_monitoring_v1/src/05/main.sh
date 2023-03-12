#!/bin/bash

start=`date +%s.%N`

. ./check_input
. ./display_info

# Execution time of the script
end=`date +%s.%N`
total_time=$(echo "$end-$start" | bc -l)
format_total_time=$(printf "%0.1lf" $total_time)
echo "Script execution time (in seconds) = $format_total_time"
