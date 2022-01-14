#pragma once
#include <string>
static class render_api {
public:
	render_api();
	static void przerwy(int);//funkcja polimorficzna do ustawienia rzeczy przed rozpoczeciem stzrelania (nick i statki)
	static void instrukcja();
	static void error();
	static void main_menu();
	static void wybor_typu_gry();
	static void opcja_nie_istnieje();
	static void Czyszczenie_Bufora();
	static void niestety_nie_ma_takiej_opcji();
	static void podaj_nazw�_save();
	static void save_error();
	static void save_read_error();
	static void plik_uszkodzony();
	static void thx_4_playing();
	static void czy_zapisac_gre();
	static void nie_ma_opcji_zapisu();
	static void pudlo(int);
	static void trafienie();
	static void przeka�_komputer();
	static void b��dny_nick();
	static void podaj_nick1();
	static void podaj_nick2();
	static void komputer_ustawia_statki();
	static void ruch_wykonuje_komputer();
	static void clear_screen();
	static void ustawkolor(char);
	static void kolorplanszyprzeciwnika(char);
	static void resetkolor();
	static void wypisz_plansze(char plansza1[10][10], char plansza2[10][10]);
	static void b��d_krytyczny();
	static void statystyki(char* nick, char* nick1, char* nick2, int oddane_strza�y1, int oddane_strza�y2, int trafienia1, int trafienia2);
	//renderowanie obu plansz
	static void legenda_planszy();
	static void render_planszy(char plansza1[10][10], char plansza2[10][10]);
	static void render_planszy_gra(char plansza1[10][10], char plansza2[10][10], char plansza2_1[10][10], char plansza2_2[10][10], int typ, unsigned int& oddane_strzaly_1, unsigned int& oddane_strzaly_2, unsigned int& trafienia_1, unsigned int& trafienia_2);
	static void b��dna_wsp�rz�dna();
	static void podaj_wsp�rz�dne();
	static void nie_ma_opcji();
	static void ustawiasz_statek(int, int);
	static void nie_mo�na_postawi�_statku();
	static void podaj_orientacj�();
	static void podaj_nazw�_pliku_do_zapisania_gry();
	static void nie_uda�o_si�();
	static void zapisano_pomy�lnie();
	static void wczytano_pomy�lnie();
	static void zaczyna(char*);
};
