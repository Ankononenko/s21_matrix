#!/bin/bash

num_to_insert_zeros=9
function insert_zero(){
	zero_inserted=$1
	if [[ $1 -le num_to_insert_zeros ]]; then
		zero_inserted="0$1"
	fi
	echo $zero_inserted
}

min_year=1970
max_year=2022
diff=max_year-min_year
year=$(( $RANDOM % diff + min_year ))

max_month=12
month=$(( $RANDOM % max_month  + 1 ))
leap_year=$(( year % 4 ))
month=$(insert_zero $month)
month_without_zero=${month#0}
if [[ $month_without_zero  -eq 1 ]] || [[ $month_without_zero -eq 3 ]] || [[ $month_without_zero -eq 5 ]] || [[ $month_without_zero -eq 7 ]] || [[ $month_without_zero -eq 8 ]] || [[ $month_without_zero -eq 10 ]] || [[ $month_without_zero -eq 12 ]]; then
	max_day=31
elif [[ $month_without_zero -eq 4 ]] || [[ $month_without_zero -eq 6 ]] || [[ $month_without_zero -eq 9 ]] || [[ $month_without_zero -eq 11 ]]; then
	max_day=30
elif [[ $leap_year -eq 0 ]] && [[ $month_without_zero -eq 2 ]]; then
	max_day=29
elif [[ $leap_year -ne 0 ]] && [[ $month_without_zero -eq 2 ]]; then
	max_day=28
fi

day=$(( $RANDOM % $max_day + 1 ))
day=$(insert_zero $day)

max_hour=24
hour=$(( $RANDOM % 24))

max_minute=59
max_start_minute=42
minute=$(( $RANDOM % $max_start_minute + 1))

max_second=59
second=$(( $RANDOM % $max_second + 1))


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
	echo "$year-$month-$day $hour_s:$minute_s:$second_s"
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
