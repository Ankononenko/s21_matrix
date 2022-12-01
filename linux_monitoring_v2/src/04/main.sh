#!/bin/bash

. ./generate_date_and_time
. ./generate_ip

#generate_date_and_time
#generate_ip

max_repetitions=1000
min_repetitions=100
diff_repetitions=$max_repetitions-$min_repetitions
number_of_lines=$(( $RANDOM % $diff_repetitions + $min_repetitions ))
if [[ $number_of_lines -lt $min_repetitions ]]; then
	number_of_lines=100
fi

for (( repetitions = 0; repetitions <= $number_of_lines; ++repetitions )); do
	hour_s=$(insert_zero $hour)
	if [[ $hour_s == "$max_hour" ]]; then
		hour_s="00"
	fi
	minute_s=$(insert_zero $minute)
	second_s=$(insert_zero $second)

	ip=$(generate_ip)
	
	echo "$year-$month-$day $hour_s:$minute_s:$second_s $ip"
	max_step_for_the_clock=60
	second=$(( $RANDOM % $max_step_for_the_clock + 1 + $second ))
	if [[ $second -gt $max_second ]]; then
		second=0
		((++minute))
	fi
	if [[ $minute -gt $max_minute ]]; then
		minute=0
		((++hour))
	fi
	if [[ $hour -eq $max_hour ]]; then
		break;
	fi
done

echo "Total num of lines: $number_of_lines"
