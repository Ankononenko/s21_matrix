# <h1 align="center">Linux Network Report</h1>

_<h2 align="left"> Part 1. ipcalc tool:</h2>_
_<h3 align="left"> 1.1. Networks and Masks:</h3>_
`$ apt-get install ipcalc` - To install ipcalc.
ipcalc provides a simple way to calculate IP information for a host. The various options specify what information ipcalc should display on standard out. Multiple options may be specified. An IP address to operate on must always be specified.

_Installed ipcalc:_ \
<img src="../misc/images/my_screenshots/Installed_ipcalc.png" alt="Installed ipcalc" width="800"/>

1) Network address of 192.167.38.54/13: \
`$ ipcalc 192.167.38.54/13` - information output for a host. \
_192.167.38.54/13:_ \
<img src="../misc/images/my_screenshots/Network_address_of_specified_ip.png" alt="Installed ipcalc" width="800"/>

2) Conversion of the mask 255.255.255.0 to prefix and binary, /15 to normal and binary, 11111111.11111111.11111111.11110000 to normal and prefix:

_255.255.255.0 to prefix and binary:_ \
<img src="../misc/images/my_screenshots/To_prefix_and_binary.png" alt="255.255.255.0 to prefix and binary" width="800"/>

_/15 to normal and binary:_ \
<img src="../misc/images/my_screenshots/To_normal_and_binary.png" alt="15 to normal and binary" width="800"/>

_11111111.11111111.11111111.11110000 to normal and prefix:_ \
<img src="../misc/images/my_screenshots/To_normal_and_prefix.png" alt="11111111.11111111.11111111.11110000 to normal and prefix" width="800"/>

3) Minimum and maximum host in 12.167.38.4 network with masks: /8, 11111111.11111111.00000000.00000000, 255.255.254.0 and /4:

_Minimum and maximum host in 12.167.38.4 network with mask /8:_ \
<img src="../misc/images/my_screenshots/Min_max_mask_8.png" alt="Minimum and maximum host in 12.167.38.4 network with mask /8" width="800"/>

_Minimum and maximum host in 12.167.38.4 network with mask 11111111.11111111.00000000.00000000:_ \
<img src="../misc/images/my_screenshots/Min_max_mask_16.png" alt="Minimum and maximum host in 12.167.38.4 network with mask 11111111.11111111.00000000.00000000" width="800"/>

_Minimum and maximum host in 12.167.38.4 network with mask 255.255.254.0:_ \
<img src="../misc/images/my_screenshots/Min_max_mask_254.png" alt="Minimum and maximum host in 12.167.38.4 network with mask 255.255.254.0" width="800"/>

_Minimum and maximum host in 12.167.38.4 network with mask /4:_ \
<img src="../misc/images/my_screenshots/Min_max_mask_4.png" alt="Minimum and maximum host in 12.167.38.4 network with mask /4" width="800"/>

_<h3 align="left"> 1.2. localhost:</h3>_

Define and write in the report whether an application running on localhost can be accessed with the following IPs: 194.34.23.100, 127.0.0.2, 127.1.0.1, 128.0.0.1:

_194.34.23.100 - Public IP. The application running on localhost cannot be accessed:_ \
<img src="../misc/images/my_screenshots/localhost_194.34.23.100.png" alt="194.34.23.100 - Public IP" width="800"/>

_127.0.0.2 - Local IP. The application running on localhost can be accessed:_ \
<img src="../misc/images/my_screenshots/localhost_127.0.0.2.png" alt="127.0.0.2 - Local IP" width="800"/>

_127.0.0.1 - Local IP. The application running on localhost can be accessed:_ \
<img src="../misc/images/my_screenshots/localhost_127.0.0.1.png" alt="127.0.0.1 - Local IP" width="800"/>

_128.0.0.1 - Local IP. The application running on localhost cannot be accessed:_ \
<img src="../misc/images/my_screenshots/localhost_128.0.0.1.png" alt="128.0.0.1 - Local IP" width="800"/>

_<h3 align="left"> 1.3. Network ranges and segments:</h3>_

1) which of the listed IPs can be used as public and which only as private: 10.0.0.45, 134.43.0.2, 192.168.4.2, 172.20.250.4, 172.0.2.1, 192.172.0.1, 172.68.0.2, 172.16.255.255, 10.10.10.10, 192.169.168.1:

Private: 10.0.0.45, 192.168.4.2, 172.20.250.4, 172.16.255.255, 10.10.10.10

Public: 134.43.0.2, 172.0.2.1, 192.172.0.1, 172.68.0.2, 192.169.168.1

_<h2 align="left"> Part 2. Static routing between two machines:</h2>_

_View existing network interfaces with the ip a command:_ \
<img src="../misc/images/my_screenshots/ip_a.png" alt="View existing network interfaces with the ip a command" width="800"/>

Describe the network interface corresponding to the internal network on both machines and set the following addresses and masks: ws1 - 192.168.100.10, mask */16 *, ws2 - 172.24.116.8, mask /12:

_ws1 - 192.168.100.10, mask */16 *, ws2 - 172.24.116.8, mask /12:_ \
<img src="../misc/images/my_screenshots/set_ip_and_mask.png" alt="ws1 - 192.168.100.10, mask */16 *, ws2 - 172.24.116.8, mask /12" width="800"/>

Run the netplan apply command to restart the network service:

_Network restarted and changed took effect:_ \
<img src="../misc/images/my_screenshots/netplan_apply.png" alt="Network restarted and changed took effect" width="800"/>

_<h3 align="left"> 2.1. Adding a static route manually:</h3>_

_Add a static route from one machine to another and back using a `$ ip r add` command and ping the connection between the machines:_ \
<img src="../misc/images/my_screenshots/ip_r_add_and_ping.png" alt="Ip route added and the machines pinged" width="800"/>

_<h3 align="left"> 2.2. Adding a static route with saving:</h3>_

1. Restart the machines - `$ sudo reboot`.
2. Add static route from one machine to another using etc/netplan/00-installer-config.yaml file.
3. Ping the connection between the machines.

_Static route added and pinged:_ \
<img src="../misc/images/my_screenshots/static_route_and_ping.png" alt="Static route added and pinged" width="800"/>

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
<img src="../misc/images/my_screenshots/iperf3_test.png" alt="Static route added and pinged" width="800"/>

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
<img src="../misc/images/my_screenshots/firewall_sh.png" alt="firewall.sh for ws1 and ws2" width="800"/>

4. `$ sudo chmod +x /etc/firewall.sh`
5. `$ sudo /etc/firewall.sh`
6. List the created rules: `$ sudo iptables -L`

_Rules listed:_ \
<img src="../misc/images/my_screenshots/iptables_L.png" alt="Rules listed" width="800"/>

_Flags explained:_ \
<img src="../misc/images/my_screenshots/iptables_flags.png" alt="Flags explained" width="800"/>

7. Describe in the report the difference between the strategies used in the first and second files: \
First suitable rule met is going to be executed. Rules that are applied after are going to be ignored.

_<h2 align="left"> 4.2. nmap utility:</h2>_

Use ping command to find a machine which is not pinged, then use nmap utility to show that the machine host is up.

1. `$ sudo apt-get install nmap`

_Contents of firewall.sh:_ \
<img src="../misc/images/my_screenshots/contents_firewall.png" alt="Contents of firewall.sh" width="800"/>

2. Add screenshots with the call and output of the ping and nmap commands to the report:

_Ping and nmap:_ \
<img src="../misc/images/my_screenshots/ping_and_nmap.png" alt="Ping and nmap" width="800"/>

3. Save dumps of the virtual machines:

_Exports to files:_ \
<img src="../misc/images/my_screenshots/export_to_file.png" alt="Exports to files" width="800"/>

_Shapshots:_ \
<img src="../misc/images/my_screenshots/snapshot_ws1.png" alt="snapshot_ws1.png" width="800"/>
<img src="../misc/images/my_screenshots/snapshot_ws2.png" alt="snapshot_ws2.png" width="800"/>

_<h2 align="left"> Part 5. Static network routing:</h2>_

_Start five virtual machines (3 workstations (ws11, ws21, ws22) and 2 routers (r1, r2)):_ \
<img src="../misc/images/my_screenshots/five_vm_started.png" alt="Five virtual machines started" width="1600"/>

_<h3 align="left"> 5.1. Configuration of machine addresses:</h3>_

_Configuration of the machines applied in the netplan:_ \
<img src="../misc/images/my_screenshots/netplan_written_for_5_machines.png" alt="Configuration of the machines applied in the netplan" width="800"/>

_Check that the machine address is correct with the `$ ip -4 a` command. Also ping ws22 from ws21. Similarly ping r1 from ws11:_ \
<img src="../misc/images/my_screenshots/ip_a_and_ping.png" alt="Ip a and ping result" width="1600"/>

_<h3 align="left"> 5.2. Enabling IP forwarding:</h3>_

`$ sysctl -w net.ipv4.ip_forward=1:` \
<img src="../misc/images/my_screenshots/ip_forward_r1.png" alt="ip_forward_r1.png" width="800"/>
<img src="../misc/images/my_screenshots/ip_forward_r2.png" alt="ip_forward_r2.png" width="800"/>

`$ net.ipv4.ip_forward = 1` added to /etc/sysctl.conf: \
<img src="../misc/images/my_screenshots/sysctl_conf_perm.png" alt="sysctl_conf_perm.png" width="800"/>

_<h3 align="left"> 5.3. Default route configuration:</h3>_

_Default gateway set:_ \
<img src="../misc/images/my_screenshots/default_gateway_set.png" alt="default_gateway_set.png" width="800"/>

_`$ ip r` command output:_ \
<img src="../misc/images/my_screenshots/ip_r_command_output.png" alt="ip_r_command_output.png" width="800"/>

_Ping r2 router from ws11 and show on r2 that the ping is reaching. To do this, use the `$ tcpdump -tn -i eth1`:_ \
<img src="../misc/images/my_screenshots/ping_r2_from_w11.png" alt="ping_r2_from_w11.png" width="800"/>

_<h3 align="left"> 5.4. Adding static routes:</h3>_

_Add static routes to r1 and r2 in configuration file:_ \
<img src="../misc/images/my_screenshots/static_routes_for_routers_added.png" alt="static_routes_for_routers_added.png" width="800"/>

_Call ip r and show route tables on both routers:_ \
<img src="../misc/images/my_screenshots/routers_ip_r_output.png" alt="routers_ip_r_output.png" width="800"/>

_Run `$ ip r list 10.10.0.0/[netmask]` and `$ ip r list 0.0.0.0/0` commands on ws11:_ \
<img src="../misc/images/my_screenshots/ws11_ip_r_output.png" alt="ws11_ip_r_output.png" width="800"/>

_Explain in the report why a different route other than 0.0.0.0/0 had been selected for 10.10.0.0/[netmask] although it could be the default route:_ \
First IP and mask suits the route that is set in netplan (10.10.0.0/18) and the other one doesn't (one of the things that doesn't fit under the rule - 0.0.0.0/0 is out of the set mask), so it follows the default route set.

_<h2 align="left"> 5.5. Making a router list:</h2>_

_Traceroute utility output after adding a gateway and `$ tcpdump -tnv -i eth0`:_ \
<img src="../misc/images/my_screenshots/traceroute_after_adding_gateway_and_tcpdump.png" alt="traceroute_after_adding_gateway_and_tcpdump.png" width="800"/>

_Based on the output of the dump on r1, explain in the report how path construction works using traceroute:_ \
First the data goes to the eth0 interface of the r1 router, then it gets routed to the second router using eth0 interface of r2 and finally gets routed to destination 10.20.0.10.

_<h2 align="left"> 5.6. Using ICMP protocol in routing:</h2>_ 

_`$ tcpdump -n -i eth0 icmp` command on the r1 and `$ ping -c 1 10.30.0.111` from the ws11 machine:_ \
<img src="../misc/images/my_screenshots/ping_non_existent_with_tcpdump.png" alt="ping_non_existent_with_tcpdump.png" width="800"/>

_Save dumps of the virtual machine images:_ \
<img src="../misc/images/my_screenshots/snapshot_part_5_6.png" alt="snapshot_part_5_6.png" width="800"/>

_<h2 align="left"> Part 6. Dynamic IP configuration using DHCP:</h2>_

_<h3 align="left"> 1) Specify the default router address, DNS-server and internal network address:</h3>_

`$ sudo apt install isc-dhcp-server`.

_For r2, configure the DHCP service in the /etc/dhcp/dhcpd.conf file:_ \
<img src="../misc/images/my_screenshots/dhcpd_conf_set_for_r2.png" alt="dhcpd_conf_set_for_r2.png" width="800"/>

_<h3 align="left"> 2) Write nameserver 8.8.8.8. in a resolv.conf file:</h3>_

_Write nameserver 8.8.8.8. in a resolv.conf file:_ \
<img src="../misc/images/my_screenshots/nameserver_8888_resolf_conf.png" alt="nameserver_8888_resolf_conf.png" width="800"/>

_Restart the DHCP service with systemctl restart isc-dhcp-server:_ \
<img src="../misc/images/my_screenshots/restarted_isc_dhcp_server.png" alt="restarted_isc_dhcp_server.png" width="800"/>

Update netplan of ws21 for DHCP to take effect. 

_Reboot the ws21 machine with reboot and show with ip a that it has got an address (above old output and below new)._ \
<img src="../misc/images/my_screenshots/new_ip_received_from_dhcp_ws21.png" alt="new_ip_received_from_dhcp_ws21.png" width="800"/>

_Ping ws22 from ws21:_ \
<img src="../misc/images/my_screenshots/ping_ws21_from_ws22.png" alt="ping_ws21_from_ws22.png" width="800"/>

_Specify MAC address at ws11 by adding to etc/netplan/00-installer-config.yaml:_ \
<img src="../misc/images/my_screenshots/mac_set_netplan_ws11.png" alt="mac_set_netplan_ws11.png" width="800"/> \
<img src="../misc/images/my_screenshots/macaddress_modified_virtualbox.png" alt="macaddress_modified_virtualbox.png" width="800"/>  \
<img src="../misc/images/my_screenshots/ws11_mac_output.png" alt="ws11_mac_output.png" width="800"/>

_Сonfigure r1 the same way as r2, but make the assignment of addresses strictly linked to the MAC-address (ws11):_ \
<img src="../misc/images/my_screenshots/r1_dhcp_set.png" alt="r1_dhcp_set.png" width="800"/> \
<img src="../misc/images/my_screenshots/r1_dhcp_restarted.png" alt="r1_dhcp_restarted.png" width="800"/> \
<img src="../misc/images/my_screenshots/ws11_new_ip_received.png" alt="ws11_new_ip_received.png" width="800"/>

_Ping ws22 from ws11:_ \
<img src="../misc/images/my_screenshots/ping_ws22_from_ws11.png" alt="ping_ws22_from_ws11.png" width="800"/>

_Request ip address update from ws21:_ \
<img src="../misc/images/my_screenshots/ws21_request_new_ip.png" alt="ws21_request_new_ip.png" width="800"/>

_Describe in the report what DHCP server options were used in this point:_ \
The -r flag explicitly releases the current lease, and once the lease has been released, the client exits.

_Save dumps of virtual machine images:_ \
<img src="../misc/images/my_screenshots/part_6_finished_snapshots.png" alt="part_6_finished_snapshots.png" width="800"/>

_<h2 align="left"> Part 7. NAT:</h2>_

1. `$ sudo apt update`
2. `$ sudo apt install apache2`
3. `$ sudo vim /etc/apache2/ports.conf`

_In /etc/apache2/ports.conf file change the line Listen 80 to Listen 0.0.0.0:80on ws22 and r1, i.e. make the Apache2 server public:_ \
<img src="../misc/images/my_screenshots/r1_ws22_apache2_ports_conf.png" alt="r1_ws22_apache2_ports_conf.png" width="800"/>

4. `$ service apache2 start`:
<img src="../misc/images/my_screenshots/apache2_started_r1_ws22.png" alt="apache2_started_r1_ws22.png" width="800"/>

5. Add the following rules to the firewall, created similarly to the firewall from Part 4, on r2:
<img src="../misc/images/my_screenshots/r2_firewall_rules_added.png" alt="r2_firewall_rules_added.png" width="800"/>

5. Run the file as in Part 4: 
<img src="../misc/images/my_screenshots/run_firewall_rules_r2.png" alt="run_firewall_rules_r2.png" width="800"/>

6. Check the connection between ws22 and r1 with the ping command:
<img src="../misc/images/my_screenshots/check_connection_between_ws22_and_r1.png" alt="check_connection_between_ws22_and_r1.png" width="800"/>

7. Allow routing of all ICMP protocol packets and run firewall.sh: 
<img src="../misc/images/my_screenshots/allow_routing_of_all_ICMP.png" alt="allow_routing_of_all_ICMP.png" width="800"/>

8. Check connection between ws22 and r1 with the ping command:
<img src="../misc/images/my_screenshots/ping_r1_from_ws22.png" alt="ping_r1_from_ws22.png" width="800"/>

9. Enable SNAT, which is masquerade all local ip from the local network behind r2 (as defined in Part 5 - network 10.20.0.0) + \
Enable DNAT on port 8080 of r2 machine and add external network access to the Apache web server running on ws22: 
<img src="../misc/images/my_screenshots/enable_snat_dnat.png" alt="enable_snat_dnat.png" width="800"/>

10. Disabled NAT on r2:
<img src="../misc/images/my_screenshots/nat_disabled_on_r2.png" alt="nat_disabled_on_r2.png" width="800"/>

11. Check the TCP connection for SNAT by connecting from ws22 to the Apache server on r1 with the telnet [address] [port] command:
<img src="../misc/images/my_screenshots/telnet_r1_from_ws22.png" alt="telnet_r1_from_ws22.png" width="800"/>

12. Check the TCP connection for DNAT by connecting from r1 to the Apache server on ws22 with the telnet command (address r2 and port 8080):
<img src="../misc/images/my_screenshots/telnet_ws22_from_r1.png" alt="telnet_ws22_from_r1.png" width="800"/>

_Save dumps of virtual machine images:_ \
<img src="../misc/images/my_screenshots/snapshots_part_7_finished.png" alt="snapshots_part_7_finished.png" width="800"/>

_<h2 align="left"> Part 8. Bonus. Introduction to SSH Tunnels:</h2>_
