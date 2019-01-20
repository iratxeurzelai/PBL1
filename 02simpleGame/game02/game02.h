#ifndef GAME10_H
#define GAME10_H
#define _CRT_SECURE_NO_WARNINGS
#include "ourTypes.h"

int sarreraMenua();
EGOERA jokatu(void);
void pertsonaiaAutatu();
void jokoarenGida();
int  jokoAmaierakoa(EGOERA egoera);
int sarreraMenua();
void hitboxErdia();
void pertsonairenIrudiaAldatu(int aldea);
void bizitzaBarraAldatu(int bizitza);
//void erlearenBizitzaBarraAldatu();

struct etsaienBidak
{
	int erleaHasierakoa, normalakHasierakoa;
}etsaienBizitza;
struct ERLEA
{
	int x, y, bizitza, mugimendua, bizitzaBarra[1], disparatu;

}erlea;
struct etsaia
{
	int x, y, bizitzak;

}etsaiak[12];
struct EtsaienIrudia
{
	int id[12];

}etsaiarenIrudia;
struct balak
{
	int x, y;
}bala[3];
struct pertsonaiaPos
{
	int x, y, irudia[2], erdiaX, erdiaY, aldea, bizitzaBarra[1];
}pertsonaia;
struct erlearenDisparoa
{
	int x, y, irudia[12];

}erleaDisparoa[3];
#endif