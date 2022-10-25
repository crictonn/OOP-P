#include <stdio.h>
#include <Windows.h>
#include <iostream>

using namespace std;

class gym {
public: 
	string adress;
};

class machine : public gym {
public: 
	string serialNumber, status;
	int amount; 
	float hoursOfUse; 
};

int main() {



	return 0;
}