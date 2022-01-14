#include <string>
#include <Windows.h>
#include <time.h>
#include <iostream>
#include "dziedziczace.h"
#include "render_api.h"
#pragma warning(disable:4996)

using namespace std;

template<typename T>
T rozpoczecie_gry(void)//funkcja pokazujaca menu dla rozpoczecia gry
{
	T wybor_gracza;
	render_api::wybor_typu_gry();
	while (scanf_s("%d", &wybor_gracza) != 1 || wybor_gracza < 1 || wybor_gracza > 3 || getchar() != '\n')//wczytywanie wyboru uzytkownika
	{
		render_api::nie_ma_opcji();
	}
	render_api::clear_screen();
	if (wybor_gracza == 1)//jezeli gracz wybral gre z komputerem
	{
		return 1;
	}
	else if (wybor_gracza == 2)//jezeli gracz wybral gre z innym graczem
	{
		return 2;
	}
	else if (wybor_gracza == 3)//jezeli gracz wybral powrot do glownego menu
	{
		return 3;
	}
	else//w wyjatkowej sytuacji koniec programu
	{
		render_api::błąd_krytyczny();
		exit(0);//awaryjne zakonczenie programu
	}
}




template<typename T>
T menu(void)//menu glowne
{
	T wybor_gracza;
	render_api::main_menu();
	while (scanf_s("%d", &wybor_gracza) != 1 || wybor_gracza < 1 || wybor_gracza > 4 || getchar() != '\n')//pobranie wyboru od uzytkownika
	{
		render_api::niestety_nie_ma_takiej_opcji();
	}
	render_api::clear_screen();
	if (wybor_gracza == 1)//jezeli gracz wybral gre
	{
		return 1;
	}
	else if (wybor_gracza == 2)//jezeli gracz wybral wczytanie gry
	{
		return 2;
	}
	else if (wybor_gracza == 3)//jezeli gracz wybral pokazanie instrukcji
	{
		return 3;
	}
	else if (wybor_gracza == 4)//jezeli gracz wybral zakonczenie programu
	{
		return 4;
	}
	else//w wyjatkowej sytuacji koniec programu
	{
		render_api::błąd_krytyczny();
		exit(0);//awaryjne zakonczenie programu
	}
}


int main()
{
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 920, 600, TRUE);

	srand((unsigned int)time(NULL));//liczby pseudolosowe
	while (1)//petla uruchamiajaca gre ciagle od nowa
	{
		render_api::clear_screen();
		FILE* plik_zapis = NULL;
		rozgrywka* rozgrywka = NULL;
		int wybor_gracza;
		int wybor_gracza2;
		int wybor_gracza3 = 0;
		wybor_gracza = menu<int>();//wywolanie funkcji menu(wybor gracza co chce zrobic)
		if (wybor_gracza == 1)//jezeli gracz wybral gre
		{
			wybor_gracza2 = rozpoczecie_gry<int>();//wywolanie funkcji w ktorej uzytkownik wybiera w jaki tryb chce zagrac
			if (wybor_gracza2 == 1)//jezeli gracz wybral gre z komputerem
			{
				bot bot;//inicjalizacja klasy dla gry gracz vs bot
				rozgrywka = &bot;
				wybor_gracza3 = 1;//ustawienie wartosci ze gracz chce zaczac od nowa
			}
			else if (wybor_gracza2 == 2)//jezeli gracz wybral gre z drugim graczem
			{
				gracz gracz;//inicjalizacja klasy dla gry gracz vs gracz
				rozgrywka = &gracz;
				wybor_gracza3 = 1;//ustawienie wartosci ze gracz chce zaczac od nowa
			}
			else if (wybor_gracza2 == 3)//jezeli gracz wybral powrot do glownego menu
			{
				continue;//powrot do glownej petli(pokazujacej menu)
			}
		}
		else if (wybor_gracza == 2)//jezeli gracz wybral wczytanie gry
		{
			int rodzaj;
			char nazwa_pliku[101];
			render_api::podaj_nazwę_save();
			while (scanf_s("%s", nazwa_pliku, 101) != 1 || getchar() != '\n')//uzytkownik podaje nazwe pliku z zapisana gra
			{
				render_api::clear_screen();
				render_api::save_read_error();
				Sleep(5000);
				render_api::clear_screen();
				render_api::Czyszczenie_Bufora();
				render_api::podaj_nazwę_save();
			}
			plik_zapis = fopen(nazwa_pliku, "r");//otwarcie pliku do odczytu
			if (plik_zapis == NULL)//jezeli nie udalo sie otworzyc pliku
			{
				render_api::save_error();
				Sleep(2000);
				render_api::clear_screen();
				continue;//powrot do glownego menu
			}
			fscanf(plik_zapis, "%d", &rodzaj);//wczytujemy z pliku jaki jest tryb gry(gracz vs gracz czy gracz vs komputer)
			if (rodzaj == 1)//jezeli tryb to gracz vs komputer
			{
				bot bot;//inicjalizacja klasy dla gry gracz vs komputer
				rozgrywka = &bot;
			}
			else if (rodzaj == 2)//jezeli tryb to komputer vs komputer
			{
				gracz gracz;//inicjalizacja klasy dla gry gracz vs gracz
				rozgrywka = &gracz;
			}
			else//w wyjatkowej sytuacji
			{
				render_api::plik_uszkodzony();
				Sleep(1000);
				continue;//powrot do menu glownego
			}
			wybor_gracza3 = 2;//ustawienie wartosci ze gracz chce wczytac gre
		}
		else if (wybor_gracza == 3)//jezeli wybral pokazanie instrukcji gry
		{
			render_api::instrukcja();
		}
		else if (wybor_gracza == 4)//jezeli gracz wybral zakonczenie programu
		{
			render_api::thx_4_playing();
			exit(0);//KONIEC PROGRAMU
		}
		else//w wyjatkowej sytuacji koniec programu
		{
			render_api::błąd_krytyczny();
			exit(0);//awaryjne zakonczenie programu
		}
		if (wybor_gracza3 == 1)//przeprowadzanie rozgrywki jezeli uzytkownik zaczyna od nowa
		{
			int licznik = 0, czy_zapisac = 0, czy_wygrana = 0;
			rozgrywka->ustawienia();//wywolanie funkcji w ktorej uzytkownicy ustawiaja nicki i statki
			while (1)
			{
				if (licznik == 8)//co 8 rund aby zapytac czy zapisac gre
				{
					render_api::czy_zapisac_gre();
					while (scanf_s("%d", &czy_zapisac) != 1 || czy_zapisac < 1 || czy_zapisac > 2 || getchar() != '\n')//czyszczenie ekranu
					{
						render_api::nie_ma_opcji_zapisu();
					}
					if (czy_zapisac == 2)//jezeli uzytkownik chce zapisac gre
					{
						rozgrywka->zapisywanie();//funkcja do zapisania stanu gry
						break;//powrot do menu glownego
					}
					licznik = 0;//zerowanie licznika
				}
				czy_wygrana = rozgrywka->gra();//wywolanie funkcji do przeprowadzenia 1 tury gry i pobranie wartosci czy ktos wygral
				licznik++;//inkrementacja licznika do zapisania gry
				if (czy_wygrana == 1)//jezeli ktos wygral
				{
					break;//powrot do menu glownego
				}
			}
		}
		else if (wybor_gracza3 == 2)//przeprowadzanie rozgrywki jezeli uzytkownik wczytal gre
		{
			int czy_wczytywanie_udane = 0;
			czy_wczytywanie_udane = rozgrywka->wczytywanie(plik_zapis);//funckja do wczytania stanu gry i pobranie wartosci czy udalo sie wczytac
			if (czy_wczytywanie_udane == 1)//jezeli udalo sie wczytac
			{
				int licznik = 0, czy_zapisac = 0, czy_wygrana = 0;
				render_api::clear_screen();
				while (1)
				{
					if (licznik == 8)//co 8 rund aby zapytac czy zapisac gre
					{
						render_api::czy_zapisac_gre();
						while (scanf_s("%d", &czy_zapisac) != 1 || czy_zapisac < 1 || czy_zapisac > 2 || getchar() != '\n')//czyszczenie ekranu
						{
							render_api::nie_ma_opcji_zapisu();
						}
						if (czy_zapisac == 2)//jezeli uzytkownik chce zapisac gre
						{
							rozgrywka->zapisywanie();//funkcja do zapisania stanu gry
							break;//powrot do menu glownego/
						}
						licznik = 0;//zerowanie licznika
					}
					czy_wygrana = rozgrywka->gra();//wywolanie funkcji do przeprowadzenia 1 tury gry i pobranie wartosci czy ktos wygral
					licznik++;//inkrementacja licznika do zapisania gry
					if (czy_wygrana == 1)//jezeli ktos wygral
					{
						break;//powrot do menu glownego
					}
				}
			}
			else//jezeli nie udalo sie wczytac
			{
				render_api::plik_uszkodzony();
				Sleep(5000);
				continue;//powrot do menu glownego
			}
		}
		else// w wyjatkowej sytuacji
		{
			continue;
		}
	}
}
