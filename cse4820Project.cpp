#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>


int main() {
	
	int choice;
	char interface[20]; // stores wireless interface name
	char command[100]; // used to store any commands given to the terminal
	command[0] = '\0'; // clears any garbage stored in memory
		
	printf(">>> Please enter the name of your wireless interface card: ");
	scanf("%s",interface);
        strcat(command,"sudo airmon-ng check kill");
        system("command");
        system("clear");
        command[0] = '\0';
	strcat(command,"sudo airmon-ng start "); // activates the wifi card
	strcat(command,interface);
        system("clear");
	system(command);
	
	
	printf(">>> The following are nearby Wi-Fi networks: \n");
	
	// script to scan for wifi networks nearby "sudo airodump-ng -c 9 interface_name"
	// print wifi networks to user 
	
	printf(">>> Which network would you like to compromise? (Please select the number (###)): \n");
	scanf("%d",&choice);
	
	
	return 0;
}
