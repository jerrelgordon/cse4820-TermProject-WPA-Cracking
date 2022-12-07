# CSE4820 Fall 2022 Project: WPA/WPA2 Cracking Automation

## INTRODUCTION
For our term project, we decided to automate WPA/WPA2 Wi-Fi password
cracking via use of the Aircrack-ng Suite (i.e., airmon-ng, airodump-ng aireplayng and aircrack-ng.) This was achieved by writing three python scripts which
were then called in a C++ program in order to produce an easy to use executable
file. The idea behind our project is to allow an ethical hacker to take advantage
of the Aircrack-ng suite without needing to know or remember how exactly to
use each tool in the suite. It will prompt the user for a wireless interface, and
then prompt them again to enter the BSSID of the target network as well as a
client connected to the network.

## LIMITATIONS OF THE TOOL
Our tool suffers from two main limitations. Firstly, the tool currently only
targets WPA/WPA2 networks. It is currently not capable of targeting WEP
or WPS networks, however future modifications can allow for this. This is
as a result of challenges that we incurred while working on the WPA/WPA2
attack. With the time constraints to consider, we decided that it would be best
if we focused on getting the WPA/WPA2 to work as best as possible instead of
trying to extend the functionality of the tool and letting the entire tool suffer
as a result. Secondly, the tool is currently not fully automated since it does
ask the user to enter the BSSID of the target network and a client connected
to the network. This means that the user needs to have at least some working
knowledge of how WPA/WPA2 attacks works, despite the tool’s attempts to
bridge this knowledge gap with concise instructions. Despite this, the tool does
eliminate the needs to research the manual page for the various tools in the
Aircrack suite. It also eliminates the need for the user to understand what a
WPA four way handshake is, why it needs to be captured, and how to go about
capturing it. In addition to the two main limitations, our tool also lacks a
graphical interface, which some users may find more appealing and easy to use.

## TOOL COMPONENTS

1) cse4820main.cpp - main program produces executable binary that runs the
python scripts
2) sniff.py - Prompts the user for a wireless interface, initiates the interface and
then dumps information about nearby networks for the user, including BSSIDs
and ESSIDs.
3) crack.py - Using the provided BSSIDs for the target network and client respectively, the tool attempts to de-authenticate the client from the network, in
an attempt to capture the four way handshake when the client tries to reestablish a connection.
If the handshake was captured, the program will then attempt to crack the
password using dictionary list.
4) dict.txt - Password dictionary used for password cracking. This list does include data from the rockyou.txt list, and can be replaced/ customized as needed.
5) cleanup.py - The tool uses numerous hardcoded file names in its execution,
and works based on these file names. In order for a successful execution, the tool
needs to remove any files created during execution so that it can run repeatedly
without any unsolicited hiccups.
6) stripdump.py - Future functionality will include full automation, and stripdump.py is the script that will parse the initial dump, and remove the need for
the user to enter the BSSIDs for the target and client network respectively.


## REQUIRED DEPENDENCIES

1) Tool has been written for Linux systems only. Most testing has been done
on Kali Linux
2) Tool requires python3. Python3 can be installed using the following command on linux:

```sudo apt-get install python3.8```


3) The tool also requires the Aircrack suite to already be downloaded on the
system. See the following link for required dependencies.
https://www.kali.org/tools/aircrack-ng/aircrack-ng
You can run the following command to install the Aircrack suite if it is not
already pre-installed.

```sudo apt install aircrack-ng```

## TUTORIAL

1) Pull the branch from the provided github link.
2) Compile the c++ file, the following command can be used:



```gcc cse4820Project -o wifihacker```



3) Run the binary


```./wifihacker```



4) Provide program with wireless interface name:
5) Copy the BSSIDs of the target Access Point and a client connected to the
Access Point
6) Password has been cracked:
