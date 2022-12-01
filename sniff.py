import os

os.system("iwconfig")
interface = input(">>> Please enter the name of your wireless interface card: (wlan0, wlan1 etc...): ")

command = "sudo airmon-ng check kill"
os.system(command)

command = "sudo airmon-ng start " + interface
os.system(command)
os.system("iwconfig")

interface = input(">>> Please re-enter the name of your wireless interface card that is in monitor mode: (wlan0, wlan1, wlan0mon, wlan1mon etc ...): ")

print("Sniffing networks ... ")

command = "sudo timeout --foreground 15 airodump-ng " + interface + " > firstdump.txt"
os.system(command)


print(">>> The following are nearby Wi-Fi networks: \n")
os.system("python3 stripdump.py")

print(">>> Which network would you like to compromise? (Enter the BSSID that appears next to the WiFi Name xx:xx:xx:xx:xx:xx) \n")
print("Example: \nA3:B4:5C:D7:E9:F0 WifiName\nYour Entry should be: A3:B4:5C:D7:E9:F0\n\n")
