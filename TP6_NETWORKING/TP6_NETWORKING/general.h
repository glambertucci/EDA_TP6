#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

typedef struct
{
	string My_ip; //Ip mia
	vector <int> order;//orden en el que imprimo //deberia mandarlo a un package
	vector <string> ips;//ips 
	int animation; ////a package
	int current_machine;//quien esta dibujando //Para package
	bool first;//soy la primera
	bool drawing; //me debo dibujar
}userData;
