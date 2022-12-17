#!/bin/bash

function scrape_cpu {
	sum=0
	echo "cpu_used_in_percent $(ps -eo pcpu | awk '{s+=$1} END {print s}')" >> metrics.html
}
