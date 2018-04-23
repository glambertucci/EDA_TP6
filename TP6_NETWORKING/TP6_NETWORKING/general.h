#pragma once
#include <vector>
#include <string>

#include <iostream>
using namespace std;
#define EMPTY -1
typedef struct
{
	string My_ip; //Ip mia
	vector <string> ips;//ips 
	bool first=false;//soy la primera
	int totalIps;
	int myPos=EMPTY;//My posicion en la lista
}userData;
