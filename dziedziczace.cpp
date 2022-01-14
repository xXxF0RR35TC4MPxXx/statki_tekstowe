#pragma warning( disable : 6386 )
#pragma warning(disable:4996)
#include <string>
#include <Windows.h>
#include "dziedziczace.h"
#include <iostream>
#include "render_api.h"
gracz::gracz() :rozgrywka()//konstruktor
{
	tryb_gry = 2;
}

int gracz::gra(void)//funkcja do przeprowadzenia tury gry(gracz vs gracz)
{
	int czy_trafione = 0;
	int jezeli_wygrana = 0;
	while (1)
	{
		render_api::clear_screen();
		pokaz_plansze(plansza1_1, plansza1_2);//funkcja pokazujaca plansze pierwszego gracza(przed strzalem)
		do
		{
			czy_trafione = strzal(plansza2_1, plansza1_2);//gracz podaje gdzie chce strzelic(funkcja zwraca wartosc ktora okresla gdzie trafil)
			oddane_strzaly_1++;//dodanie oddanego strzalu do statystyk
			render_api::clear_screen();//czyszczenie ekranu
			pokaz_plansze(plansza1_1, plansza1_2);//funkcja pokazujaca plansze pierwszego gracza(po strzale)
			//sprawdzanie czy trafil
			if (czy_trafione == 0)
			{
				render_api::pudlo(0);
			}
			else if (czy_trafione == 2)
			{
				render_api::pudlo(1);
			}
			else
			{
				trafienia_1++;//dodanie trafionego strzalu do statystyk
				render_api::trafienie();
			}
			jezeli_wygrana = czy_wygrana(plansza2_1);//sprawdzanie czy gracz zatopil juz wszytskie statki
			if (jezeli_wygrana == 1)//jezeli zatopil wszytskie statki
			{
				wygrana(nick1);//wywolanie funkcji pokazujacej kto wygral oraz statystyki
				return 1;
			}
		} while (czy_trafione == 1);//dopoki trafia moze strzelac
		jezeli_wygrana = czy_wygrana(plansza2_1);//sprawdzanie czy gracz zatopil juz wszytskie statki
		Sleep(2000);
		render_api::przeka¿_komputer();
		render_api::clear_screen();//czyszczenie ekranu
		pokaz_plansze(plansza2_1, plansza2_2);//pokazanie planszy drugiego gracza(przed strzalem)
		do
		{
			czy_trafione = strzal(plansza1_1, plansza2_2);//gracz podaje gdzie chce strzelic(funkcja zwraca wartosc ktora okresla gdzie trafil)
			oddane_strzaly_2++;//dodanie oddanego strzalu do statystyk
			render_api::clear_screen();//czyszczenie ekranu
			pokaz_plansze(plansza2_1, plansza2_2);//pokazanie planszy drugiego gracza(po strzale)
			//sprawdzanie czy trafil
			if (czy_trafione == 0)
			{
				render_api::pudlo(0);
			}
			else if (czy_trafione == 2)
			{
				render_api::pudlo(1);
			}
			else
			{
				trafienia_2++;//dodanie trafionego strzalu do statystyk
				render_api::trafienie();
			}
			jezeli_wygrana = czy_wygrana(plansza1_1);//sprawdzanie czy gracz zatopil juz wszytskie statki
			if (jezeli_wygrana == 1)//jezeli zatopil wszytskie statki
			{
				wygrana(nick2);//wywolanie funkcji pokazujacej kto wygral oraz statystyki
				return 1;
			}
		} while (czy_trafione == 1);//dopoki trafia moze strzelac
		Sleep(2000);
		render_api::przeka¿_komputer();
		return 0;//koniec tury
	}
}

void gracz::ustawienia(void)//gracze ustawiaja nicki oraz statki
{
	render_api::podaj_nick1();
	render_api::przerwy(50); while (scanf_s("%s", nick1, 21) != 1 || getchar() != '\n')//pierwszy gracz podaje swoj nick
	{
		render_api::b³êdny_nick();
		render_api::podaj_nick1();
	}
	ustawienie_statkow(plansza1_1, plansza1_2);//funkcja w ktorej gracz ustawia wszystkie swoje statki
	render_api::przeka¿_komputer();
	render_api::podaj_nick1();
	render_api::przerwy(50);  while (scanf_s("%s", nick2, 21) != 1 || getchar() != '\n')//gracz drugi podaje swoj nick
	{
		render_api::b³êdny_nick();
		render_api::podaj_nick1();
	}
	ustawienie_statkow(plansza2_1, plansza2_2);//funkcja w ktorej gracz ustawia wszystkie swoje statki
	render_api::przeka¿_komputer();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bot::bot() :rozgrywka() //konstruktor
{
	tryb_gry = 1;
}

void bot::ustawienia(void)//gracz oraz komputer uswtaiaja nicki oraz statki
{
	render_api::podaj_nick1();
	render_api::przerwy(57);  while (scanf_s("%s", nick1, 21) != 1 || getchar() != '\n')//gracz podaje swoj nick
	{
		render_api::b³êdny_nick();
		render_api::podaj_nick1();
	}
	ustawienie_statkow(plansza1_1, plansza1_2);//funkcja gdzie gracz ustawia statki
	strcpy_s(nick2, "Komputer");//ustawienie drugiego nicku jako 'Komputer'
	ustawienie_statkow_bot(plansza2_1, plansza2_2);//funkcja gdzie komputer 'ustawia' statki
	render_api::komputer_ustawia_statki();
	Sleep(1000);
}

template <class T>
int bot::strzal_bot(T plansza1[10][10], T plansza2[10][10])//funkcja gdzie komputer losuje w ktore pole strzelic
{
	unsigned int wspolrzedna_x, wspolrzedna_y;
	wspolrzedna_x = (rand() % 10) + 1;//losowanie wspolrzednej X 1-10
	wspolrzedna_y = (rand() % 10) + 1;//losowanie wspolrzednej Y 1-10
	//sprawdzanie gdzie trafily wylosowane wspolrzedne
	if (plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == ' ')//jezeli trafienie w puste pole
	{
		//ustawienie oznaczen strzalu na odpowiednich planszach i zwrocenie oznaczenia nietrafienia
		plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '.';
		plansza2[wspolrzedna_y - 1][wspolrzedna_x - 1] = '.';
		return 0;
	}
	else if (plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == 'x' || plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == '.')//jezeli trafienie w pole gdzie juz strzelano
	{
		return 2;//wrocenie oznaczenia nietrafienia
	}
	else//jezeli trafiono
	{
		//ustawienie odpowiedniego oznaczenia(zaleznego od tego w jaki statek trafiono) na odpowiedniej planszy
		if (plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == '1')
		{
			plansza2[wspolrzedna_y - 1][wspolrzedna_x - 1] = '1';
		}
		else if (plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == '2')
		{
			plansza2[wspolrzedna_y - 1][wspolrzedna_x - 1] = '2';
		}
		else if (plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == '3')
		{
			plansza2[wspolrzedna_y - 1][wspolrzedna_x - 1] = '3';
		}
		else if (plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] == '4')
		{
			plansza2[wspolrzedna_y - 1][wspolrzedna_x - 1] = '4';
		}
		plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = 'x';//ustawienie oznaczenia ze wrog trafil na planszy przeciwnika
		return 1;//zwrocenie oznaczenia trafienia
	}
}

int bot::gra(void)//funkcja do przeprowadzenia tury gry(gracz vs komputer)
{
	int czy_trafione = 0;
	int jezeli_wygrana = 0;
	while (1)
	{
		render_api::clear_screen();
		pokaz_plansze(plansza1_1, plansza1_2);//wyswietlenie prawidlowej planszy(przed strzalem)
		do
		{
			czy_trafione = strzal(plansza2_1, plansza1_2);//uzytkownik oddaje strzal i sprawdzamy w co trafil
			oddane_strzaly_1++;//doliczenie do statystyk oddane strzaly
			render_api::clear_screen();//czyszczenie ekranu
			pokaz_plansze(plansza1_1, plansza1_2);//wyswietlenie prawidlowej planszy(po strzalem)
			//sprawdzanie czy trafil
			if (czy_trafione == 0)
			{
				render_api::pudlo(0);
			}
			else if (czy_trafione == 2)
			{
				render_api::pudlo(1);
			}
			else
			{
				trafienia_1++;//doliczenie do statystyk strzaly trafione
				render_api::trafienie();
			}
			jezeli_wygrana = czy_wygrana(plansza2_1);//sprawdzenie czy gracz wygral
			if (jezeli_wygrana == 1)//jezeli wygral
			{
				wygrana(nick1);//wyswietlenie statystyk
				return 1;
			}
		} while (czy_trafione == 1);//strzela do poki trafia
		Sleep(2000);

		render_api::ruch_wykonuje_komputer();
		render_api::clear_screen();//czyszczenie ekranu
		do
		{
			czy_trafione = strzal_bot(plansza1_1, plansza2_2);//wywolanie funkcji w ktorej komputer losuje gdzie strzelic i sprawdzenie gdzie trafil
			if (czy_trafione != 2)//zabezpieczenie aby nie doliczyc strzalu do statystyk ktory komputer powtorzy(stzrelil w pole w ktorej juz strzelal)
			{
				oddane_strzaly_2++;//doliczenie do statystyk oddane strzaly
			}
			//sprawdzanie czy trafil
			if (czy_trafione == 1)
			{
				trafienia_2++;//doliczenie do statystyk trafione strzaly
			}
			jezeli_wygrana = czy_wygrana(plansza1_1);//sprawdzenie czy komputer wygral
			if (jezeli_wygrana == 1)//jezeli wygral
			{
				wygrana(nick2);//wyswietlenie statystyk
				return 1;
			}
		} while (czy_trafione == 1 || czy_trafione == 2);//strzela do poki trafia lub trafil w to w co juz strzelal(bot nie marnuje strzalow na stzrelanie w cos co juz strzelal)
		return 0;//koniec tury
	}
}

template<class T>
void bot::ustawienie_statkow_bot(T plansza1[10][10], T plansza2[10][10])//funkcja w ktorej komputer losuje gdzie postawic statki
{
	unsigned int wspolrzedna_x, wspolrzedna_y, orientacja;
	int odpowiedz = 0;
	for (int i = 0; i < 4; i++)//ustawianie statkow jednomasztowych
	{
		do
		{
			//komputer losuje 2 liczby z przedzialu 1-10
			wspolrzedna_x = (rand() % 10) + 1;
			wspolrzedna_y = (rand() % 10) + 1;
			odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);//sprawdzanie czy w wylosowanej pozycji moze stac statek
		} while (odpowiedz != 1);//losuje do poki nie wylosuje dobrej pozycji
		plansza1[wspolrzedna_y - 1][wspolrzedna_x - 1] = '1';//wpisanie statku do tablicy w odpowiednie miejsce
	}
	for (int i = 0; i < 3; i++)//ustawianie statkow dwumasztowych
	{
		while (1)
		{
			//komputer losuje 2 liczby z przedzialu 1-10 oraz orientacji statku 1-4
			wspolrzedna_x = (rand() % 10) + 1;
			wspolrzedna_y = (rand() % 10) + 1;
			orientacja = (rand() % 4) + 1;
			//sprawdzanie czy w danej orientacji moze stac statek poprzez wywolywanie funkcji sprawdzajacej to dla kazdej wspolrzednej w ktorej bedzie sie znajdowal statek
			if (orientacja == 1)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y - 1, plansza1);
				if (odpowiedz == 0) continue;
			}
			else if (orientacja == 2)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x + 1, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;

			}
			else if (orientacja == 3)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x - 1, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
			}
			else if (orientacja == 4)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y + 1, plansza1);
				if (odpowiedz == 0) continue;
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
		while (1)
		{
			//komputer losuje 2 liczby z przedzialu 1-10 oraz orientacji statku 1-4
			wspolrzedna_x = (rand() % 10) + 1;
			wspolrzedna_y = (rand() % 10) + 1;
			orientacja = (rand() % 4) + 1;
			//sprawdzanie czy w danej orientacji moze stac statek poprzez wywolywanie funkcji sprawdzajacej to dla kazdej wspolrzednej w ktorej bedzie sie znajdowal statek
			if (orientacja == 1)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y - 1, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y - 2, plansza1);
				if (odpowiedz == 0) continue;
			}
			else if (orientacja == 2)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x + 1, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x + 2, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;

			}
			else if (orientacja == 3)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x - 1, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x - 2, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
			}
			else if (orientacja == 4)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y + 1, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y + 2, plansza1);
				if (odpowiedz == 0) continue;
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
		while (1)
		{
			//komputer losuje 2 liczby z przedzialu 1-10 oraz orientacji statku 1-4
			wspolrzedna_x = (rand() % 10) + 1;
			wspolrzedna_y = (rand() % 10) + 1;
			orientacja = (rand() % 4) + 1;
			//sprawdzanie czy w danej orientacji moze stac statek poprzez wywolywanie funkcji sprawdzajacej to dla kazdej wspolrzednej w ktorej bedzie sie znajdowal statek
			if (orientacja == 1)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y - 1, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y - 2, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y - 3, plansza1);
				if (odpowiedz == 0) continue;
			}
			else if (orientacja == 2)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x + 1, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x + 2, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x + 3, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
			}
			else if (orientacja == 3)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x - 1, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x - 2, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x - 3, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
			}
			else if (orientacja == 4)
			{
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y + 1, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y + 2, plansza1);
				if (odpowiedz == 0) continue;
				odpowiedz = czy_moze_tu_stac(wspolrzedna_x, wspolrzedna_y + 3, plansza1);
				if (odpowiedz == 0) continue;
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
	render_api::clear_screen();//czyszczenie ekranu
}
