> All parts of the task should be highlighted in the report as level 2 headers.
> Within one part of the task, everything that is added to the report must be in the form of the list.
> Each screenshot in the report must be briefly captioned (what’s in the screenshot).
> All screenshots must be cropped so that only the relevant part of the screen is shown.

# <h1 align="center">Report on Linux operating systems</h1>

_<h2 align="left"> Part 1. Installation of the OS:</h2>_
_Version of the OS installed: Ubuntu 20.04 Server LTS without GUI_
![Version of the OS after the Installation](../misc/images/my_screenshots/Screen_Shot_2022-08-09_at_8.26.10_PM.png)

_<h2 align="left"> Part 2. Creating a user:</h2>_
_Add user using sudo adduser <username> command and gave the user admin rights using sudo_
![Add user using sudo adduser <username> command and gave admin rights](../misc/images/my_screenshots/Screen_Shot_2022-08-10_at_5.13.27_PM.png)
_Result of cat /etc/passwd command output_
![Result of cat /etc/passwd command output](../misc/images/my_screenshots/Screen_Shot_2022-08-10_at_5.14.57_PM.png)

_<h2 align="left"> Part 3. Setting up the OS network:</h2>_

1. Set the machine name as user-1:
    Look up the hostname with hostnamectl:
`$ hostnamectl`
    And edit it using:
`$ hostnamectl set-hostname 'user-1'`

_Result of the hostname look up and hostname change_
![Look up and change the hostname](../misc/images/my_screenshots/Screen_Shot_2022-08-10_at_6.26.55_PM.png)

2. Set the time zone corresponding to your current location:
View all available timezones using `$ timedatectl list-timezones`
Set the timezone using `$ sudo timedatectl set-timezone <Etc/GMT+3>`

_Result of the timezone change_
![Result of the timezone change](../misc/images/my_screenshots/Screen_Shot_2022-08-10_at_6.54.23_PM.png)

3. Output the names of the network interfaces using a console command:
    To show all available interfaces I need to use `$ ip link show` command

_Show all network interfaces_
![Show all network interfaces](../misc/images/my_screenshots/Screen_Shot_2022-08-10_at_7.03.33_PM.png)
lo – Loopback interface. A loopback interface is a virtual interface in our network device that is always up and active after it has been configured.

4. Use the console command to get the ip address of the device you are working on from the DHCP server:
    To get the IP-address call the command `$ ip address`

_The IP is 10.0.2.15_
![Look up the IP address](../misc/images/my_screenshots/Screen_Shot_2022-08-10_at_7.22.47_PM.png)
DHCP - Dynamic Host Configuration Protocol.

5. Define and display the external ip address of the gateway (ip) and the internal IP address of the gateway, aka default ip address (gw):    
    To find and display the internal IP of the gateway (default IP) use the following command: `$ ip route | grep default`

_Internal IP address of the gateway_
![Internal IP address of the gateway](../misc/images/my_screenshots/Screen_Shot_2022-08-10_at_8.13.36_PM.png)
    To find the external IP address of the gateway:  I need to first call nestat -rn to find all the addresses, then do nslookup on the desired IP and look up the address that I've got:

_External IP address of the gateway_
![External IP address of the gateway](../misc/images/my_screenshots/Screen_Shot_2022-08-10_at_8.40.18_PM.png)

6. Set static (manually set, not received from DHCP server) ip, gw, dns settings (use public DNS servers, e.g. 1.1.1.1 or 8.8.8.8):
    To set static IP, not received from DHCP server I need to do 
