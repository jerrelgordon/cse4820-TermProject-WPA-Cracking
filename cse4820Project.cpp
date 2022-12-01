#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>


using namespace std;

int main() {

        system("python3 sniff.py");
        system("python3 crack.py");
        system("python3 cleanup.py");
	return 0;
}
