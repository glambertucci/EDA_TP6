#include "general.h"
#include "callback.h"
#include "allegro.h"
#include "parser.h"
#include "client.h"
#include "server.h"
#include "utils.h"
#include <iostream>
using namespace std;
int main(int argc, char ** argv)
{
	userData  usr;
	allegro_c allegro;

	
	fill_vector(usr.ips);//llena al vector con las ips
	if (parseCmdLine(argc, argv, &callback, (&usr)) > 0) //parsea 
	{// aca va el resto
		do   //PAQUETES primero que animacion, contador de animacion y orden
		{
			if (usr.first)//tengoq ue hacer un cliente y mandarlo
			{
				get_user_data(usr);//recibe  de usuario
				//ME FIJO el orden y me fijo a quien le toca dibujar, le mando el paquete a quien le toque y me pongo a escuchar.
				//Flatan cosassaskmalkcas
			}
			if () { // es mi turno de dibujar
				allegro.draw(usr);//ahora tengo que dibujar ya que solo salgo de listen si tengo que dibujar

			}

			if () { // le tengo que hablar a la proxima computadora
				// creo el cliente y mando el paquete
			}
			//Cuando este ene el ultimo me tengo que fijar si soy el ultimo en dibujar, asi no se quedan todos mudos. cosa que salte la funcion de que hacer.
			//itpo if(notthelastone) y el codigo de abajo
			server srvr("12345");//el tp dice que ese es el puerto
			srvr.listen();//escucho//Como es bloqueante 
			string response = srvr.recive_msg();

				
		} while (1);//something gto close);// cuando termina el loop podes ponerle una funcion que lo que haga es preguntarle si quiere seguir
					// y si sigue que elija otra ves el orden y eso
	}
	else
		cout << "Error in parse" << endl;


	return 0;
}
