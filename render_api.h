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
	static void podaj_nazwê_save();
	static void save_error();
	static void save_read_error();
	static void plik_uszkodzony();
	static void thx_4_playing();
	static void czy_zapisac_gre();
	static void nie_ma_opcji_zapisu();
	static void pudlo(int);
	static void trafienie();
	static void przeka¿_komputer();
	static void b³êdny_nick();
	static void podaj_nick1();
	static void podaj_nick2();
	static void komputer_ustawia_statki();
	static void ruch_wykonuje_komputer();
	static void clear_screen();
	static void ustawkolor(char);
	static void kolorplanszyprzeciwnika(char);
	static void resetkolor();
	static void wypisz_plansze(char plansza1[10][10], char plansza2[10][10]);
	static void b³¹d_krytyczny();
	static void statystyki(char* nick, char* nick1, char* nick2, int oddane_strza³y1, int oddane_strza³y2, int trafienia1, int trafienia2);
	//renderowanie obu plansz
	static void legenda_planszy();
	static void render_planszy(char plansza1[10][10], char plansza2[10][10]);
	static void render_planszy_gra(char plansza1[10][10], char plansza2[10][10], char plansza2_1[10][10], char plansza2_2[10][10], int typ, unsigned int& oddane_strzaly_1, unsigned int& oddane_strzaly_2, unsigned int& trafienia_1, unsigned int& trafienia_2);
	static void b³êdna_wspó³rzêdna();
	static void podaj_wspó³rzêdne();
	static void nie_ma_opcji();
	static void ustawiasz_statek(int, int);
	static void nie_mo¿na_postawiæ_statku();
	static void podaj_orientacjê();
	static void podaj_nazwê_pliku_do_zapisania_gry();
	static void nie_uda³o_siê();
	static void zapisano_pomyœlnie();
	static void wczytano_pomyœlnie();
	static void zaczyna(char*);
};
