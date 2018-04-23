#pragma once
#include "general.h"
#include "utils.h"

class paquete
{
public:
	paquete();
	~paquete();
	string make_packet();//arma el paquete para mandar 
	//Importante: Paquete: Primero animacion, luego la pocicion en el orden de quien dibuja! no la maquina que esta dibujando Ojal, luego el vector orden
	void set_packet(string recived);
	int next_pc();
	bool myturn(int mynum);//recibe el numero de compu que sos y devuelve si te toca
	bool amITheLastOne(int totalIps);
	vector <int> order;//orden en el que imprimo //deberia mandarlo a un package
	char animation; ////a package
	int count;//quien esta dibujando (EN EL ORDEN) //Para package
private:

};

