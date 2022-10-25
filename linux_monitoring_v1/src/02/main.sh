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

# Get the network mask
echo "MASK = $( ifconfig | grep -m2 'inet '| awk '{ if (NR==2) printf $4}' )"

# Display the default gateway
echo "GATEWAY = $( ip n | awk '{print $1 }' )"

# Display the total RAM in GB with three decimal places
echo "RAM_TOTAL = $( free -m | awk 'sub(/Mem:/,""){printf("%.3f\n",$1 / 1024) }' ) GB"

# Display the used RAM in GBs with three decimal places
echo "RAM_USED = $( free -m | awk 'sub(/Mem:/,""){printf("%.3f\n",$2 /1024) }' ) GB"

# Display the free RAM in GBs with three decimal places
echo "RAM_FREE = $( free -m | awk 'sub(/Mem:/,""){printf("%.3f\n",$3 / 1024) }' ) GB"

# Display the size of the root partion in MBs with two decimal spaces
echo "SPACE_ROOT = $( df -hk / | awk 'sub(/dev/,""){printf("%.2f\n",$2 / 1024) }' ) MB"

# Display the used space of the root partion in MBs with two decimal places
echo "SPACE_ROOT_USED = $( df -hk / | awk 'sub(/dev/,""){printf("%.2f",$3 / 1024) }' ) MB"

# Display the free space of the root partion in MBs with two decimal places
echo "SPACE_ROOT_FREE = $( df -hk / | awk 'sub(/dev/,""){printf("%.2f",$4 / 1024) }' ) MB"
