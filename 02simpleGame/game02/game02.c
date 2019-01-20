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

#define _CRT_SECURE_NO_WARNINGS
#define ONGI_ETORRI_MEZUA "Sakatu return hasteko..."
#define JOKOA_SOUND ".\\sound\\132TRANCE_02.wav"
#define JOKOAREN_PANTAILA ".\\img\\Bozetoak\\Jokoaren pantaila\\background.bmp"
#define JOLASTEKO_GIDA ".\\img\\Bozetoak\\Jokoaren pantaila\\jolastekoGida.bmp"
#define JOKALARIA_AUTATU ".\\img\\Bozetoak\\Jokoaren pantaila\\pertsonaiaAutatu.bmp"
#define MENUA ".\\img\\Bozetoak\\Jokoaren pantaila\\menua2.bmp"
#define JOKALARIA1 ".\\img\\Bozetoak\\Pertsonaiak\\Amaituta.bmp"
#define JOKALARIA0 ".\\img\\Bozetoak\\Pertsonaiak\\Amaituta1.bmp"
#define JOKOA_SOUND_WIN ".\\sound\\BugleCall.wav"
#define JOKOA_SOUND_LOOSE ".\\sound\\terminator.wav" 
#define BUKAERA_SOUND_1 ".\\sound\\128NIGHT_01.wav"
#define ERLEA1 ".\\img\\Bozetoak\\Etsaiak\\Berezia\\ERLEA\\Erlea1.bmp"
#define ERLEARENDISPAROA ".\\img\\Bozetoak\\Etsaiak\\Berezia\\ERLEA\\disparoa.bmp"
#define ETSAIA  ".\\img\\Bozetoak\\Etsaiak\\Normala\\2.bmp"
#define BUKAERA_IMAGE ".\\img\\gameOver_1.bmp"
#define BIZITZA_BARRA ".\\img\\Bozetoak\\Bizitza barrak\\pertsonaia\\barra1.bmp"
#define BIZITZA_BARRA_2 ".\\img\\Bozetoak\\Bizitza barrak\\pertsonaia\\barra2.bmp"
#define BIZITZA_BARRA_3 ".\\img\\Bozetoak\\Bizitza barrak\\pertsonaia\\barra3.bmp"
#define BIZITZA_BARRA_4 ".\\img\\Bozetoak\\Bizitza barrak\\pertsonaia\\barra4.bmp"
#define BIZITZA_BARRA_5 ".\\img\\Bozetoak\\Bizitza barrak\\pertsonaia\\barra5.bmp"
#define MUSIKA_FONDO ".\\sound\\Gurea\\MusikaFondo.wav"
#define HASIERAKO_BALAK 90
#define HASIERAKO_DENBORA 300

int erdiaX = 300, erdiaY = 240;
int ebentu = 0, zeinTxanda = 1, zeinScore = 0;

//-----Menuak-------//
int sarreraMenua()
{
	int x1= erdiaX - 60, x2= erdiaX - 70, y1= erdiaY - 40, y2= erdiaY - 50, y3= erdiaY - 30;
	int ebentu = 0, pos=0, menua;
	menua = irudiaKargatu(MENUA);

	do
	{
		pantailaBerriztu();
		pantailaGarbitu();
		irudiakMarraztu();
		textuaIdatzi(erdiaX - 50, erdiaY - 50, "JOLASTU");
		textuaIdatzi(erdiaX - 50, erdiaY, "JOKALARIA HAUTATU");
		textuaIdatzi(erdiaX - 50, erdiaY + 50, "JOLASTEKO GIDA");
		arkatzKoloreaEzarri(255, 0, 128);
		zuzenaMarraztu(x1, y1, x2, y2);
		zuzenaMarraztu(x2, y2, x2, y3);
		zuzenaMarraztu(x2, y3, x1, y1);
		ebentu = ebentuaJasoGertatuBada();
		if (ebentu == TECLA_DOWN)
		{
			if (pos != 3)
			{
				y1 += 50;
				y2 += 50;
				y3 += 50;
				pos++;
			}
			if (pos == 3)
			{
				y1 = erdiaY - 40;
				y2 = erdiaY - 50;
				y3 = erdiaY - 30;
				pos = 0;
			}
			printf("%d", pos);
		}
	} while (ebentu!=TECLA_RETURN);
	return pos;
}
void pertsonaiaAutatu()
{
	int x1 = 50, y1 = 120, x2 = 130, y2 = 120, x3 = 130, y3 = 210, x4 = 50, y4 = 210;
	int ebentu = 0, autatu, pos=1, aldaketaX=100;
	autatu = irudiaKargatu(JOKALARIA_AUTATU);

	do
	{
		pantailaBerriztu();
		pantailaGarbitu();
		irudiakMarraztu();
		ebentu = ebentuaJasoGertatuBada();
		arkatzKoloreaEzarri(255, 0, 128);
		zuzenaMarraztu(x1, y1, x2, y2);
		zuzenaMarraztu(x2, y2, x3, y3);
		zuzenaMarraztu(x3, y3, x4, y4);
		zuzenaMarraztu(x4, y4, x1, y1);
		if (ebentu==TECLA_RIGHT)
		{

			if (pos<2)
			{
				if (pos == 0)
				{
					aldaketaX = 100;
					x1 = 50;
					x2 = 130;
					x3 = 130;
					x4 = 50;
					y1 = 120;
					y2 = 120;
					y3 = 210;
					y4 = 210;
				}
				if (pos >= 1)
				{
					x1 += aldaketaX;
					x2 += aldaketaX;
					x3 += aldaketaX;
					x4 += aldaketaX;
				}
				pos++;
				aldaketaX = aldaketaX + 2;
			}
			if (pos==2)
			{
				pos = 0;
			}
		}
	} while (ebentu != TECLA_RETURN);
}
void jokoarenGida()
{
	int ebentu = 0, gida;
	gida = irudiaKargatu(JOLASTEKO_GIDA);

	do
	{
		pantailaBerriztu();
		pantailaGarbitu();
		irudiakMarraztu();
		ebentu = ebentuaJasoGertatuBada();

	} while (ebentu != TECLA_RETURN);
}

EGOERA jokatu(void) {
	int arma = 0;
	int mugitu = 0; //boolean
	EGOERA  egoera = JOLASTEN;
	int segunduak = 0;
	int vx = 10, vy = 10;
	int metrailetaBalak = HASIERAKO_BALAK, eskopetaBalak = HASIERAKO_BALAK, balakDisparatu;
	int  etsaientzakoTxanda=1,  zeinDenbora = HASIERAKO_DENBORA;
	int jokoarePantaila, erlearenIrudia;
	int marraztuErlea = 0;
	int bizitza = 100;
	int disparatzen = 0, inmune=0, inmuneErlea=0;
	int pertsonaiarenIrudiaHasieratu = 1, irudiaAldatutaEskuina=0, irudiaAldatutaEzkerra=0;
	pertsonaia.aldea = 0;//0=ezkerra eta 1=eskuina
	pertsonaia.x = erdiaX - 10;
	pertsonaia.y = erdiaY - 25;
	//--------ETSAIEN MUGIMENDURAKO--------//

	int etsaiNormalak = 1, etsaiakHasieratu = 1, etsaiaMugitu = 0, etsaiaMugitu1 = 0, etsaiaMugitu2 = 0, etsaienIrudiaHasieratuta=1;
	int n1, m1;
	int erlearenDisparoaEgin1 = 0, erlearenDisparoaEgin2 = 0, erlearenDisparoaEgin3 = 0, erlearenDisparoaEgin4 = 0;
	int erleakDisparatu1 = 0, erleakDisparatu2 = 0, erleakDisparatu3 = 0, erleakDisparatu4 = 0;
	erlea.x = erdiaX - 37, erlea.y = erdiaY - 37;
	int erleaMugimendua = 0, etsaiaHilda=0, erlearenDisparoa1=0, erlearenDisparoa2=0, erlearenDisparoa3=0, erlearenDisparoa4=0;
	posizioakHasieratu();
	int hasieratuErlea = 1;
	int zeinKolisio = 0;
	etsaienBizitza.erleaHasierakoa= 100;
	etsaienBizitza.normalakHasierakoa = 50;
	//----------IRUDIAK-----------------//
	jokoarePantaila = irudiaKargatu(JOKOAREN_PANTAILA);
	etsaienBizitzakHasieratu();
	//---------SOINUAK---------------//
	audioInit();
	loadTheMusic(MUSIKA_FONDO);
	playMusic();

	do {
		Sleep(2);
		bizitzaBarraAldatu(bizitza);
		pantailaGarbitu();
		etsaiaMugitu++;
		segunduak++;
		if (segunduak == 200 && zeinDenbora != 0)
		{
			zeinDenbora--;
			denbora(zeinDenbora);
			segunduak = 0;
		}
		irudiakMarraztu();
		if (pertsonaiarenIrudiaHasieratu)
		{
			pertsonaia.irudia[0] = irudiaKargatu(JOKALARIA0);
			pertsonaiarenIrudiaHasieratu = 0;
		}
		irudiaMugitu(pertsonaia.irudia[0], pertsonaia.x, pertsonaia.y);
		irudiaMugitu(pertsonaia.bizitzaBarra[0], pertsonaia.x - 10, pertsonaia.y - 10);
		hitboxErdia();
		if( zeinTxanda % 7!=0)
		{
			if (etsaienIrudiaHasieratuta == 1)
			{
				hasieratuEtsaienIrudia(etsaientzakoTxanda);
				etsaienIrudiaHasieratuta = 0;
			}
			if (etsaiaMugitu == 40)
			{
				etsaiaMugitu = 0;
				etsaiarenMugimendua(etsaientzakoTxanda);
				for (int i = 0; i < etsaientzakoTxanda * 2; i++)
				{
					if (etsaiak[i].bizitzak == 0)
					{
						etsaiaHilda++;
						if (etsaiaHilda == etsaientzakoTxanda * 2)
						{
							zeinScore += 200 * zeinTxanda;
							zeinTxanda++;
							etsaientzakoTxanda++;
							posizioakHasieratu();
							etsaienBizitzakHasieratu();
							etsaiaHilda = 0;
							etsaienIrudiaHasieratuta = 1;
						}
					}
				}		
				etsaiaHilda = 0;
			}
			for (int i = 0; i < etsaientzakoTxanda * 2; i++)
			{
				n1 = etsaiak[i].x;
				m1 = etsaiak[i].y;
				irudiakMarraztu();
				irudiaMugitu(etsaiarenIrudia.id[i], n1, m1);
			}
			for (int i = 0; i < etsaientzakoTxanda *2; i++)
			{
			if (kolisioaEtsaiarekin(i))
			{
				if (bizitza > 0)
				{
					printf("a");
					if (etsaiak[i].x + 25 < pertsonaia.x + 20)
					{
						pertsonaia.x += 50;

					}
					if (etsaiak[i].x + 25 > pertsonaia.x + 20)
					{
						pertsonaia.x -= 50;

					}

					irudiaMugitu(pertsonaia.irudia[pertsonaia.aldea], pertsonaia.x, pertsonaia.y);
					bizitza -= 25;
				}
				else
				{
					egoera = GALDU;
				}
			}

		}
		}	
		//------------ERLEA------------//
		if (zeinTxanda % 7 == 0)
		{
			inmune--;
			if (hasieratuErlea==1)
			{
				pantailaGarbitu();
				erlearenIrudia = irudiaKargatu(ERLEA1);
				hasieratuErlea = 0;
				erlearenBizitzaHasieratu();
				etsaienIrudiakKendu();
				pantailaBerriztu();
			}
			irudiakMarraztu();
			inmuneErlea--;
			irudiaMugitu(erlearenIrudia, erlea.x, erlea.y);
			if (erlea.mugimendua == 0)
			{
				if (erlea.y > 31)
				{
					erlea.y -= 1;
				}
				else
				{
					erlea.mugimendua++;

				}

			}
			if (erlea.mugimendua == 1)
			{
				if (erlea.x > 31)
				{
					erlea.x -= 1;
				}

				else
				{
					erlea.mugimendua++;
					disparatuErlea1();
					erleakDisparatu1 = 1;
					hasieratuErlearenBalenIrudia();
				}

			}
			if (erlea.mugimendua == 2)
			{
				if (erlea.y < 374)
				{
					erlea.y += 1;
				}

				else
				{
					erlea.mugimendua++;
					disparatuErlea2();
					erleakDisparatu2 = 1;				
					hasieratuErlearenBalenIrudia();
				}

			}
			if (erlea.mugimendua == 3)
			{
				if (erlea.x < 494)
				{
					erlea.x += 1;

				}

				else
				{
					erlea.mugimendua++;
					disparatuErlea3();
					erleakDisparatu3 = 1;
					hasieratuErlearenBalenIrudia();
				}

			}
			if (erlea.mugimendua == 4)
			{
				if (erlea.y > 31)
				{
					erlea.y -= 1;
				}

				else
				{
					erlea.mugimendua++;
					disparatuErlea4();
					erleakDisparatu4 = 1;
					hasieratuErlearenBalenIrudia();
				}
			}
			if (erlea.mugimendua == 5)
			{
				if (erlea.x > 31)
				{
					erlea.x -= 1;
				}

				else
				{
					erlea.mugimendua = 2;
					disparatuErlea1();
					erleakDisparatu1 = 1;
					hasieratuErlearenBalenIrudia();
				}
			}
			if (erleakDisparatu1 == 1)
			{
				if (erlearenDisparoaEgin1 < 40)
				{
					Sleep(5);
					erleaDisparoa[0].x += 4;
					erleaDisparoa[0].y += 2;
					erleaDisparoa[1].x += 4;
					erleaDisparoa[1].y += 6;
					erlearenDisparoaEgin1++;
					irudiaMugitu(erleaDisparoa[0].irudia[0], erleaDisparoa[0].x, erleaDisparoa[0].y);
					irudiaMugitu(erleaDisparoa[1].irudia[1], erleaDisparoa[1].x, erleaDisparoa[1].y);
					irudiakMarraztu();

				}
				else if (erlearenDisparoaEgin1 == 40)
				{
					erleakDisparatu1 = 0;
					erlearenDisparoaEgin1 = 0;
					disparatuErlea1();
					kenduErlearenBalenIrudia();

				}
			}
			if (erleakDisparatu2 == 1)
			{
				if (erlearenDisparoaEgin2 < 40)
				{
					Sleep(5);
					erleaDisparoa[0].x += 4;
					erleaDisparoa[0].y -= 2;
					erleaDisparoa[1].x += 4;
					erleaDisparoa[1].y -= 6;
					//pantailaBerriztu();
					erlearenDisparoaEgin2++;
					irudiaMugitu(erleaDisparoa[0].irudia[2], erleaDisparoa[0].x, erleaDisparoa[0].y);
					irudiaMugitu(erleaDisparoa[1].irudia[3], erleaDisparoa[1].x, erleaDisparoa[1].y);
					irudiakMarraztu();

				}
				else if (erlearenDisparoaEgin2 == 40)
				{
					erleakDisparatu2 = 0;
					disparatuErlea2();
					erlearenDisparoaEgin2 = 0;
					kenduErlearenBalenIrudia();
				}

			}
			if (erleakDisparatu3 == 1)
			{
				if (erlearenDisparoaEgin3 < 40)
				{
					Sleep(5);
					erleaDisparoa[0].x -= 4;
					erleaDisparoa[0].y -= 2;
					erleaDisparoa[1].x -= 4;
					erleaDisparoa[1].y -= 6;
					//pantailaBerriztu();
					erlearenDisparoaEgin3++;
					irudiaMugitu(erleaDisparoa[0].irudia[4], erleaDisparoa[0].x, erleaDisparoa[0].y);
					irudiaMugitu(erleaDisparoa[1].irudia[5], erleaDisparoa[1].x, erleaDisparoa[1].y);
					irudiakMarraztu();
				}
				else if (erlearenDisparoaEgin3 == 40)
				{
					erleakDisparatu3 = 0;
					disparatuErlea3();
					erlearenDisparoaEgin3 = 0;
					kenduErlearenBalenIrudia();
				}
			}
			if (erleakDisparatu4 == 1)
			{
				if (erlearenDisparoaEgin4 < 40)
				{
					Sleep(5);
					erleaDisparoa[0].x -= 4;
					erleaDisparoa[0].y += 2;
					erleaDisparoa[1].x -= 4;
					erleaDisparoa[1].y += 6;
					//pantailaBerriztu();
					erlearenDisparoaEgin4++;
					irudiaMugitu(erleaDisparoa[0].irudia[6], erleaDisparoa[0].x, erleaDisparoa[0].y);
					irudiaMugitu(erleaDisparoa[1].irudia[7], erleaDisparoa[1].x, erleaDisparoa[1].y);
					irudiakMarraztu();
				}
				else if (erlearenDisparoaEgin4 == 40)
				{
					erleakDisparatu4 = 0;
					disparatuErlea4();
					erlearenDisparoaEgin4 = 0;
					kenduErlearenBalenIrudia();
				}
			}

			zeinKolisio = erlearekinKolisioa();
			if (zeinKolisio > 0)
			{
				if (inmune<=0)
				{
					if (bizitza > 0)
					{
						if (zeinKolisio == 1 && erleariJo()==0)
						{
							printf("a");
							bizitza -= 25;
						}
						if (zeinKolisio == 2)
						{
							printf("a");
							bizitza -= 25;
							printf("%d", bizitza);
						}
						inmune = 50;
					}
				}
				
				if (bizitza == 0)
				{
					egoera = GALDU;
				}
			}
			if (erlea.bizitza==0)
			{
				hasieratuErlearenBalenIrudia();
				kenduErlearenBalenIrudia();
				zeinScore += 400 * zeinTxanda;
				zeinTxanda++;
				etsaientzakoTxanda=1;
				hasieratuErlea = 1;
				irudiaKendu(erlearenIrudia);
				etsaiaMugitu = 0;
				etsaienIrudiaHasieratuta = 1;
				etsaienBizitza.normalakHasierakoa += 25;
				etsaienBizitza.erleaHasierakoa += 100;
				//----Hasieratu aldagaiak----//
				bizitza = 100;
				eskopetaBalak = HASIERAKO_BALAK;
				metrailetaBalak = HASIERAKO_BALAK;
				zeinDenbora += 50;
				//----Hasieratu aldagaiak----//
				//----------Hobekuntzak--------//
				if (segunduak % 2 == 0)
				{
					//bizitza gehitu
					bizitza += 50;
				}

				else if (segunduak % 7 == 0)
				{
					//balak gehitu
					eskopetaBalak += 30;
					metrailetaBalak += 30;
				}
				//----------Hobekuntzak--------//

			}
		}

		sortuBalakPos();
		txanda(zeinTxanda);
		score(zeinScore);
		denbora(zeinDenbora);

		if (arma == 0)
		{
			balaKop(metrailetaBalak);
		}
		if (arma == 1)
		{
			balaKop(eskopetaBalak);
		}

		//------TEKLAK--------//
		ebentu = ebentuaJasoGertatuBada();
		switch (ebentu)
		{
		case TECLA_d:
			if (pertsonaia.erdiaX != 520)
			{
				pertsonaia.x += vx;
			}

			pertsonaia.aldea = 1;
			if (irudiaAldatutaEskuina == 0)
			{
				pertsonairenIrudiaAldatu(pertsonaia.aldea);
				irudiaAldatutaEskuina = 1;
				irudiaAldatutaEzkerra = 0;
			}

			break;
		case TECLA_a:
			if (pertsonaia.erdiaX != 40)
			{
				pertsonaia.x -= vx;

			}
			pertsonaia.aldea = 0;
			if (irudiaAldatutaEzkerra == 0)
			{
				pertsonairenIrudiaAldatu(pertsonaia.aldea);
				irudiaAldatutaEskuina = 0;
				irudiaAldatutaEzkerra = 1;
			}

			break;
		case TECLA_w:
			if (pertsonaia.erdiaY != 35)
			{
				pertsonaia.y -= vy;
			}
			break;
		case TECLA_s:
			if (pertsonaia.erdiaY != 395)
			{
				pertsonaia.y += vy;
			}
			break;
		case TECLA_m:if (arma == 0)arma++;
			break;
		case TECLA_n:if (arma == 1)arma--;
			break;
		case TECLA_SPACE:
			if (disparatzen == 0)
			{
				printf("\n%d", arma);
					if (arma == 0)
					{
						if (metrailetaBalak > 0)
						{
							disparatzen = 1;
							metrailetaBalak--;
							for (balakDisparatu = 0; balakDisparatu < 40; balakDisparatu++)
							{

								Sleep(10);
								pantailaGarbitu();
								irudiakMarraztu();
								if (zeinTxanda % 7 != 0)
								{

									if (etsaiaMugitu1 == 10)
									{
											etsaiarenMugimendua(etsaientzakoTxanda);
											etsaiaMugitu1 = 0;
									}
									for (int i = 0; i < etsaientzakoTxanda * 2; i++)
									{
										n1 = etsaiak[i].x;
										m1 = etsaiak[i].y;
										irudiakMarraztu();
										irudiaMugitu(etsaiarenIrudia.id[i], n1, m1);
									}
									etsaiaMugitu1++;
								}

								balakSortu(arma);
								disparatu(arma);
								markagailuak(zeinDenbora, zeinTxanda, zeinScore, metrailetaBalak);

								for (int j = 0; j < etsaientzakoTxanda * 2; j++)
								{
									if (etsaiariJo(j) && etsaiak[j].bizitzak > 0)
									{
										printf("d");
										etsaiak[j].bizitzak -= 25;
										printf("\n%d", etsaiak[j].bizitzak);
										balakDisparatu = 41;
									}
									if (etsaiak[j].bizitzak == 0)
									{
										etsaiak[j].x = 7000;
									}

								}
								pantailaBerriztu();
								if (zeinTxanda % 7 == 0)
								{
									
									irudiakMarraztu();
									inmuneErlea--;
									irudiaMugitu(erlearenIrudia, erlea.x, erlea.y);

									if (erlea.mugimendua == 0)
									{
										if (erlea.y > 31)
										{
											erlea.y -= 1;
										}
										else
										{
											erlea.mugimendua++;

										}

									}
									if (erlea.mugimendua == 1)
									{
										if (erlea.x > 31)
										{
											erlea.x -= 1;
										}

										else
										{
											erlea.mugimendua++;
											disparatuErlea1();
											erleakDisparatu1 = 1;
											hasieratuErlearenBalenIrudia();
										}

									}
									if (erlea.mugimendua == 2)
									{
										if (erlea.y < 374)
										{
											erlea.y += 1;
										}

										else
										{
											erlea.mugimendua++;
											disparatuErlea2();
											erleakDisparatu2 = 1;
											hasieratuErlearenBalenIrudia();
										}

									}
									if (erlea.mugimendua == 3)
									{
										if (erlea.x < 494)
										{
											erlea.x += 1;

										}

										else
										{
											erlea.mugimendua++;
											disparatuErlea3();
											erleakDisparatu3 = 1;
											hasieratuErlearenBalenIrudia();
										}

									}
									if (erlea.mugimendua == 4)
									{
										if (erlea.y > 31)
										{
											erlea.y -= 1;
										}

										else
										{
											erlea.mugimendua++;
											disparatuErlea4();
											erleakDisparatu4 = 1;
											hasieratuErlearenBalenIrudia();
										}
									}
									if (erlea.mugimendua == 5)
									{
										if (erlea.x > 31)
										{
											erlea.x -= 1;
										}

										else
										{
											erlea.mugimendua = 2;
											disparatuErlea1();
											erleakDisparatu1 = 1;
											hasieratuErlearenBalenIrudia();
										}
									}
									if (erleakDisparatu1 == 1)
									{
										if (erlearenDisparoaEgin1 < 40)
										{
											Sleep(5);
											erleaDisparoa[0].x += 4;
											erleaDisparoa[0].y += 2;
											erleaDisparoa[1].x += 4;
											erleaDisparoa[1].y += 6;
											erlearenDisparoaEgin1++;
											irudiaMugitu(erleaDisparoa[0].irudia[0], erleaDisparoa[0].x, erleaDisparoa[0].y);
											irudiaMugitu(erleaDisparoa[1].irudia[1], erleaDisparoa[1].x, erleaDisparoa[1].y);
											irudiakMarraztu();

										}
										else if (erlearenDisparoaEgin1 == 40)
										{
											erleakDisparatu1 = 0;
											erlearenDisparoaEgin1 = 0;
											disparatuErlea1();
											kenduErlearenBalenIrudia();

										}
									}
									if (erleakDisparatu2 == 1)
									{
										if (erlearenDisparoaEgin2 < 40)
										{
											Sleep(5);
											erleaDisparoa[0].x += 4;
											erleaDisparoa[0].y -= 2;
											erleaDisparoa[1].x += 4;
											erleaDisparoa[1].y -= 6;
											//pantailaBerriztu();
											erlearenDisparoaEgin2++;
											irudiaMugitu(erleaDisparoa[0].irudia[2], erleaDisparoa[0].x, erleaDisparoa[0].y);
											irudiaMugitu(erleaDisparoa[1].irudia[3], erleaDisparoa[1].x, erleaDisparoa[1].y);
											irudiakMarraztu();

										}
										else if (erlearenDisparoaEgin2 == 40)
										{
											erleakDisparatu2 = 0;
											disparatuErlea2();
											erlearenDisparoaEgin2 = 0;
											kenduErlearenBalenIrudia();
										}

									}
									if (erleakDisparatu3 == 1)
									{
										if (erlearenDisparoaEgin3 < 40)
										{
											Sleep(5);
											erleaDisparoa[0].x -= 4;
											erleaDisparoa[0].y -= 2;
											erleaDisparoa[1].x -= 4;
											erleaDisparoa[1].y -= 6;
											//pantailaBerriztu();
											erlearenDisparoaEgin3++;
											irudiaMugitu(erleaDisparoa[0].irudia[4], erleaDisparoa[0].x, erleaDisparoa[0].y);
											irudiaMugitu(erleaDisparoa[1].irudia[5], erleaDisparoa[1].x, erleaDisparoa[1].y);
											irudiakMarraztu();
										}
										else if (erlearenDisparoaEgin3 == 40)
										{
											erleakDisparatu3 = 0;
											disparatuErlea3();
											erlearenDisparoaEgin3 = 0;
											kenduErlearenBalenIrudia();
										}
									}
									if (erleakDisparatu4 == 1)
									{
										if (erlearenDisparoaEgin4 < 40)
										{
											Sleep(5);
											erleaDisparoa[0].x -= 4;
											erleaDisparoa[0].y += 2;
											erleaDisparoa[1].x -= 4;
											erleaDisparoa[1].y += 6;
											//pantailaBerriztu();
											erlearenDisparoaEgin4++;
											irudiaMugitu(erleaDisparoa[0].irudia[6], erleaDisparoa[0].x, erleaDisparoa[0].y);
											irudiaMugitu(erleaDisparoa[1].irudia[7], erleaDisparoa[1].x, erleaDisparoa[1].y);
											irudiakMarraztu();
										}
										else if (erlearenDisparoaEgin4 == 40)
										{
											erleakDisparatu4 = 0;
											disparatuErlea4();
											erlearenDisparoaEgin4 = 0;
											kenduErlearenBalenIrudia();
										}
									}

									if (erleariJo() && inmuneErlea<=0 && disparatzen == 1)
									{
										erlea.bizitza -= 25;
										printf("%d", erlea.bizitza);
										inmuneErlea = 50;
									}
								}
							}
						}

						else if (metrailetaBalak == 0)
						{
							textuaIdatzi(erdiaX - 100, 50, "EZ DAUDE BALA GEHIAGO!");
							pantailaBerriztu();
							Sleep(500);
						}
					}
					else if (arma == 1)
					{
						if (eskopetaBalak > 0)
						{
							disparatzen = 1;
							eskopetaBalak = eskopetaBalak - 3;
							for (balakDisparatu = 0; balakDisparatu < 30; balakDisparatu++)
							{
								Sleep(10);
								pantailaGarbitu();
								irudiakMarraztu();
								if (zeinTxanda % 7 != 0)
								{

									if (etsaiaMugitu2 == 10)
									{
										etsaiarenMugimendua(etsaientzakoTxanda);

											etsaiaMugitu2 = 0;

										
										etsaiaHilda = 0;
									}
									for (int i = 0; i < etsaientzakoTxanda * 2; i++)
									{
										n1 = etsaiak[i].x;
										m1 = etsaiak[i].y;
										irudiakMarraztu();
										irudiaMugitu(etsaiarenIrudia.id[i], n1, m1);
									}
									etsaiaMugitu2++;
								}
								balakSortu(arma);
								disparatu(arma);
								markagailuak(zeinDenbora, zeinTxanda, zeinScore, eskopetaBalak);

								for (int i = 0; i < etsaientzakoTxanda * 2; i++)
								{
									if (etsaiariJo(i) && etsaiak[i].bizitzak > 0)
									{
										printf("d");
										etsaiak[i].bizitzak -= 25;
										printf("\n%d", etsaiak[i].bizitzak);
										balakDisparatu = 31;
									}
									if (etsaiak[i].bizitzak == 0)
									{
										etsaiak[i].x = 7000;
									}
								}
								pantailaBerriztu();
								if (zeinTxanda % 7 == 0)
								{

									irudiakMarraztu();
									inmuneErlea--;
									irudiaMugitu(erlearenIrudia, erlea.x, erlea.y);

									if (erlea.mugimendua == 0)
									{
										if (erlea.y > 31)
										{
											erlea.y -= 1;
										}
										else
										{
											erlea.mugimendua++;

										}

									}
									if (erlea.mugimendua == 1)
									{
										if (erlea.x > 31)
										{
											erlea.x -= 1;
										}

										else
										{
											erlea.mugimendua++;
											disparatuErlea1();
											erleakDisparatu1 = 1;
											hasieratuErlearenBalenIrudia();
										}

									}
									if (erlea.mugimendua == 2)
									{
										if (erlea.y < 374)
										{
											erlea.y += 1;
										}

										else
										{
											erlea.mugimendua++;
											disparatuErlea2();
											erleakDisparatu2 = 1;
											hasieratuErlearenBalenIrudia();
										}

									}
									if (erlea.mugimendua == 3)
									{
										if (erlea.x < 494)
										{
											erlea.x += 1;

										}

										else
										{
											erlea.mugimendua++;
											disparatuErlea3();
											erleakDisparatu3 = 1;
											hasieratuErlearenBalenIrudia();
										}

									}
									if (erlea.mugimendua == 4)
									{
										if (erlea.y > 31)
										{
											erlea.y -= 1;
										}

										else
										{
											erlea.mugimendua++;
											disparatuErlea4();
											erleakDisparatu4 = 1;
											hasieratuErlearenBalenIrudia();
										}
									}
									if (erlea.mugimendua == 5)
									{
										if (erlea.x > 31)
										{
											erlea.x -= 1;
										}

										else
										{
											erlea.mugimendua = 2;
											disparatuErlea1();
											erleakDisparatu1 = 1;
											hasieratuErlearenBalenIrudia();
										}
									}
									if (erleakDisparatu1 == 1)
									{
										if (erlearenDisparoaEgin1 < 40)
										{
											Sleep(5);
											erleaDisparoa[0].x += 4;
											erleaDisparoa[0].y += 2;
											erleaDisparoa[1].x += 4;
											erleaDisparoa[1].y += 6;
											erlearenDisparoaEgin1++;
											irudiaMugitu(erleaDisparoa[0].irudia[0], erleaDisparoa[0].x, erleaDisparoa[0].y);
											irudiaMugitu(erleaDisparoa[1].irudia[1], erleaDisparoa[1].x, erleaDisparoa[1].y);
											irudiakMarraztu();

										}
										else if (erlearenDisparoaEgin1 == 40)
										{
											erleakDisparatu1 = 0;
											erlearenDisparoaEgin1 = 0;
											disparatuErlea1();
											kenduErlearenBalenIrudia();

										}
									}
									if (erleakDisparatu2 == 1)
									{
										if (erlearenDisparoaEgin2 < 40)
										{
											Sleep(5);
											erleaDisparoa[0].x += 4;
											erleaDisparoa[0].y -= 2;
											erleaDisparoa[1].x += 4;
											erleaDisparoa[1].y -= 6;
											erlearenDisparoaEgin2++;
											irudiaMugitu(erleaDisparoa[0].irudia[2], erleaDisparoa[0].x, erleaDisparoa[0].y);
											irudiaMugitu(erleaDisparoa[1].irudia[3], erleaDisparoa[1].x, erleaDisparoa[1].y);
											irudiakMarraztu();

										}
										else if (erlearenDisparoaEgin2 == 40)
										{
											erleakDisparatu2 = 0;
											disparatuErlea2();
											erlearenDisparoaEgin2 = 0;
											kenduErlearenBalenIrudia();
										}

									}
									if (erleakDisparatu3 == 1)
									{
										if (erlearenDisparoaEgin3 < 40)
										{
											Sleep(5);
											erleaDisparoa[0].x -= 4;
											erleaDisparoa[0].y -= 2;
											erleaDisparoa[1].x -= 4;
											erleaDisparoa[1].y -= 6;
											erlearenDisparoaEgin3++;
											irudiaMugitu(erleaDisparoa[0].irudia[4], erleaDisparoa[0].x, erleaDisparoa[0].y);
											irudiaMugitu(erleaDisparoa[1].irudia[5], erleaDisparoa[1].x, erleaDisparoa[1].y);
											irudiakMarraztu();
										}
										else if (erlearenDisparoaEgin3 == 40)
										{
											erleakDisparatu3 = 0;
											disparatuErlea3();
											erlearenDisparoaEgin3 = 0;
											kenduErlearenBalenIrudia();
										}
									}
									if (erleakDisparatu4 == 1)
									{
										if (erlearenDisparoaEgin4 < 40)
										{
											Sleep(5);
											erleaDisparoa[0].x -= 4;
											erleaDisparoa[0].y += 2;
											erleaDisparoa[1].x -= 4;
											erleaDisparoa[1].y += 6;
											erlearenDisparoaEgin4++;
											irudiaMugitu(erleaDisparoa[0].irudia[6], erleaDisparoa[0].x, erleaDisparoa[0].y);
											irudiaMugitu(erleaDisparoa[1].irudia[7], erleaDisparoa[1].x, erleaDisparoa[1].y);
											irudiakMarraztu();
										}
										else if (erlearenDisparoaEgin4 == 40)
										{
											erleakDisparatu4 = 0;
											disparatuErlea4();
											erlearenDisparoaEgin4 = 0;
											kenduErlearenBalenIrudia();
										}
									}

									if (erleariJo() && inmuneErlea <= 0 && disparatzen == 1)
									{
										erlea.bizitza -= 25;
										printf("%d", erlea.bizitza);
										inmuneErlea = 50;
									}									
								}
							}
						}
						else if (eskopetaBalak == 0)
						{

							textuaIdatzi(erdiaX - 100, 50, "EZ DAUDE BALA GEHIAGO!");
							pantailaBerriztu();
							Sleep(500);
						}
						printf("%d", metrailetaBalak);
						printf("%d", eskopetaBalak);
					}
					etsaiaMugitu1 = 0;
					etsaiaMugitu2 = 0;
					disparatzen = 0;
			
			break;
			}
		default:
			break;
		}
		//------TEKLAK--------//

		pantailaBerriztu();
	} while (egoera == JOLASTEN);

		toggleMusic();
		audioTerminate();
		pantailaGarbitu();
		pantailaBerriztu();
		return egoera;
	
}


void hitboxErdia()
{

	pertsonaia.erdiaX = pertsonaia.x+20;
	pertsonaia.erdiaY = pertsonaia.y + ((pertsonaia.y+60 - pertsonaia.y) / 2);

}
void pertsonairenIrudiaAldatu(int aldea)
{
	irudiaKendu(pertsonaia.irudia[0]);
	if (aldea == 0)
	{
		pertsonaia.irudia[0] = irudiaKargatu(JOKALARIA0);
	}
	if (aldea == 1)
	{
		pertsonaia.irudia[0] = irudiaKargatu(JOKALARIA1);
	}
	
}
void bizitzaBarraAldatu(int bizitza)
{
	irudiaKendu(pertsonaia.bizitzaBarra[0]);
	if (bizitza == 100)
	{
		pertsonaia.bizitzaBarra[0] = irudiaKargatu(BIZITZA_BARRA);
	}
	if (bizitza == 75)
	{
		pertsonaia.bizitzaBarra[0] = irudiaKargatu(BIZITZA_BARRA_2);
	}
	if (bizitza == 50)
	{
		pertsonaia.bizitzaBarra[0] = irudiaKargatu(BIZITZA_BARRA_3);
	}
	if (bizitza == 25)
	{
		pertsonaia.bizitzaBarra[0] = irudiaKargatu(BIZITZA_BARRA_4);
	}
	if (bizitza == 0)
	{
		pertsonaia.bizitzaBarra[0] = irudiaKargatu(BIZITZA_BARRA_5);
	}

}

/*void erlearenBizitzaBarraAldatu()
{
	irudiakMarraztu();
	if (erlea.bizitza == 100)
	{
		erlea.bizitzaBarra[0] = irudiaKargatu(ERLEAREN_BIZITZA_BARRA);
	}
	if (erlea.bizitza == 75)
	{
		erlea.bizitzaBarra[0] = irudiaKargatu(ERLEAREN_BIZITZA_BARRA_2);
	}
	if (erlea.bizitza == 50)
	{
		erlea.bizitzaBarra[0] = irudiaKargatu(ERLEAREN_BIZITZA_BARRA_3);
	}
	if (erlea.bizitza == 25)
	{
		erlea.bizitzaBarra[0] = irudiaKargatu(ERLEAREN_BIZITZA_BARRA_4);
	}
	if (erlea.bizitza == 0)
	{
		erlea.bizitzaBarra[0] = irudiaKargatu(ERLEAREN_BIZITZA_BARRA_5);
	}
	irudiaMugitu(erlea.bizitzaBarra[0], 250, 420);

	irudiaKendu(erlea.bizitzaBarra[0]);
}*/

int  jokoAmaierakoa(EGOERA egoera)
{
  int id;	
  char scorea[128];	  
  char txandak[128];
  id=irudiaKargatu(BUKAERA_IMAGE);
  do 
  {
	  pantailaBerriztu();
	  pantailaGarbitu();
	  irudiakMarraztu();
	  sprintf(scorea, "%d", zeinScore);
	  textuaIdatzi(210, 170, scorea);
	  sprintf(txandak, "%d", zeinTxanda);
	  textuaIdatzi(240, 240, txandak);
    ebentu = ebentuaJasoGertatuBada();
  } while ((ebentu!= TECLA_RETURN) && (ebentu!= SAGU_BOTOIA_ESKUMA));
  audioTerminate();
  irudiaKendu(id);
  return (ebentu != TECLA_RETURN) ? 1 : 0;
}
