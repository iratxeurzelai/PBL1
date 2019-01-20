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

#define ERLEA1 ".\\img\\Bozetoak\\Etsaiak\\Berezia\\ERLEA\\Erlea1.bmp"
#define ERLEARENDISPAROA ".\\img\\Bozetoak\\Etsaiak\\Berezia\\ERLEA\\disparoa.bmp"
#define ETSAIA  ".\\img\\Bozetoak\\Etsaiak\\Normala\\2.bmp"

void etsaiarenMugimendua(int etsaientzakoTxanda)
{

	for (int i = 0; i < etsaientzakoTxanda * 2; i++)
	{
		int distantziaX = pertsonaia.x - etsaiak[i].x + 40;
		int distantziaY = pertsonaia.y - etsaiak[i].y + 40;

		if (distantziaX > 0) {
			etsaiak[i].x += 4;

		}
		else if (distantziaX < 0) {
			etsaiak[i].x -= 4;

		}
		if (distantziaY > 0) {
			etsaiak[i].y += 4;

		}
		else if (distantziaY < 0) {
			etsaiak[i].y -= 4;

		}

		//------------
		else if (distantziaX = 0)
		{
			pantailaBerriztu();
		}
		//------------
	}
}
void posizioakHasieratu()
{
	//-----Ezkerra----//
	etsaiak[0].x = 80;
	etsaiak[0].y = 130;
	etsaiak[1].x = 80;
	etsaiak[1].y = 180;
	etsaiak[2].x = 80;
	etsaiak[2].y = 230;
	etsaiak[3].x = 80;
	etsaiak[3].y = 280;
	etsaiak[4].x = 80;
	etsaiak[4].y = 330;
	etsaiak[5].x = 80;
	etsaiak[5].y = 380;
	//-----Eskuma----//
	etsaiak[6].x = 520;
	etsaiak[6].y = 130;
	etsaiak[7].x = 520;
	etsaiak[7].y = 180;
	etsaiak[8].x = 520;
	etsaiak[8].y = 230;
	etsaiak[9].x = 520;
	etsaiak[9].y = 280;
	etsaiak[10].x = 520;
	etsaiak[10].y = 330;
	etsaiak[11].x = 520;
	etsaiak[11].y = 380;
}
void etsaienBizitzakHasieratu()
{
	etsaiak[0].bizitzak = etsaienBizitza.normalakHasierakoa;
	etsaiak[1].bizitzak = etsaienBizitza.normalakHasierakoa;
	etsaiak[2].bizitzak = etsaienBizitza.normalakHasierakoa;
	etsaiak[3].bizitzak = etsaienBizitza.normalakHasierakoa;
	etsaiak[4].bizitzak = etsaienBizitza.normalakHasierakoa;
	etsaiak[5].bizitzak = etsaienBizitza.normalakHasierakoa;
	etsaiak[6].bizitzak = etsaienBizitza.normalakHasierakoa;
	etsaiak[7].bizitzak = etsaienBizitza.normalakHasierakoa;
	etsaiak[8].bizitzak = etsaienBizitza.normalakHasierakoa;
	etsaiak[9].bizitzak = etsaienBizitza.normalakHasierakoa;
	etsaiak[10].bizitzak = etsaienBizitza.normalakHasierakoa;
	etsaiak[11].bizitzak = etsaienBizitza.normalakHasierakoa;
}
void hasieratuEtsaienIrudia(int zeinTxanda)
{

	for (int i = 0; i < (zeinTxanda - 1) * 2; i++)
	{
		irudiaKendu(etsaiarenIrudia.id[i]);
	}
	for (int i = 0; i < zeinTxanda * 2; i++)
	{
		etsaiarenIrudia.id[i] = irudiaKargatu(ETSAIA);
	}

}
int kolisioaEtsaiarekin(int i)
{
	int kolisioa = 0;
	if (etsaiak[i].x + 12 > pertsonaia.x + 20)
	{
		if ((etsaiak[i].x > pertsonaia.x && etsaiak[i].x < pertsonaia.x + 40) && (etsaiak[i].y > pertsonaia.y && etsaiak[i].y < pertsonaia.y + 60))
		{
			kolisioa = 1;
		}
	}
	if (etsaiak[i].x + 12 < pertsonaia.x + 20)
	{
		if ((etsaiak[i].x + 25 > pertsonaia.x && etsaiak[i].x + 50 < pertsonaia.x + 40) && (etsaiak[i].y > pertsonaia.y && etsaiak[i].y < pertsonaia.y + 60))
		{
			kolisioa = 1;
		}
	}

	return kolisioa;
}
int etsaiariJo(int i)
{
	int kolisioa = 0;

	if ((etsaiak[i].x < bala[0].x && etsaiak[i].x + 25 > bala[0].x) && (etsaiak[i].y < bala[0].y && etsaiak[i].y + 45 > bala[0].y))
	{
		kolisioa = 1;
	}
	if ((etsaiak[i].x < bala[1].x && etsaiak[i].x + 25 > bala[1].x) && (etsaiak[i].y < bala[1].y && etsaiak[i].y + 45 > bala[1].y))
	{
		kolisioa = 1;
	}
	if ((etsaiak[i].x < bala[2].x && etsaiak[i].x + 25 > bala[2].x) && (etsaiak[i].y < bala[2].y && etsaiak[i].y + 45 > bala[2].y))
	{
		kolisioa = 1;
	}

	return kolisioa;
}
void etsaienIrudiakKendu()
{
	irudiaKendu(etsaiarenIrudia.id[0]);
	irudiaKendu(etsaiarenIrudia.id[1]);
	irudiaKendu(etsaiarenIrudia.id[2]);
	irudiaKendu(etsaiarenIrudia.id[3]);
	irudiaKendu(etsaiarenIrudia.id[4]);
	irudiaKendu(etsaiarenIrudia.id[5]);
	irudiaKendu(etsaiarenIrudia.id[6]);
	irudiaKendu(etsaiarenIrudia.id[7]);
	irudiaKendu(etsaiarenIrudia.id[8]);
	irudiaKendu(etsaiarenIrudia.id[9]);
	irudiaKendu(etsaiarenIrudia.id[10]);
	irudiaKendu(etsaiarenIrudia.id[11]);
}
