
#include "callback.h"

int callback(char * key, char * PARAMETER, void * USER_DATA)
{
	userData * usr = (userData*)USER_DATA;
	if (key == NULL)
	{
		if (!strcmp(key, "INICIA"))
		{
			usr->first = true;
			return 0;
		}
		else
		{
			usr->first = false;
		}

	}
	else if (!strcmp(key, "IP"))
	{

		for(int i=0; i < usr->ips.size() ;i++)
		{
			if (!strcmp(PARAMETER, usr->ips[i].c_str()))
			{
				usr->My_ip = PARAMETER; //ACA TENGO QUE FIJARME QUE LA IP ESTE EN MI LISTA ASI SE MI POCIION
				usr->myPos = i; //la ip que soy segun la lista;
				return 0;
			}
		}
	}
	else
		return ERROR3;
}