# <h1 align="center">Linux Network Report</h1>

_<h2 align="left"> Part 1. ipcalc tool:</h2>_
_<h3 align="left"> 1.1. Networks and Masks:</h3>_
`$ apt-get install ipcalc` - To install ipcalc.
ipcalc provides a simple way to calculate IP information for a host. The various options specify what information ipcalc should display on standard out. Multiple options may be specified. An IP address to operate on must always be specified.

_Installed ipcalc:_ \
<img src="../misc/my_screenshots/Installed_ipcalc.png" alt="Installed ipcalc" width="800"/>

1) Network address of 192.167.38.54/13: \
`$ ipcalc 192.167.38.54/13` - information output for a host. \
_192.167.38.54/13:_ \
<img src="../misc/my_screenshots/Network_address_of_specified_ip.png" alt="Installed ipcalc" width="800"/>

2) Conversion of the mask 255.255.255.0 to prefix and binary, /15 to normal and binary, 11111111.11111111.11111111.11110000 to normal and prefix:

_255.255.255.0 to prefix and binary:_ \
<img src="../misc/my_screenshots/To_prefix_and_binary.png" alt="255.255.255.0 to prefix and binary" width="800"/>

_/15 to normal and binary:_ \
<img src="../misc/my_screenshots/To_normal_and_binary.png" alt="15 to normal and binary" width="800"/>

_11111111.11111111.11111111.11110000 to normal and prefix:_ \
<img src="../misc/my_screenshots/To_normal_and_prefix.png" alt="11111111.11111111.11111111.11110000 to normal and prefix" width="800"/>

3) Minimum and maximum host in 12.167.38.4 network with masks: /8, 11111111.11111111.00000000.00000000, 255.255.254.0 and /4:

_Minimum and maximum host in 12.167.38.4 network with mask /8:_ \
<img src="../misc/my_screenshots/Min_max_mask_8.png" alt="Minimum and maximum host in 12.167.38.4 network with mask /8" width="800"/>

_Minimum and maximum host in 12.167.38.4 network with mask 11111111.11111111.00000000.00000000:_ \
<img src="../misc/my_screenshots/Min_max_mask_16.png" alt="Minimum and maximum host in 12.167.38.4 network with mask 11111111.11111111.00000000.00000000" width="800"/>

_Minimum and maximum host in 12.167.38.4 network with mask 255.255.254.0:_ \
<img src="../misc/my_screenshots/Min_max_mask_254.png" alt="Minimum and maximum host in 12.167.38.4 network with mask 255.255.254.0" width="800"/>

_Minimum and maximum host in 12.167.38.4 network with mask /4:_ \
<img src="../misc/my_screenshots/Min_max_mask_4.png" alt="Minimum and maximum host in 12.167.38.4 network with mask /4" width="800"/>

_<h3 align="left"> 1.2. localhost:</h3>_

Define and write in the report whether an application running on localhost can be accessed with the following IPs: 194.34.23.100, 127.0.0.2, 127.1.0.1, 128.0.0.1:

_194.34.23.100 - Public IP. The application running on localhost cannot be accessed:_ \
<img src="../misc/my_screenshots/localhost_194.34.23.100.png" alt="194.34.23.100 - Public IP" width="800"/>

_127.0.0.2 - Local IP. The application running on localhost can be accessed:_ \
<img src="../misc/my_screenshots/localhost_127.0.0.2.png" alt="127.0.0.2 - Local IP" width="800"/>

_127.0.0.1 - Local IP. The application running on localhost can be accessed:_ \
<img src="../misc/my_screenshots/localhost_127.0.0.1.png" alt="127.0.0.1 - Local IP" width="800"/>

_128.0.0.1 - Local IP. The application running on localhost cannot be accessed:_ \
<img src="../misc/my_screenshots/localhost_128.0.0.1.png" alt="128.0.0.1 - Local IP" width="800"/>

_<h3 align="left"> 1.3. Network ranges and segments:</h3>_

1) which of the listed IPs can be used as public and which only as private: 10.0.0.45, 134.43.0.2, 192.168.4.2, 172.20.250.4, 172.0.2.1, 192.172.0.1, 172.68.0.2, 172.16.255.255, 10.10.10.10, 192.169.168.1:

Private: 10.0.0.45, 192.168.4.2, 172.20.250.4, 172.16.255.255, 10.10.10.10

Public: 134.43.0.2, 172.0.2.1, 192.172.0.1, 172.68.0.2, 192.169.168.1

_<h2 align="left"> Part 2. Static routing between two machines:</h2>_

_View existing network interfaces with the ip a command:_ \
<img src="../misc/my_screenshots/ip_a.png" alt="View existing network interfaces with the ip a command" width="800"/>

Describe the network interface corresponding to the internal network on both machines and set the following addresses and masks: ws1 - 192.168.100.10, mask */16 *, ws2 - 172.24.116.8, mask /12:

_ws1 - 192.168.100.10, mask */16 *, ws2 - 172.24.116.8, mask /12:_ \
<img src="../misc/my_screenshots/set_ip_and_mask.png" alt="ws1 - 192.168.100.10, mask */16 *, ws2 - 172.24.116.8, mask /12" width="800"/>

Run the netplan apply command to restart the network service:

_Network restarted and changed took effect:_ \
<img src="../misc/my_screenshots/netplan_apply.png" alt="Network restarted and changed took effect" width="800"/>

_<h3 align="left"> 2.1. Adding a static route manually:</h3>_

_Add a static route from one machine to another and back using a `$ ip r add` command and ping the connection between the machines:_ \
<img src="../misc/my_screenshots/ip_r_add_and_ping.png" alt="Ip route added and the machines pinged" width="800"/>

_<h3 align="left"> 2.2. Adding a static route with saving:</h3>_

1. Restart the machines - `$ sudo reboot`.
2. Add static route from one machine to another using etc/netplan/00-installer-config.yaml file.
3. Ping the connection between the machines.

_Static route added and pinged:_ \
<img src="../misc/my_screenshots/static_route_and_ping.png" alt="Static route added and pinged" width="800"/>

_<h2 align="left"> Part 3. iperf3 utility:</h2>_

_<h3 align="left"> 3.1. Connection speed:</h3>_
Convert and write results in the report: 8 Mbps to MB/s, 100 MB/s to Kbps, 1 Gbps to Mbps:

8 Mbps to MB/s: 1MB/s \
100 MB/s to Kbps: 819 200 Kbps (in binary) (* 8 * 1024), 800 000 Kbps (in decimal) (* 8 * 1000)\
1 Gbps to Mbps: 1 024 Mbps

_<h3 align="left"> 3.2. iperf3 utility:</h3>_
Measure connection speed between ws1 and ws2:

To download iperf3 I need internet access set up. To do it I need to do the following:
1. Turn on the second interface to be able to set up the Internet.
2. Turn on DHCP for the second interface in the netplan.
3. Netplan apply.
4. Ping an address to be sure that it works.

`$ sudo apt-get install iperf3` \
On the server `$ iperf3 -s` \
On the client `$ iperf3 -c 172.24.116.8 -p 5201`

_Output of the speed measurement:_ \
<img src="../misc/my_screenshots/iperf3_test.png" alt="Static route added and pinged" width="800"/>

_<h2 align="left"> Part 4. Network firewall:</h2>_


1. `$sudo vim /etc/firewall.sh` 
2. Enter the flush and and delete chain commands:
```
#!/bin/sh

# Deleting all the rules in the "filter" table (default).
iptables -F
iptables –X
```
3. Enter the iptable commands for ws1 and ws2 according to the instructions: 

_firewall.sh for ws1 and ws2:_ \
<img src="../misc/my_screenshots/firewall_sh.png" alt="firewall.sh for ws1 and ws2" width="800"/>

4. `$ sudo chmod +x /etc/firewall.sh`
5. `$ sudo /etc/firewall.sh`
6. List the created rules: `$ sudo iptables -L`

_Rules listed:_ \
<img src="../misc/my_screenshots/iptables_L.png" alt="Rules listed" width="800"/>

_Flags explained:_ \
<img src="../misc/my_screenshots/iptables_flags.png" alt="Flags explained" width="800"/>

7. Describe in the report the difference between the strategies used in the first and second files: \
First suitable rule met is going to be executed. Rules that are applied after are going to be ignored.

_<h2 align="left"> 4.2. nmap utility:</h2>_

Use ping command to find a machine which is not pinged, then use nmap utility to show that the machine host is up.

1. `$ sudo apt-get install nmap`

_Contents of firewall.sh:_ \
<img src="../misc/my_screenshots/contents_firewall.png" alt="Contents of firewall.sh" width="800"/>

2. Add screenshots with the call and output of the ping and nmap commands to the report:

_Ping and nmap:_ \
<img src="../misc/my_screenshots/ping_and_nmap.png" alt="Ping and nmap" width="800"/>

3. Save dumps of the virtual machines:

_Exports to files:_ \
<img src="../misc/my_screenshots/export_to_file.png" alt="Exports to files" width="800"/>

_Shapshots:_ \
<img src="../misc/my_screenshots/snapshot_ws1.png" alt="snapshot_ws1.png" width="800"/>
<img src="../misc/my_screenshots/snapshot_ws2.png" alt="snapshot_ws2.png" width="800"/>

_<h2 align="left"> Part 5. Static network routing:</h2>_

_Start five virtual machines (3 workstations (ws11, ws21, ws22) and 2 routers (r1, r2)):_ \
<img src="../misc/my_screenshots/five_vm_started.png" alt="Five virtual machines started" width="1600"/>

_<h3 align="left"> 5.1. Configuration of machine addresses:</h3>_

_Configuration of the machines applied in the netplan:_ \
<img src="../misc/my_screenshots/netplan_written_for_5_machines.png" alt="Configuration of the machines applied in the netplan" width="800"/>

_Check that the machine address is correct with the `$ ip -4 a` command. Also ping ws22 from ws21. Similarly ping r1 from ws11:_ \
<img src="../misc/my_screenshots/ip_a_and_ping.png" alt="Ip a and ping result" width="1600"/>

_<h3 align="left"> 5.2. Enabling IP forwarding:</h3>_

`$ sysctl -w net.ipv4.ip_forward=1:` \
<img src="../misc/my_screenshots/ip_forward_r1.png" alt="ip_forward_r1.png" width="800"/>
<img src="../misc/my_screenshots/ip_forward_r2.png" alt="ip_forward_r2.png" width="800"/>

`$ net.ipv4.ip_forward = 1` added to /etc/sysctl.conf: \
<img src="../misc/my_screenshots/sysctl_conf_perm.png" alt="sysctl_conf_perm.png" width="800"/>

_<h3 align="left"> 5.3. Default route configuration:</h3>_

_Default gateway set:_ \
<img src="../misc/my_screenshots/default_gateway_set.png" alt="default_gateway_set.png" width="800"/>

_`$ ip r` command output:_ \
<img src="../misc/my_screenshots/ip_r_command_output.png" alt="ip_r_command_output.png" width="800"/>

_Ping r2 router from ws11 and show on r2 that the ping is reaching. To do this, use the `$ tcpdump -tn -i eth1`:_ \
<img src="../misc/my_screenshots/ping_r2_from_w11.png" alt="ping_r2_from_w11.png" width="800"/>

_<h3 align="left"> 5.4. Adding static routes:</h3>_
