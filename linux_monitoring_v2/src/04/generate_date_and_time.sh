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
hour=$(( $RANDOM % $max_hour + 1))
hour=$(insert_zero $hour)
if [[ $hour == "$max_hour" ]]; then
	hour="00"
fi

max_minute=59
minute=$(( $RANDOM % $max_minute + 1))
minute=$(insert_zero $minute)

max_second=59
second=$(( $RANDOM % $max_second + 1))
second=$(insert_zero $second)

echo "$year-$month-$day $hour:$minute:$second"
