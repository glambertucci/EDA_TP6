#include "general.h"
#include "utils.h"
#include <fstream>
#include <curses.h>
void fill_vector(vector<string>& strin)
{
	ifstream src;
	src.open("ips.txt");
	string line;
	while (src.good()) {

		getline(src, line);		strin.push_back(line);
	}
	src.close();
}

void get_user_data (userData& usr)
{
	WINDOW * winTest = NULL;
	winTest = initscr();
	nodelay(winTest, TRUE);
	noecho();
	immedok(winTest, TRUE);
	string s;
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	color_set(1, NULL);
	move(0, 0);
	printw("Elija una de las siguientes animaciones:\n");
	printw("A.Cat Running\nB. Explosion 1\nC. Explosion 2\nD. Homer Dance\nE. Super Mario\nF. Sonic");
	int i=1,valid=1;
	while (valid)
	{
		i = getch();
		if ((toupper(i)<='F') && (toupper(i) >= 'A'))
		{
			valid = 0;
		}
	}
	usr.animation = i;
	printw("Ingrese el orden en el que quiere ver la animacion de a una maquina\n");
	int lenght = usr.ips.size();
	for (int i = 0; i < lenght; i++)
	{
		int num;
		cin >> num;//No estaria verificando que sea un numero valido o que no se repita tipo tengo 3 pcs y 1234 o 1223 si quieren hacerlo haganlo :)
		usr.order.push_back(num); //el orden ahora está en un vector
		cout << "Siguiente!" << endl;
	}


}