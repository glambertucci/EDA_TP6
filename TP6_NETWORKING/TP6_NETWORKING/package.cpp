#include "package.h"



paquete::paquete()
{
	animation = EMPTY;
	count = EMPTY;

}

bool paquete::myturn(int mynum)
{
	//Me fijo si coinciden en la lista de a quien le toca
	//con quien soy yo, el menos uno es porque curremt machine nunca es cero 
	return (count != EMPTY ? order[count - 1] == mynum : false);//Si count esta inicializado devuelvo todo pio, si no false
}
int paquete::next_pc()
{
	return order[count - 1];
}
bool paquete::amITheLastOne(int totalIps)
{
	return totalIps == count;
}
string paquete::make_packet()
{
	char arr[2] = { animation,0 };
	string packet = arr;
	packet += to_string(++count); //Aumento count para mandar el paquete
	for (int num : order)
	{
		packet += num;
	}
	return packet;
}

void paquete::set_packet(string recived)
{
	animation = recived[0];
	recived.erase(recived.begin());
	count = recived[0];
	for (char ch : recived)
		order.push_back(ch);

}
paquete::~paquete()
{
}
