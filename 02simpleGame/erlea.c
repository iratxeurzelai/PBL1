#include "game02.h"
#include "imagen.h"
#include "graphics.h"
#include "ebentoak.h"
#include "text.h"
#include "soinua.h"
#include <stdio.h>
#include <windows.h>
#include <SDL.h>
#include "balak.h"
#include "markagailuak.h"
#include "animazioak.h"
#include "etsaiak.h"
#include "erlea.h"
#define ERLEA1 ".\\img\\Bozetoak\\Etsaiak\\Berezia\\ERLEA\\Erlea1.bmp"
#define ERLEARENDISPAROA ".\\img\\Bozetoak\\Etsaiak\\Berezia\\ERLEA\\disparoa.bmp"


void disparatuErlea1()
{

	erleaDisparoa[0].x = erlea.x + 75;
	erleaDisparoa[0].y = erlea.y + 75;
	erleaDisparoa[1].x = erlea.x + 75;
	erleaDisparoa[1].y = erlea.y + 75;
	erleaDisparoa[2].x = erlea.x + 75;
	erleaDisparoa[2].y = erlea.y + 75;

}
void disparatuErlea2()
{
	erleaDisparoa[0].x = erlea.x + 75;
	erleaDisparoa[0].y = erlea.y;
	erleaDisparoa[1].x = erlea.x + 75;
	erleaDisparoa[1].y = erlea.y;
	erleaDisparoa[2].x = erlea.x + 75;
	erleaDisparoa[2].y = erlea.y;

}
void disparatuErlea3()
{
	erleaDisparoa[0].x = erlea.x;
	erleaDisparoa[0].y = erlea.y;
	erleaDisparoa[1].x = erlea.x;
	erleaDisparoa[1].y = erlea.y;
	erleaDisparoa[2].x = erlea.x;
	erleaDisparoa[2].y = erlea.y;

}
void disparatuErlea4()
{
	erleaDisparoa[0].x = erlea.x;
	erleaDisparoa[0].y = erlea.y + 75;
	erleaDisparoa[1].x = erlea.x;
	erleaDisparoa[1].y = erlea.y + 75;
	erleaDisparoa[2].x = erlea.x;
	erleaDisparoa[2].y = erlea.y + 75;

}
void hasieratuErlearenBalenIrudia()
{

	erleaDisparoa[0].irudia[0] = irudiaKargatu(ERLEARENDISPAROA);
	erleaDisparoa[1].irudia[1] = irudiaKargatu(ERLEARENDISPAROA);
	erleaDisparoa[0].irudia[2] = irudiaKargatu(ERLEARENDISPAROA);
	erleaDisparoa[1].irudia[3] = irudiaKargatu(ERLEARENDISPAROA);
	erleaDisparoa[0].irudia[4] = irudiaKargatu(ERLEARENDISPAROA);
	erleaDisparoa[1].irudia[5] = irudiaKargatu(ERLEARENDISPAROA);
	erleaDisparoa[0].irudia[6] = irudiaKargatu(ERLEARENDISPAROA);
	erleaDisparoa[1].irudia[7] = irudiaKargatu(ERLEARENDISPAROA);


}
void kenduErlearenBalenIrudia()
{
	irudiaKendu(erleaDisparoa[0].irudia[0]);
	irudiaKendu(erleaDisparoa[1].irudia[1]);
	irudiaKendu(erleaDisparoa[0].irudia[2]);
	irudiaKendu(erleaDisparoa[1].irudia[3]);
	irudiaKendu(erleaDisparoa[0].irudia[4]);
	irudiaKendu(erleaDisparoa[1].irudia[5]);
	irudiaKendu(erleaDisparoa[0].irudia[6]);
	irudiaKendu(erleaDisparoa[1].irudia[7]);
}
void erlearenBizitzaHasieratu()
{
	erlea.bizitza = etsaienBizitza.erleaHasierakoa;
}
int erlearekinKolisioa()
{
	int kolisioa = 0;

	if ((erlea.x > pertsonaia.x && erlea.x + 75 < pertsonaia.x + 40) && (erlea.y > pertsonaia.y && erlea.y + 75 < pertsonaia.y + 60))
	{
		kolisioa = 1;
	}
	if ((pertsonaia.x < erleaDisparoa[0].x && pertsonaia.x + 40 > erleaDisparoa[0].x) && (pertsonaia.y < erleaDisparoa[0].y && pertsonaia.y + 60 > erleaDisparoa[0].y))
	{
		kolisioa = 2;
	}
	if ((pertsonaia.x < erleaDisparoa[1].x && pertsonaia.x + 40 > erleaDisparoa[1].x) && (pertsonaia.y < erleaDisparoa[1].y && pertsonaia.y + 60 > erleaDisparoa[1].y))
	{
		kolisioa = 2;
	}
	if ((pertsonaia.x < erleaDisparoa[2].x && pertsonaia.x + 40 > erleaDisparoa[2].x) && (pertsonaia.y < erleaDisparoa[2].y && pertsonaia.y + 60 > erleaDisparoa[2].y))
	{
		kolisioa = 2;
	}
	return kolisioa;
}
int erleariJo()
{
	int kolisioa = 0;

	if ((erlea.x < bala[0].x && erlea.x + 75 > bala[0].x) && (erlea.y < bala[0].y && erlea.y + 75 > bala[0].y))
	{
		kolisioa = 1;
	}
	if ((erlea.x < bala[1].x && erlea.x + 75 > bala[1].x) && (erlea.y < bala[1].y && erlea.y + 75 > bala[1].y))
	{
		kolisioa = 1;
	}
	if ((erlea.x < bala[2].x && erlea.x + 75 > bala[2].x) && (erlea.y < bala[2].y && erlea.y + 75 > bala[2].y))
	{
		kolisioa = 1;
	}

	return kolisioa;
}
