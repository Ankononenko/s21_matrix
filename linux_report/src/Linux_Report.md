# <h1 align="center">Report on Linux operating systems</h1>

_<h2 align="left"> Part 1. Installation of the OS:</h2>_
_Version of the OS installed: Ubuntu 20.04 Server LTS without GUI_ \
<img src="../misc/images/my_screenshots/Version_of_the_OS_after_the_Installation.png" alt="Version of the OS after the Installation" width="800"/>

_<h2 align="left"> Part 2. Creating a user:</h2>_
_Add user using sudo adduser <username> command and gave the user admin rights using sudo_
<img src="../misc/images/my_screenshots/Add_user_using_sudo_adduser.png" alt="Add user using sudo adduser <username> command and gave admin rights" width="800"/>

_Result of cat /etc/passwd command output_ \
<img src="../misc/images/my_screenshots/passwd_command_output.png" alt="Result of cat /etc/passwd command output" width="800"/>

_<h2 align="left"> Part 3. Setting up the OS network:</h2>_

1. Set the machine name as user-1:
    Look up the hostname with hostnamectl:
`$ hostnamectl`
    And edit it using:
`$ hostnamectl set-hostname 'user-1'`

_Result of the hostname look up and hostname change_ \
<img src="../misc/images/my_screenshots/Look_up_and_change_the_hostname.png" alt="Look up and change the hostname" width="800"/>

2. Set the time zone corresponding to your current location:
View all available timezones using `$ timedatectl list-timezones`
Set the timezone using `$ sudo timedatectl set-timezone <Etc/GMT+3>`

_Result of the timezone change_ \
<img src="../misc/images/my_screenshots/Result_of_the_timezone_change.png" alt="Result of the timezone change" width="800"/>

3. Output the names of the network interfaces using a console command:
    To show all available interfaces I need to use `$ ip link show` command

_Show all network interfaces_ \
<img src="../misc/images/my_screenshots/Show_all_network_interfaces.png" alt="Show all network interfaces" width="800"/> \
lo – Loopback interface. The loopback network interface is a virtual network device implemented entirely in software. All traffic sent to it "loops back" and just targets services on your local machine. It represents the Linux-host itself. 

4. Use the console command to get the ip address of the device you are working on from the DHCP server:
    To get the IP-address call the command `$ ip r` or `$ ip address` (since I got the IP using DHCP either way)

_The IP is 10.0.2.15_ \
<img src="../misc/images/my_screenshots/Look_up_the_IP_address.png" alt="Look up the IP address" width="800"/> \
DHCP - Dynamic Host Configuration Protocol.

5. Define and display the external ip address of the gateway (ip) and the internal IP address of the gateway, aka default ip address (gw):    
    To find and display the internal IP of the gateway (default IP) use the following command: `$  ip addr show`

_Internal IP address of the gateway_ \
<img src="../misc/images/my_screenshots/Internal_IP_address_of_the_gateway.png" alt="Internal IP address of the gateway" width="800"/> \
    To find the external IP address I need to parse IP-address from a webpage. Wget command can be used for that with flags q and O: `$ wget -qO- eth0.me`

_External IP address of the gateway_ \
<img src="../misc/images/my_screenshots/External_IP_address_of_the_gateway.png" alt="External IP address of the gateway" width="800"/>

6. Set static (manually set, not received from DHCP server) ip, gw, dns settings (use public DNS servers, e.g. 1.1.1.1 or 8.8.8.8):
- Open the interfaces file with a text editor and admin rights: `$ sudo nano /etc/network/interfaces`
    
_Open interfaces to edit_ \
<img src="../misc/images/my_screenshots/Open_interfaces_to_edit.png" alt="Open interfaces to edit" width="800"/>
- Enter new values:
    
_Enter new IP, gateway, mask, dns_ \
<img src="../misc/images/my_screenshots/Enter_new_IP_gateway_mask_dns.png" alt="Enter new IP, gateway, mask, dns" width="800"/>
- Edit /etc/resolv.conf: `$ sudo nano /etc/resolv.conf`
    
_Edit the resolv configuration file_ \
<img src="../misc/images/my_screenshots/Edit_the_resolv_configuration_file.png" alt="Edit the resolv configuration file" width="800"/>

_Entered the new dns servers_ \
<img src="../misc/images/my_screenshots/Entered_the_new_dns_servers.png" alt="Entered the new dns servers" width="800"/>

- Restart the virtual machine using `$ sudo reboot`
    
_Restarted the network_ \
<img src="../misc/images/my_screenshots/Restarted_the_network.png" alt="Restarted the network" width="800"/>

- Ping 1.1.1.1 and ya.ru:

_Ping_ \
<img src="../misc/images/my_screenshots/Ping.png" alt="Ping" width="800"/>

_<h2 align="left"> Part 4. OS Update:</h2>_

- What to do to update the OS: `$ apt-get update` and `$ sudo apt-get upgrade`

_OS update_ \
<img src="../misc/images/my_screenshots/OS_update.png" alt="OS update" width="800"/>

_<h2 align="left"> Part 5. Using the sudo command:</h2>_
_Sudo command grants root power to administrators (members of group admin or sudo) based on the rules defined in /etc/sudoers._

- `$ sudo usermod -aG sudo second_admin`;
    
_Switch to the second user and change the hostname_ \
<img src="../misc/images/my_screenshots/Switch_to_the_second_user_and_change_the_hostname.png" alt="Switch to the second user and change the hostname" width="800"/>
- `$ sudo reboot`;
    
_Hostname changed after the reboot_ \
<img src="../misc/images/my_screenshots/Hostname_changed_after_the_reboot.png" alt="Hostname changed after the reboot" width="800"/>

_<h2 align="left"> Part 6. Installing and configuring the time service:</h2>_

- Install and set up Chrony to synchronize time:

_Synchronized using Chrony_ \
<img src="../misc/images/my_screenshots/Synchronized_using_Chrony.png" alt="Synchronized using Chrony" width="800"/>

_<h2 align="left"> Part 7. Installing and using text editors:</h2>_

_1. Created a txt.file using VIM_ \
<img src="../misc/images/my_screenshots/Created_a_txt_file_using_VIM.png" alt="Created a txt.file using VIM" width="800"/> \
To save the file you need to exit the insert mode using ESC and type `:wq`.

_2. Created a txt.file using Nano_ \
<img src="../misc/images/my_screenshots/Created_a_txt_file_using_Nano.png" alt="Created a txt.file using Nano" width="800"/> \
To save the file you need to exit using `Ctrl + X`, type `y` in the pop-up screen and press enter when asked the exact filename.

_3. Created a txt.file using Emacs_ \
<img src="../misc/images/my_screenshots/Created_a_txt_file_using_Emacs.png" alt="Created a txt.file using Emacs" width="800"/> \
To save the file you need to press `Ctrl + X + C` and then in the dialog enter `y` to save the file.

_1. Find and substitute a string using VIM_ \
<img src="../misc/images/my_screenshots/Find_and_substitute_a_string_using_VIM.png" alt="Find and substitute a string using VIM" width="800"/> \
Command to find and substitute: `:s/\<finchren\>/21 School 21/` and `:q!` to exit without saving the changes.

_2. Find and substitute a string using Nano_ \
<img src="../misc/images/my_screenshots/Find_and_substitute_a_string_using_Nano.png" alt="Find and substitute a string using Nano" width="800"/> \
Command to find and substitute: `Ctrl + \` then enter the string to find, string to replace the found string with and select which occurrences to change `Ctrl + X` to exit and enter `n` to not save the changes.

_3. Find and substitute a string using Emacs_ \
<img src="../misc/images/my_screenshots/Find_and_substitute_a_string_using_Emacs.png" alt="Find and substitute a string using Emacs" width="800"/> \
Command to find and substitute: `Alt (Optinon key on Mac) + Shift + 5` then enter the string to find, string to replace the found string with and enter `y` to confirm replacement. select which occurrences to change `Ctrl + X + C` to exit, enter `q` to not save the changes and enter `yes` to exit even though there's modified buffer.

_1. Seach result and commands - VIM_

_Word search result and command - VIM_ \
<img src="../misc/images/my_screenshots/Word_search_result_and_command_VIM.png" alt="Word search result and command - VIM" width="800"/>

_2. Seach result and commands - Nano_

_Search to replace - Nano_ \
<img src="../misc/images/my_screenshots/Search_to_replace_Nano.png" alt="Search to replace - Nano" width="800"/> \
_Replace with - Nano_ \
<img src="../misc/images/my_screenshots/Replace_with_Nano.png" alt="Replace with - Nano" width="800"/> \
_Search result - Nano_ \
<img src="../misc/images/my_screenshots/Search_result_Nano.png" alt="Search result - Nano" width="800"/>

_3. Seach result and commands - Emacs_

_Search to replace - Emancs (`Alt (Optinon key on Mac) + Shift + 5`)_ \
<img src="../misc/images/my_screenshots/Search_to_replace_Emancs.png" alt="Search to replace - Emancs" width="800"/> \
_Replace with - Emacs_ \
<img src="../misc/images/my_screenshots/Replace_with_Emacs.png" alt="Replace with - Emacs" width="800"/> \
_Search result - Emacs_ \
<img src="../misc/images/my_screenshots/Search_result_Emacs.png" alt="Search result - Emacs" width="800"/>

_<h2 align="left"> Part 8. Installing and basic setup of the SSHD service:</h2>_

1. Install the SSHd service:

`$ sudo apt install openssh-server`

2. Add an auto-start of the service whenever the system boots:

`sudo system enable ssh`

_SSH status_ \
<img src="../misc/images/my_screenshots/SSH_status.png" alt="SSH status" width="800"/>

3. Reset the SSHd service to port 2022:

Back up the config file of ssh just in case: `$ sudo cp /etc/ssh/sshd_config /etc/ssh/sshd_config.factory-defaults`

Edit the file: `$ sudo vim /etc/ssh/sshd_config`

_Change the port in the editor:_ \
<img src="../misc/images/my_screenshots/Change_the_port_in_the_editor.png" alt="Change the port in the editor" width="800"/>


Restart the process: `$ sudo systemctl restart ssh`

4. Show the presence of the sshd process using the ps command. To do this, you need to match the keys to the command.

Get the PID of the process: `$ ps aux | grep sshd`. Where ps is the command to list the processes, aux are the flags (a - removes the limit to show only the process of the current user, u - user-oriented format, x - removes the limit to show only processes with a terminal). Grep searches for a string in the name of the process.
List the ssh process: `$ ps 7588`.

5. Reboot the system: `$ sudo reboot`

_The output of the netstat -tan command should contain `tcp 0 0.0.0.0:2022 0.0.0.0:* LISTEN`:_
<img src="../misc/images/my_screenshots/The_output_of_the_netstat_tan_command.png" alt="The output of the netstat -tan command" width="800"/>

Explain the meaning of the -tan keys, the value of each output column, the value 0.0.0.0. in the report:

`-a` - Displays all active connections and the TCP and UDP ports on which the computer is listening.

`-n` - Displays active TCP connections, however, addresses and port numbers are expressed numerically and no attempt is made to determine names.

`-t` - Display only TCP connections.

`Proto` - The protocol of the connection.

`Recv-Q` - The data which has not yet been pulled from the socket buffer by the application. High Recv-Q means the data is put on TCP/IP receive buffer, but the application does not call recv() to copy it from TCP/IP buffer to the application buffer.

`Send-Q` - The data which the sending application has given to the transport, but has yet to be acknowledged by the receiving TCP. High Send-Q means the data is put on TCP/IP send buffer, but it is not sent or it is sent but not acknowledged. So, high value in Send-Q can be related to server network congest, server performance issue or data packet flow control.

`Local Address` – The IP address of the local computer and the port number being used.

`Foreign Address` – The IP address and port number of the remote computer to which the socket is connected.

`State` – Indicates the state of a TCP connection. The possible states are as follows: CLOSE_WAIT, CLOSED, ESTABLISHED, FIN_WAIT_1, FIN_WAIT_2, LAST_ACK, LISTEN, SYN_RECEIVED, SYN_SEND, and TIME_WAIT.

`0.0.0.0` - The client devices like PCs show 0.0.0.0 address when they aren’t connected to any TCP/IP network. A device may get this address by default if it’s offline. In the case of address assignment failures, it may be automatically assigned by DHCP. Just in case your device is set to this address, it can’t talk to any other devices on the network over IP.

_<h2 align="left"> Part 9. Installing and using the top, htop utilities:</h2>_

_1. Install and run the top and htop utilities:_ \
`$ sudo apt-get install htop`
Top utility came preinstalled on the system.

_2. Uptime:_ \
<img src="../misc/images/my_screenshots/Uptime.png" alt="Uptime" width="800"/>

_3. Number of authorised users:_ \
<img src="../misc/images/my_screenshots/Number_of_authorised_users.png" alt="Number of authorised users›" width="800"/>

_4. Total system load:_ \
<img src="../misc/images/my_screenshots/Total_system_load.png" alt="Total system load›" width="800"/>

_5. Total number of processes:_ \
<img src="../misc/images/my_screenshots/Total_number_of_processes.png" alt="Total number of processes›" width="800"/>

_6. CPU load:_ \
<img src="../misc/images/my_screenshots/CPU_load.png" alt="CPU load›" width="800"/>

_7. Memory load:_ \
<img src="../misc/images/my_screenshots/Memory_load.png" alt="Memory load›" width="800"/>

_8. PID of the process with the highest memory usage:_ \
<img src="../misc/images/my_screenshots/Highest_memory_PID.png" alt="Highest memory PID›" width="800"/>

_9. PID of the process taking the most CPU time:_ \
<img src="../misc/images/my_screenshots/Highest_CPU_PID.png" alt="Highest CPU PID›" width="800"/>

_10. Sorted by PID:_ \
<img src="../misc/images/my_screenshots/Sorted_by_PID.png" alt="Sorted by PID›" width="800"/>

_11. Sorted by PERCENT_CPU:_ \
<img src="../misc/images/my_screenshots/Sorted by PERCENT_CPU.png" alt="Sorted by PERCENT_CPU" width="800"/>

_12. Sorted by PERCENT_MEM:_ \
<img src="../misc/images/my_screenshots/Sorted by PERCENT_MEM.png" alt="Sorted by PERCENT_MEM" width="800"/>

_13. Sorted by TIME:_ \
<img src="../misc/images/my_screenshots/Sorted by TIME.png" alt="Sorted by TIME" width="800"/>

_14. Filtered for sshd process:_ \
<img src="../misc/images/my_screenshots/Filtered_for_sshd_process.png" alt="Filtered for sshd process" width="800"/>

_15. With the syslog process found by searching:_ \
<img src="../misc/images/my_screenshots/With_the_syslog_process_found_by_searching.png" alt="With the syslog process found by searching" width="800"/>

_16. With hostname, clock and uptime output added:_ \
<img src="../misc/images/my_screenshots/With_hostname_clock_and_uptime_output_added.png" alt="With hostname, clock and uptime output added" width="800"/>

_<h2 align="left"> Part 10. Using the fdisk utility:</h2>_

_Write name of the hard disk, its capacity and number of sectors:_
1. List all devices: `$ sudo fdisk -l /dev/sda`
2. Go over each device to see extended info: `$ sudo fdisk -l /dev/sda[number of the disk]`

_Names of the disks, capacity and number of sectors:_ \
<img src="../misc/images/my_screenshots/Names_of_the_disks_capacity_and_number_of_sectors.png" alt="Names of the disks, capacity and number of sectors" width="800"/>

_Write the swap size:_
Check the swap size: `$ free -h`

_Swap size:_ \
<img src="../misc/images/my_screenshots/Swap_size.png" alt="Swap size" width="800"/>

_<h2 align="left"> Part 11. Using the df utility:</h2>_

_`$ df /dev/root` Partition size, space used, space free, percentage used for the root partition:_ \
<img src="../misc/images/my_screenshots/Partition_size_space_used_space_free_percentage_used_for_the_root_partition01.png" alt="Partition size, space used, space free, percentage used for the root partition" width="800"/>

The measurement unit is 1k-blocks - 1024 bytes.

_`$ df -Th` Partition size, space used, space free, percentage used for the root partition:_ \
<img src="../misc/images/my_screenshots/Partition_size_space_used_space_free_percentage_used_for_the_root_partition02.png" alt="Partition size, space used, space free, percentage used for the root partition" width="800"/>

Type for the partition: ext4.

_<h2 align="left"> Part 12. Using the du utility:</h2>_

_The size of the /home in bytes and human readable format:_ \
<img src="../misc/images/my_screenshots/The_size_of_the_home_in_bytes_and_human_readable_format.png" alt="The size of the /home in bytes and human readable format" width="800"/>

_The size of the /var in bytes and human readable format:_ \
<img src="../misc/images/my_screenshots/The_size_of_the_var_in_bytes_and_human_readable_format.png" alt="The size of the /var in bytes and human readable format" width="800"/>

_The size of the /var/log in bytes and human readable format:_ \
<img src="../misc/images/my_screenshots/The_size_of_the_var_log_in_bytes_and_human_readable_format.png" alt="The size of the /var/log in bytes and human readable format" width="800"/>

_The size of all contents in /var/log:_ \
<img src="../misc/images/my_screenshots/The_size_of_all_contents_in_var_log01.png" alt="The size of all contents in /var/log" width="800"/>

_`$ sudo du /var/log -a | less`:_ \
<img src="../misc/images/my_screenshots/The_size_of_all_contents_in_var_log02.png" alt="The size of all contents in /var/log" width="800"/> \
<img src="../misc/images/my_screenshots/The_size_of_all_contents_in_var_log03.png " alt="The size of all contents in /var/log" width="800"/>

_`$ sudo du /var/log -ah | less`:_ \
<img src="../misc/images/my_screenshots/The_size_of_all_contents_in_var_log04.png" alt="The size of all contents in /var/log" width="800"/> \
<img src="../misc/images/my_screenshots/The_size_of_all_contents_in_var_log05.png " alt="The size of all contents in /var/log" width="800"/>

_<h2 align="left"> Part 13. Installing and using the ncdu utility:</h2>_

_The size of the /home:_ \
<img src="../misc/images/my_screenshots/The_size_of_all_contents_in_var_log06.png " alt="The size of all contents in /var/log" width="800"/>

_The size of the /var:_ \
<img src="../misc/images/my_screenshots/The_size_of_all_contents_in_var_log07.png " alt="The size of all contents in /var/log" width="800"/>

_The size of the /var/log:_ \
<img src="../misc/images/my_screenshots/The_size_of_all_contents_in_var_log08.png " alt="The size of all contents in /var/log" width="800"/>

_<h2 align="left"> Part 14. Working with system logs:</h2>_

`/var/log/dmesg` – Contains kernel ring buffer information. When the system boots up, it prints number of messages on the screen that displays information about the hardware devices that the kernel detects during boot process. 

`var/log/syslog` - Logs everything, except auth related messages.

`var/log/auth.log` - Contains system authorization information, including user logins and authentication machinsm that were used.

_The last successful login time, user name and login method:_ \
<img src="../misc/images/my_screenshots/The_last_successful_login_time_user_name_and_login_method.png" alt="The last successful login time, user name and login method" width="800"/>

_Stopped and restarted SSH:_ \
<img src="../misc/images/my_screenshots/Stopped_and_restarted_SSH.png" alt="Stopped and restarted SSH" width="800"/>

_<h2 align="left"> Part 15. Using the CRON job scheduler:</h2>_

Using the job scheduler, run the uptime command in every 2 minutes:
1. `$ crontab -e` and select the text editor - To edit the configuration file.
2. `$ */2 * * * * uptime` - New task added.

_Lines in the system logs (at least two within a given time range) about the execution:_ \
<img src="../misc/images/my_screenshots/Lines_in_the_system_logs.png" alt="Lines in the system logs" width="800"/>

_Display a list of current jobs for CRON `$ crontab -l:`_ \
<img src="../misc/images/my_screenshots/A_list_of_current_jobs_for_CRON_01.png" alt="A list of current jobs for CRON" width="800"/>

Remove all tasks from the job scheduler:
1. `$ crontab -r` - remove all tasks;
2. `$ crontab -l` - list all tasks;

_The list of current tasks for CRON:_
<img src="../misc/images/my_screenshots/A_list_of_current_jobs_for_CRON_02.png" alt="A list of current jobs for CRON" width="800"/>
