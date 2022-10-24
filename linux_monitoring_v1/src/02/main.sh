#!bin/bash

# Show hostname
echo "HOSTNAME = $HOSTNAME"

# Show timezone
echo "TIMEZONE = $(< /etc/timezone)"

# Show username
echo "USER = $USER"

# Show type and verson of the operating system
echo "OS = $(hostnamectl | grep -oP '(?<=Operating System: ).*')"

# Show date
echo "DATE = $(date '+%d %B %Y %H:%M:%S')"

# Display the system's uptime
echo "UPTIME = $(uptime -p)"

# Display the system's uptime in seconds
uptime=$(</proc/uptime)
uptime=${uptime%%.*}
echo "UPTIME_SEC = $uptime"

# Display the IP of the local machine
echo "IP = $(hostname -I)"
