#!/bin/bash

function scrape_free_hd_space {
	echo "free_hd_space_in_bytes $(df -B1 /home | awk 'NR==2{print $4}')" >> metrics.html
}
