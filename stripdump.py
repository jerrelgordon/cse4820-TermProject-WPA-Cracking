import re
import os

file = open("firstdump.txt","r")
raw_data = file.read()
file.close()

lines = raw_data.split("\n")

for i in lines:
    if "WPA" in i:
        #print(i)
        with open("stripped_dump.txt","a") as fp:
            fp.write("%s\n" %i)



file = open("stripped_dump.txt","r")
stripped_data = file.read()
file.close()


stripped_lines = stripped_data.split("\x1b")

for j in stripped_lines:
    with open("dump.txt","a") as fp:
            fp.write("%s\n" %j)

file = open("dump.txt","r")
stripped_data2 = file.read()
file.close()


stripped_lines2= stripped_data2.split("[0K")

for j in stripped_lines2:
    with open("dump2.txt","a") as fp:
            fp.write("%s\n" %j)




file = open("dump2.txt","r")
stripped_data3 = file.read()
file.close()


stripped_lines3= stripped_data3.split("[1B")

for j in stripped_lines3:
    with open("dump3.txt","a") as fp:
            fp.write("%s\n" %j)

remove_duplicates = set(stripped_lines3)
final_capture = list(remove_duplicates)

for j in final_capture:
    with open("airodump1.txt","a") as fp:
            fp.write("%s\n" %j)


os.system("rm dump.txt")
os.system("rm dump2.txt")
os.system("rm dump3.txt")
os.system("rm stripped_dump.txt")

os.system("cat airodump1.txt")
