#include <string>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include "bazowa.h"
#include "render_api.h"
#pragma warning( disable : 6386 )
#pragma warning(disable:4996)
using namespace std;
rozgrywka::rozgrywka() :tryb_gry(0), nick1("Gracz1"), nick2("Gracz2"), oddane_strzaly_1(0), oddane_strzaly_2(0), trafienia_1(0), trafienia_2(0)//konstruktor
{
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			//uzupelnianie tablic(plansz) pustymi polami
			plansza1_1[i][k] = { ' ' };
			plansza1_2[i][k] = { ' ' };
			plansza2_1[i][k] = { ' ' };
			plansza2_2[i][k] = { ' ' };
		}
	}
}
void przerwa(int x)
{
	for (int i = 0; i < x; i++)
		cout << (" ");
}

void rozgrywka::pokaz_plansze(char plansza1[10][10], char plansza2[10][10])//funkcja tworzy i pokazuje plansze z przeslanych dwoch tablic dwuwymiarowych
{
	render_api::wypisz_plansze(plansza1, plansza2);
}

int rozgrywka::czy_wygrana(char plansza[10][10])//funkcja sprawdza czy w przeslanej tablicy znajduja sie jeszcze symbole oznaczajace niezatopiony statek i zwraca odpowiednia informacje
{
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (plansza[i][k] == '1' || plansza[i][k] == '2' || plansza[i][k] == '3' || plansza[i][k] == '4')
			{
				return 0;
			}
		}
	}
	return 1;
}
void rozgrywka::podawanie_pozycji(unsigned int* wspol_x, unsigned int* wspol_y)//funkcja pobiera od uzytkownika wspolrzedne X i Y dla statku
{
	while (scanf("%d%d", wspol_x, wspol_y) != 2 || *wspol_x > 10 || *wspol_y > 10 || getchar() != '\n')
	{
		render_api::b³êdna_wspó³rzêdna();
	}
}
void przer(int x)
{
	for (int i = 0; i < x; i++)
	{
		printf(" ");
	}
}
void rozgrywka::wygrana(char nick[])//funkcja ktora wyswietla statystyki po wygranej jednej ze stron
{
	render_api::statystyki(nick, nick1, nick2, oddane_strzaly_1, oddane_strzaly_2, trafienia_1, trafienia_2);
}

int rozgrywka::strzal(char plansza1[10][10], char plansza2[10][10])//funkcja odopowiadaja za strzal gracza
{
	unsigned int wspolrzedna_x, wspolrzedna_y;
	render_api::podaj_wspó³rzêdne();
	podawanie_pozycji(&wspolrzedna_x, &wspolrzedna_y);//wywolanie funkcji gdzie uzytkownik podaje wspolrzedne X i Y gdzie chce strzelic
	render_api::clear_screen();
	//sprawdzanie gdzie strzelil uzytkownik
	if (plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == ' ')//jezeli uzytkownik strzelil w puste pole
	{
		//ustawianie oznaczenia strzalu w odpowiednich tablicach
		plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '.';
		plansza2[wspolrzedna_y - 1][wspolrzedna_x - 1] = '.';
		return 0;
	}
	else if (plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == 'x' || plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == '.')//jezeli uzytkownik strzelil w juz strzelane pole
	{
		return 2;
	}
	else//jezeli uzytkownik trafil
	{
		//umieszczanie odpowiednich oznaczen statkow na tablicach
		if (plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == '1')//jezeli statek jednomasztowy
		{
			plansza2[wspolrzedna_y - 1][wspolrzedna_x - 1] = '1';
		}
		else if (plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == '2')//jezeli statek dwumasztowy
		{
			plansza2[wspolrzedna_y - 1][wspolrzedna_x - 1] = '2';
		}
		else if (plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == '3')//jezeli statek trzymasztowy
		{
			plansza2[wspolrzedna_y - 1][wspolrzedna_x - 1] = '3';
		}
		else if (plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == '4')//jezeli statek czteromasztowy
		{
			plansza2[wspolrzedna_y - 1][wspolrzedna_x - 1] = '4';
		}
		plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = 'x';//ustawienie na planszy drugiego gracza oznaczenia, ze przeciwnik trafil
		return 1;
	}
}

void rozgrywka::podawanie_orientacji_statku(unsigned int* orientacja)//funkcja pobiera od uzytkownika orientacje statku na planszy
{
	while (scanf("%d", orientacja) != 1 || *orientacja > 4 || getchar() != '\n')
	{
		render_api::opcja_nie_istnieje();
	}
}

int rozgrywka::czy_moze_tu_stac(unsigned int wspolrzedna_x, unsigned int wspolrzedna_y, char plansza[10][10])//funkcja sprawdza czy postawiony statek w tej pozycji nie
{																											//bedzie kolidowal z juz postawionymi statkami lub czy nie
	//czy nie wychodzi za tablice																			//wychodzi za plansze
	if (wspolrzedna_x > 10 || wspolrzedna_x < 1 || wspolrzedna_y > 10 || wspolrzedna_y < 1)					//zwraca 0 jezeli nie moze stac na tej pozycji lub 1 jezeli moze
	{
		return 0;
	}
	if (plansza[wspolrzedna_y - 1][wspolrzedna_x - 1] != ' ')
	{
		return 0;
	}
	if (wspolrzedna_x == 10)//jezeli dotyka prawej sciany(sprawdzamy tylko czy czegos nie dotyka po lewej)
	{
		if (plansza[wspolrzedna_y - 1][wspolrzedna_x - 2] != ' ')
		{
			return 0;
		}
	}
	else if (wspolrzedna_x == 1)//jezeli dotyka lewej sciany(sprawdzamy tylko czy czegos nie dotyka po prawej)
	{
		if (plansza[wspolrzedna_y - 1][wspolrzedna_x] != ' ')
		{
			return 0;
		}
	}
	else//jezeli nie dotyka zadnej sciany(lewej lub prawej)(sprawdzamy czy nie dotyka czegos z obu stron)
	{
		if (plansza[wspolrzedna_y - 1][wspolrzedna_x] != ' ' || plansza[wspolrzedna_y - 1][wspolrzedna_x - 2] != ' ')
		{
			return 0;
		}
	}
	if (wspolrzedna_y == 10)//jezeli dotyka dolna sciane(sprawdzamy tylko czy czegos nie dotyka u gory)
	{
		if (plansza[wspolrzedna_y - 2][wspolrzedna_x - 1] != ' ')
		{
			return 0;
		}
	}
	else if (wspolrzedna_y == 1)//jezeli dotyka dolna sciane(sprawdzamy tylko czy czegos nie dotyka u dolu)
	{
		if (plansza[wspolrzedna_y][wspolrzedna_x - 1] != ' ')
		{
			return 0;
		}
	}
	else//jezeli nie dotyka dotyka zadnej sciany(gornej lub dolnej)(sprawdzamy czy nie dotyka czegos u gory i dolu)
	{
		if (plansza[wspolrzedna_y - 2][wspolrzedna_x - 1] != ' ' || plansza[wspolrzedna_y][wspolrzedna_x - 1] != ' ')
		{
			return 0;
		}
	}
	if (wspolrzedna_y > 1)//jezeli nie dotyka gornej sciany
	{
		if (wspolrzedna_x == 10)//jezeli dotyka prawej sciany(sprawdzamy tylko czy lewy gorny rog jest wolny)
		{
			if (plansza[wspolrzedna_y - 2][wspolrzedna_x - 2] != ' ')
			{
				return 0;
			}
		}
		else if (wspolrzedna_x == 1)//jezeli dotyka lewej sciany(sprawdzamy tylko czy prawy gorny rog jest wolny)
		{
			if (plansza[wspolrzedna_y - 2][wspolrzedna_x] != ' ')
			{
				return 0;
			}
		}
		else//jezeli nie dotyka zadnej sciany(lewej lub prawej)(sprawdzamy czy gorne rogi sa wolne)
		{
			if (plansza[wspolrzedna_y - 2][wspolrzedna_x - 2] != ' ' || plansza[wspolrzedna_y - 2][wspolrzedna_x] != ' ')
			{
				return 0;
			}
		}
	}
	if (wspolrzedna_y < 10)//jezeli nie dotyka dolnej sciany
	{
		if (wspolrzedna_x == 10)//jezeli dotyka prawej sciany(sprawdzamy tylko czy lewy dolny rog jest wolny)
		{
			if (plansza[wspolrzedna_y][wspolrzedna_x - 2] != ' ')
			{
				return 0;
			}
		}
		else if (wspolrzedna_x == 1)//jezeli dotyka lewej sciany(sprawdzamy tylko czy prawy dolny rog jest wolny)
		{
			if (plansza[wspolrzedna_y][wspolrzedna_x] != ' ')
			{
				return 0;
			}
		}
		else//jezeli nie dotyka zadnej sciany(lewej lub prawej)(sprawdzamy czy dolne rogi sa wolne)
		{
			if (plansza[wspolrzedna_y][wspolrzedna_x - 2] != ' ' || plansza[wspolrzedna_y][wspolrzedna_x] != ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

void rozgrywka::ustawienie_statkow(char plansza1[10][10], char plansza2[10][10])//funkcja  ustawia statki na planszy(wersja dla gracza)
{
	unsigned int wspolrzedna_x, wspolrzedna_y, orientacja;
	int odpowiedz = 0;
	for (int i = 0; i < 4; i++)//ustawianie statkow jednomasztowych
	{
		render_api::clear_screen();
		pokaz_plansze(plansza1, plansza2);//pokazanie odpowiedniej planszy
		render_api::ustawiasz_statek(1, i+1);
		do
		{
			podawanie_pozycji(&wspolrzedna_x, &wspolrzedna_y);//uzytkownik podaje wspolrzedne statku do postawienia
			odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);//sprawdzanie czy w wylosowanej pozycji moze stac statek
			if (odpowiedz == 0)
			{
				render_api::nie_mo¿na_postawiæ_statku();
			}
		} while (odpowiedz != 1);//jezeli nie moze stac statek w tej pozycji uzytkownik podaje nowe wspolrzedne
		plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '1';//wpisanie statku do tablicy w odpowiednie miejsce
	}
	for (int i = 0; i < 3; i++)//ustawianie statkow dwumasztowych
	{
		render_api::clear_screen();
		pokaz_plansze(plansza1, plansza2);//pokazanie odpowiedniej planszy
		render_api::ustawiasz_statek(2, i + 1);
		while (1)
		{
			podawanie_pozycji(&wspolrzedna_x, &wspolrzedna_y);//uzytkownik podaje wspolrzedne statku do postawienia
			render_api::podaj_orientacjê();
			podawanie_orientacji_statku(&orientacja);//uzytkownik podaje orientacj\251 statku do postawienia
			//sprawdzanie czy w danej orientacji moze stac statek poprzez wywolywanie funkcji sprawdzajacej to dla kazdej wsp\242\210rz\251dnej w ktorej bedzie sie znajdowal statek
			if (orientacja == 1)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y - 1, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
			}
			else if (orientacja == 2)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x + 1, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}

			}
			else if (orientacja == 3)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x - 1, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
			}
			else if (orientacja == 4)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y + 1, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
			}
			break;//jezeli moze stac w takim miejscu przerwanie petli
		}
		//wpisaniu statku do tablicy w odpowiednie miejsce(w zaleznosci od orientacji)
		if (orientacja == 1)
		{
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '2';
			plansza1[wspolrzedna_y - 2][wspolrzedna_x - 1] = '2';
		}
		else if (orientacja == 2)
		{
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '2';
			plansza1[wspolrzedna_y - 1][wspolrzedna_x] = '2';
		}
		else if (orientacja == 3)
		{
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '2';
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 2] = '2';
		}
		else if (orientacja == 4)
		{
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '2';
			plansza1[wspolrzedna_y][wspolrzedna_x - 1] = '2';
		}
	}
	for (int i = 0; i < 2; i++)//ustawianie statkow trzymasztowych
	{
		render_api::clear_screen();
		pokaz_plansze(plansza1, plansza2);//pokazanie odpowiedniej planszy
		render_api::ustawiasz_statek(3, i + 1);
		while (1)
		{
			podawanie_pozycji(&wspolrzedna_x, &wspolrzedna_y);//uzytkownik podaje wspolrzedne statku do postawienia
			render_api::podaj_orientacjê();
			podawanie_orientacji_statku(&orientacja);//uzytkownik podaje orientacj\251 statku do postawienia
			//sprawdzanie czy w danej orientacji moze stac statek poprzez wywolywanie funkcji sprawdzajacej to dla kazdej wsp\242\210rz\251dnej w ktorej bedzie sie znajdowal statek
			if (orientacja == 1)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y - 1, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y - 2, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
			}
			else if (orientacja == 2)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x + 1, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x + 2, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}

			}
			else if (orientacja == 3)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x - 1, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x - 2, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
			}
			else if (orientacja == 4)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y + 1, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y + 2, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
			}
			break;//jezeli moze stac w takim miejscu przerwanie petli
		}
		//wpisaniu statku do tablicy w odpowiednie miejsce(w zaleznosci od orientacji)
		if (orientacja == 1)
		{
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '3';
			plansza1[wspolrzedna_y - 2][wspolrzedna_x - 1] = '3';
			plansza1[wspolrzedna_y - 3][wspolrzedna_x - 1] = '3';
		}
		else if (orientacja == 2)
		{
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '3';
			plansza1[wspolrzedna_y - 1][wspolrzedna_x] = '3';
			plansza1[wspolrzedna_y - 1][wspolrzedna_x + 1] = '3';
		}
		else if (orientacja == 3)
		{
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '3';
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 2] = '3';
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 3] = '3';
		}
		else if (orientacja == 4)
		{
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '3';
			plansza1[wspolrzedna_y][wspolrzedna_x - 1] = '3';
			plansza1[wspolrzedna_y + 1][wspolrzedna_x - 1] = '3';
		}
	}
	for (int i = 0; i < 1; i++)//ustawianie statkow czteromasztowego
	{
		render_api::clear_screen();
		pokaz_plansze(plansza1, plansza2);//pokazanie odpowiedniej planszy
		render_api::ustawiasz_statek(4, i + 1);
		while (1)
		{
			podawanie_pozycji(&wspolrzedna_x, &wspolrzedna_y);//uzytkownik podaje wsp\242\210rz\251dne statku do postawienia
			render_api::podaj_orientacjê();
			podawanie_orientacji_statku(&orientacja);//uzytkownik podaje orientacj\251 statku do postawienia
			//sprawdzanie czy w danej orientacji moze stac statek poprzez wywolywanie funkcji sprawdzajacej to dla kazdej wsp\242\210rz\251dnej w ktorej bedzie sie znajdowal statek
			if (orientacja == 1)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y - 1, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y - 2, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y - 3, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
			}
			else if (orientacja == 2)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x + 1, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x + 2, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x + 3, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
			}
			else if (orientacja == 3)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x - 1, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x - 2, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x - 3, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
			}
			else if (orientacja == 4)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y + 1, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y + 2, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y + 3, plansza1);
				if (odpowiedz == 0)
				{
					render_api::nie_mo¿na_postawiæ_statku(); continue;
				}
			}
			break;//jezeli moze stac w takim miejscu przerwanie petli
		}
		//wpisaniu statku do tablicy w odpowiednie miejsce(w zaleznosci od orientacji)
		if (orientacja == 1)
		{
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '4';
			plansza1[wspolrzedna_y - 2][wspolrzedna_x - 1] = '4';
			plansza1[wspolrzedna_y - 3][wspolrzedna_x - 1] = '4';
			plansza1[wspolrzedna_y - 4][wspolrzedna_x - 1] = '4';
		}
		else if (orientacja == 2)
		{
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '4';
			plansza1[wspolrzedna_y - 1][wspolrzedna_x] = '4';
			plansza1[wspolrzedna_y - 1][wspolrzedna_x + 1] = '4';
			plansza1[wspolrzedna_y - 1][wspolrzedna_x + 2] = '4';
		}
		else if (orientacja == 3)
		{
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '4';
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 2] = '4';
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 3] = '4';
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 4] = '4';
		}
		else if (orientacja == 4)
		{
			plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '4';
			plansza1[wspolrzedna_y][wspolrzedna_x - 1] = '4';
			plansza1[wspolrzedna_y + 1][wspolrzedna_x - 1] = '4';
			plansza1[wspolrzedna_y + 2][wspolrzedna_x - 1] = '4';
		}
	}
	render_api::clear_screen();
	pokaz_plansze(plansza1, plansza2);//pokazania odpowiedniej planszy
	Sleep(1000);
}

void rozgrywka::zapisywanie(void)//funkcja do zapisania stanu gry
{
	fstream plik;
	string nazwa_pliku;
	while (1)
	{
		render_api::podaj_nazwê_pliku_do_zapisania_gry();
		cin >> nazwa_pliku;//pobieranie nazwy pliku do zapisu
		plik.open(nazwa_pliku, ios::out);
		if (plik.good() == false)//jezeli nie udalo sie otworzyc pliku
		{
			render_api::nie_uda³o_siê();
			Sleep(1000);
			render_api::clear_screen();
			continue;//powrot na poczatek petli, aby uzytkownik mogl jeszcze raz podac nazwe pliku do zapisu
		}
		break;//wyjscie z petli jezeli plik otworzony
	}
	//zamiana w tablicach pustych miejsc na symbol '0' aby moc zapisac w pliku
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (plansza1_1[i][k] == ' ')
			{
				plansza1_1[i][k] = '0';
			}
			if (plansza1_2[i][k] == ' ')
			{
				plansza1_2[i][k] = '0';
			}
			if (plansza2_1[i][k] == ' ')
			{
				plansza2_1[i][k] = '0';
			}
			if (plansza2_2[i][k] == ' ')
			{
				plansza2_2[i][k] = '0';
			}
		}
	}
	//zapisywanie wszystkich danych do pliku
	plik << tryb_gry << "\t" << nick1 << "\t" << nick2 << "\t" << oddane_strzaly_1 << "\t" << oddane_strzaly_2 << "\t" << trafienia_1 << "\t" << trafienia_2 << "\n";
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			plik << plansza1_1[i][k] << "\t";
		}
	}
	plik << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			plik << plansza1_2[i][k] << "\t";
		}
	}
	plik << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			plik << plansza2_1[i][k] << "\t";
		}
	}
	plik << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			plik << plansza2_2[i][k] << "\t";
		}
	}
	plik << endl;
	plik.close();//zamkniecie pliku(po tej funkcji powrot do menu glownego)
	render_api::zapisano_pomyœlnie();
	Sleep(1000);
}

int rozgrywka::wczytywanie(FILE* plik)//funkcja do wczytania stanu gry
{
	rewind(plik);//przewiniecie pliku do poczatku
	//wczytanie wszystkich danych z pliku(ORAZ ICH KONTROLA !)
	fscanf(plik, "%d%s%s%d%d%d%d", &tryb_gry, nick1, nick2, &oddane_strzaly_1, &oddane_strzaly_2, &trafienia_1, &trafienia_2);
	if (tryb_gry != 1 && tryb_gry != 2)//sprawdzanie czy nie wczytano blednych danych
	{
		return 0;
	}
	//sprawdzanie czy do tablic nie wczytano nieprawidlowych danych(jezeli tak, zwracamy 0 co oznacza uszkodzony plik, w przeciwnym wypadku zwracamy 1 co oznacza prawidlowe wczytanie danych)
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			fscanf(plik, "%s", &plansza1_1[i][k]);
			if (plansza1_1[i][k] != '0' && plansza1_1[i][k] != '.' && plansza1_1[i][k] != '1' && plansza1_1[i][k] != '2' && plansza1_1[i][k] != '3' && plansza1_1[i][k] != '4' && plansza1_1[i][k] != 'x')
			{
				return 0;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			fscanf(plik, "%s", &plansza1_2[i][k]);
			if ((plansza1_2[i][k] != '0') && plansza1_2[i][k] != '.' && plansza1_2[i][k] != '1' && plansza1_2[i][k] != '2' && plansza1_2[i][k] != '3' && plansza1_2[i][k] != '4')
			{
				return 0;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			fscanf(plik, "%s", &plansza2_1[i][k]);
			if (plansza2_1[i][k] != '0' && plansza2_1[i][k] != '.' && plansza2_1[i][k] != '1' && plansza2_1[i][k] != '2' && plansza2_1[i][k] != '3' && plansza2_1[i][k] != '4' && plansza2_1[i][k] != 'x')
			{
				return 0;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			fscanf(plik, "%s", &plansza2_2[i][k]);
			if (plansza2_2[i][k] != '0' && plansza2_2[i][k] != '.' && plansza2_2[i][k] != '1' && plansza2_2[i][k] != '2' && plansza2_2[i][k] != '3' && plansza2_2[i][k] != '4')
			{
				return 0;
			}
		}
	}
	fclose(plik);//zamkniecie pliku
	//zamiana w tablicach symobli oznaczajacych puste miejsce na puste miejsca
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			if (plansza1_1[i][k] == '0')
			{
				plansza1_1[i][k] = ' ';
			}
			if (plansza1_2[i][k] == '0')
			{
				plansza1_2[i][k] = ' ';
			}
			if (plansza2_1[i][k] == '0')
			{
				plansza2_1[i][k] = ' ';
			}
			if (plansza2_2[i][k] == '0')
			{
				plansza2_2[i][k] = ' ';
			}
		}
	}
	render_api::wczytano_pomyœlnie();
	Sleep(1000);
	render_api::zaczyna(nick1);
	return 1;//zwrocenie 1 jezeli wczytano pomyslnie
}
