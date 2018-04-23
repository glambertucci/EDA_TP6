#include "general.h"
#include "callback.h"
#include "allegro.h"
#include "package.h"
#include "parser.h"
#include "client.h"
#include "server.h"
#include "utils.h"
#include <iostream>
using namespace std;
int main(int argc, char ** argv)
{
	userData  usr;
	userData* pusr= &usr;
	allegro_c allegro;
	bool draw_finished=false;
	bool exit = false;
	fill_vector(usr.ips);//llena al vector con las ips
	if (parseCmdLine(argc, argv, &callback, (&usr)) > 0) //parsea 
	{// aca va el resto
		do   //PAQUETES primero que animacion, contador de animacion y orden
		{
			paquete pkt;
			paquete * ppkt=&pkt;
		
			if (usr.first)//tengoq ue hacer un cliente y mandarlo
			{//LARECONCHADETUMADRE PORQUE PIJA NO QUERES ACEPTAR EL PAQUETE
				//get_user_data(pusr, ppkt);//recibe  de usuario
				//ME FIJO el orden y me fijo a quien le toca dibujar, le mando el paquete a quien le toque y me pongo a escuchar.

			}
			if (pkt.myturn(usr.myPos) )
			{ // es mi turno de dibujar
				allegro.draw(pkt);//ahora tengo que dibujar ya que solo salgo de listen si tengo que dibujar
				draw_finished = true;
			}
			///Solo entra con usr.first al primera ves
			if (draw_finished || usr.first ) { // le tengo que hablar a la proxima computadora
				client cl;// creo el cliente y mando el paquete
				cl.connect( usr.My_ip.c_str(), "12345");
				cl.send_msg(pkt.make_packet());
				draw_finished = false;
				usr.first = false;
			}
			//Cuando este ene el ultimo me tengo que fijar si soy el ultimo en dibujar, asi no se quedan todos mudos. cosa que salte la funcion de que hacer.
			//itpo if(notthelastone) y el codigo de abajo
			if (!(pkt.amITheLastOne(usr.totalIps))) {
				server srvr("12345");//el tp dice que ese es el puerto
				srvr.listen();//escucho//Como es bloqueante 
				string response = srvr.recive_msg();
				pkt.set_packet(response);
			}
			else exit = true;//esto deberia ser cambiado a una funcion que haga lo que dice abajo
				
		} while (exit);// cuando termina el loop podes ponerle una funcion que lo que haga es preguntarle si quiere seguir
					// y si sigue que elija otra ves el orden y eso
	}
	else
		cout << "Error in parse" << endl;


	return 0;
}
