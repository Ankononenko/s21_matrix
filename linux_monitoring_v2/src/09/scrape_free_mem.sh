#!/bin/bash

function scrape_free_mem {
	echo "free_mem_in_bytes $(free -b | awk 'NR==2{print $4}')" >> metrics.html
}
