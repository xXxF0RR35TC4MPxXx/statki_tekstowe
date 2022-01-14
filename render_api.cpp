#include <string>
#include <Windows.h>
#include <time.h>
#include <iostream>
#include "dziedziczace.h"
#include "render_api.h"

#pragma warning(disable:4996)
using namespace std;

void render_api::Czyszczenie_Bufora(void)//czyszczenie bufora
{
	while (getchar() != '\n') {}
}

render_api::render_api() {

}

void render_api::pudlo(int typ) {
	if (typ == 0) {
		printf("\n\x1B[91m                                                       Pud\210o !\033[0m\n");
	}
	else if (typ == 1) {
		printf("\nStrzela\210e\230 ju\230 w to miejsce ! Strata kolejki\n");
	}

}

void render_api::przeka�_komputer() {
	for (int i = 0; i < 3; i++)//odczekanie 3 sekund aby gracze mogli sobie przekazac komputer
	{
		render_api::clear_screen();
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		przerwy(32); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
		przerwy(32); printf("\xba                                                   \xba\n");
		przerwy(32); printf("\xba      Przeka\276 komputer drugiemu graczowi ! %d       \xba\n", 3 - i);
		przerwy(32); printf("\xba                                                   \xba\n");
		przerwy(32); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
		Sleep(1000);
	}
}

void render_api::podaj_nick1() {
	clear_screen();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	przerwy(32); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(32); printf("\xba                                                   \xba\n");
	przerwy(32); printf("\xba            Podaj sw\242j nick(bez spacji):           \xba\n");
	przerwy(32); printf("\xba                                                   \xba\n");
	przerwy(32); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

}

void render_api::komputer_ustawia_statki() {
	clear_screen();//czyszczenie ekranu
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	przerwy(35); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(35); printf("\xba                                              \xba\n");
	przerwy(35); printf("\xba           Komputer ustawia statki            \xba\n");
	przerwy(35); printf("\xba                                              \xba\n");
	przerwy(35); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

}
void render_api::podaj_nick2() {
	przerwy(40); cout << "Podaj sw\242j nick(bez spacji):";
}
void render_api::clear_screen() {
	system("cls");
}

void render_api::ruch_wykonuje_komputer() {
	render_api::clear_screen();//czyszczenie ekranu
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	przerwy(35); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(35); printf("\xba                                              \xba\n");
	przerwy(35); printf("\xba           Ruch wykonuje \033[91mkomputer\033[0m!            \xba\n");
	przerwy(35); printf("\xba                                              \xba\n");
	przerwy(35); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	Sleep(1000);
}



void render_api::b��dny_nick() {
	render_api::clear_screen();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	przerwy(6); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(6); printf("\xba                                                                                                        \xba\n");
	przerwy(6); printf("\xba Poda\210e\230 b\210\251dnie sw\242j nick(Sprawd\253 czy Twoj nick ma max 20 znak\242w i jest bez spacji). Spr\242buj ponownie! \xba\n");
	przerwy(6); printf("\xba                                                                                                        \xba\n");
	przerwy(6); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	przerwy(50); 
	Czyszczenie_Bufora();
	clear_screen();
}

void render_api::trafienie() {
	printf("\n                                                      \x1B[92mTrafienie !\033[0m\n");

}

void render_api::main_menu() {
	for (int i = 0; i < 9; i++)
		cout << ("\n");

	przerwy(40); cout << ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(40); cout << ("\xba     \033[91m-\033[93m-\033[92m-\033[96m-\033[36m-\033[95m-\033[0m     STATKI     \033[95m-\033[36m-\033[96m-\033[92m-\033[93m-\033[91m-\033[0m     \xba\n");
	przerwy(40); cout << ("\xba                                      \xba\n");
	przerwy(40); cout << ("\xba             1.Nowa gra               \xba\n");
	przerwy(40); cout << ("\xba            2.Wczytaj gr\251             \xba\n");
	przerwy(40); cout << ("\xba            3.Instrukcja              \xba\n");
	przerwy(40); cout << ("\xba          4.Zako\344cz program           \xba\n");
	przerwy(40); cout << ("\xba                                      \xba\n");
	przerwy(40); cout << ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	przerwy(50); cout << "Tw\242j wyb\242r:\t";
}

void render_api::opcja_nie_istnieje() {
	printf("\nNie ma takiej opcji. Popraw:\t");
	while (getchar() != '\n') {}//czyszczenie bufora
}

void render_api::niestety_nie_ma_takiej_opcji() {
	system("cls");//czyszczenie ekranu
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	przerwy(35); cout << ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(35); cout << ("\xba                                                 \xba\n");
	przerwy(35); cout << ("\xba Niestety nie ma takiej opcji. Spr\242buj ponownie! \xba\n");
	przerwy(35); cout << ("\xba                                                 \xba\n");
	przerwy(35); cout << ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	przerwy(50); printf("Tw\242j wyb\242r:\t");
	Czyszczenie_Bufora();//funkcja czyszczaca bufor
}

void render_api::wybor_typu_gry() {
	for (int i = 0; i < 10; i++)
		cout << ("\n");

	przerwy(40); cout << ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(40); cout << ("\xba     \033[91m-\033[93m-\033[92m-\033[96m-\033[36m-\033[95m-\033[0m     STATKI     \033[95m-\033[36m-\033[96m-\033[92m-\033[93m-\033[91m-\033[0m     \xba\n");
	przerwy(40); cout << ("\xba                                      \xba\n");
	przerwy(40); cout << ("\xba         1.Gra z komputerem           \xba\n");
	przerwy(40); cout << ("\xba        2.Gra z innym graczem         \xba\n");
	przerwy(40); cout << ("\xba               3.Wyjd\253                \xba\n");
	przerwy(40); cout << ("\xba                                      \xba\n");
	przerwy(40); cout << ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	przerwy(50); cout << "Tw\242j wyb\242r:\t";
}

void render_api::error() {

}
void render_api::instrukcja() {
	for (int i = 0; i < 5; i++)
		cout << ("\n");
	przerwy(20); cout << ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(20); cout << ("\xba                          \033[91m-\033[93m-\033[92m-\033[96m-\033[36m-\033[95m-\033[0m     STATKI     \033[95m-\033[36m-\033[96m-\033[92m-\033[93m-\033[91m-\033[0m                          \xba\n");
	przerwy(20); cout << ("\xba                                                                                \xba\n");
	przerwy(20); cout << ("\xba                                 \033[92mTwoja plansza:\033[0m                                 \xba\n");
	przerwy(20); cout << ("\xba  1. Oznaczenia '\033[92m1-4\033[0m' informuj\245 gdzie stoj\245 oraz ilu masztowe s\245 Twoje statki   \xba\n");
	przerwy(20); cout << ("\xba         2. Symbol '\033[92m.\033[0m' oznacza miejsce spud\210owanego strza\210u przeciwnika         \xba\n");
	przerwy(20); cout << ("\xba        3. Znak '\033[91mx\033[0m' symbolizuje trafienie Twojego statku przez przeciwnika      \xba\n");
	przerwy(20); cout << ("\xba                                                                                \xba\n");
	przerwy(20); cout << ("\xba                             \033[91mPlansza przeciwnika:\033[0m                               \xba\n");
	przerwy(20); cout << ("\xba         1. Oznaczenia '\033[92m1-4\033[0m' informuj\245 w ilu masztowy statek trafi\210e\230           \xba\n");
	przerwy(20); cout << ("\xba                  2. Symbol '\033[91m.\033[0m' oznacza spud\210owany strza\210                       \xba\n");
	przerwy(20); cout << ("\xba                                                                                \xba\n");
	przerwy(20); cout << ("\xba                              \033[93mInformacje og\242lne:\033[0m                                \xba\n");
	przerwy(20); cout << ("\xba        1. Gr\251 wygrywa gracz, kt\242ry jako pierwszy zatopi wszystkie statki       \xba\n");
	przerwy(20); cout << ("\xba          przeciwnika: cztery statki 1 masztowe, trzy statki dwumasztowe,       \xba\n");
	przerwy(20); cout << ("\xba               dwa statki trzymasztowe, jeden statek czteromasztowy             \xba\n");
	przerwy(20); cout << ("\xba               2. Opcja zapisania gry pojawia si\251 co 4 tury                     \xba\n");
	przerwy(20); cout << ("\xba             3. Statki nie mog\245 znajdowa\206 si\251 na planszy obok siebie            \xba\n");
	przerwy(20); cout << ("\xba                                                                                \xba\n");
	przerwy(20); cout << ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	przerwy(45); system("PAUSE");
	system("cls");//wyczyszczenie ekranu
}

void render_api::podaj_nazw�_save() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	przerwy(20); cout << ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(20); cout << ("\xba                                                                               \xba\n");
	przerwy(20); cout << ("\xba                                                                               \xba\n");
	przerwy(20); cout << ("\xba                        Podaj nazw\251 pliku z zapisem gry:                       \xba\n");
	przerwy(20); cout << ("\xba                                                                               \xba\n");
	przerwy(20); cout << ("\xba                                                                               \xba\n");
	przerwy(20); cout << ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	przerwy(55);
}

void render_api::save_error() {
	system("cls");//czyszczenie ekranu
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	przerwy(12); cout << ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(12); cout << ("\xba                                                                                                     \xba\n");
	przerwy(12); cout << ("\xba                                                                                                     \xba\n");
	przerwy(12); cout << ("\xba                     Niestety nie uda\210o si\251 otworzy\206 pliku o podanej nazwie !                        \xba\n");
	przerwy(12); cout << ("\xba                                                                                                     \xba\n");
	przerwy(12); cout << ("\xba                                                                                                     \xba\n");
	przerwy(12); cout << ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

}

void render_api::save_read_error() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	przerwy(5); cout << ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(5); cout << ("\xba                                                                                                                \xba\n");
	przerwy(5); cout << ("\xba                                                                                                                \xba\n");
	przerwy(5); cout << ("\xba Niestety wyst\245pi\210 \033[91mb\210\245d\033[0m. Upewnij si\251, ze nie u\276y\210e\230 \033[93mspacji\033[0m lub nazwa pliku nie jest zbyt d\210uga(max 100 znak\242w)! \xba\n");
	przerwy(5); cout << ("\xba                                                                                                                \xba\n");
	przerwy(5); cout << ("\xba                                                                                                                \xba\n");
	przerwy(5); cout << ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

}

void render_api::plik_uszkodzony() {
	clear_screen();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	przerwy(25); cout << ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(25); cout << ("\xba                                                                         \xba\n");
	przerwy(25); cout << ("\xba                                                                         \xba\n");
	przerwy(25); cout << ("\xba     Plik jest \033[91muszkodzony\033[0m. Niestety nie uda\210o sie wczyta\206 stanu gry      \xba\n");
	przerwy(25); cout << ("\xba                                                                         \xba\n");
	przerwy(25); cout << ("\xba                                                                         \xba\n");
	przerwy(25); cout << ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

}

void render_api::thx_4_playing() {
	clear_screen();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	przerwy(42); cout << ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(42); cout << ("\xba                               \xba\n");
	przerwy(42); cout << ("\xba     Thanks 4 playing \033[91m<3\033[0m       \xba\n");
	przerwy(42); cout << ("\xba        Mateusz Je\276ewski       \xba\n");
	przerwy(42); cout << ("\xba         Pawe\210 Awramiuk        \xba\n");
	przerwy(42); cout << ("\xba      Gabriel Chomiczewski     \xba\n");
	przerwy(42); cout << ("\xba                               \xba\n");
	przerwy(42); cout << ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	przerwy(42); system("PAUSE");
}

void render_api::czy_zapisac_gre() {
	clear_screen();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	przerwy(35); cout << ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(35); cout << ("\xba                                                 \xba\n");
	przerwy(35); cout << ("\xba         Czy chcesz zapisa\206 gr\251 i wyj\230\206 ?        \xba\n");
	przerwy(35); cout << ("\xba               \033[91m(1) - Nie\033[0m\t\033[92m(2) - Tak\033[0m            \xba\n");
	przerwy(35); cout << ("\xba                                                 \xba\n");
	przerwy(35); cout << ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	przerwy(50); cout << "Tw\242j wyb\242r:\t";
}

void render_api::nie_ma_opcji_zapisu() {
	clear_screen();
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
	przerwy(35); cout << ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(35); cout << ("\xba                                                 \xba\n");
	przerwy(35); cout << ("\xba Niestety nie ma takiej opcji. Spr\242buj ponownie! \xba\n");
	przerwy(35); cout << ("\xba         Czy chcesz zapisa\206 gr\251 i wyj\230\206 ?        \xba\n");
	przerwy(35); cout << ("\xba               \033[91m(1) - Nie\033[0m\t\033[92m(2) - Tak\033[0m            \xba\n");
	przerwy(35); cout << ("\xba                                                 \xba\n");
	przerwy(35); cout << ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	przerwy(50); cout << "Tw\242j wyb\242r:\t";
	Czyszczenie_Bufora();//czyszczenie bufora
}

void render_api::przerwy(int x)
{
	for (int i = 0; i < x; i++) {
		cout << " ";
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void render_api::ustawkolor(char c)
{
	if (c == 'x') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 156); //czerwony
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 154); //zielony
}
void render_api::kolorplanszyprzeciwnika(char c)
{
	if (c == '.') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 156); //czerwony
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 154); //zielony
}

void render_api::resetkolor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
}

void render_api::legenda_planszy() {
	przerwy(20); printf("    \x1B[92m 1  2  3  4  5  6  7  8  9 10\t           \x1B[91m1  2  3  4  5  6  7  8  9 10\033[0m\n");

}

void render_api::b��dna_wsp�rz�dna() {
	printf("\nB\210\251dna wsp\242\210rzedna. Popraw:\t");
	Czyszczenie_Bufora();
}

void render_api::podaj_wsp�rz�dne() {
	printf("\n\n");
	przerwy(30); printf("Podaj wsp\242\210rz\251dne gdzie chcesz strzeli\206 X Y:\t");
}



void render_api::wypisz_plansze(char plansza1[10][10], char plansza2[10][10]) {
	printf("\n\n\n\n\n\n\n");
	przerwy(30);
	printf("\x1B[92mTwoja plansza:\t\t\t      \x1B[91mPlansza przeciwnika:\033[0m\n\n");
	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
		{
			legenda_planszy();
		}
		else if (i == 1)
		{
			przerwy(20); printf("   \x1B[92m\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\t         \x1B[91m\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\033[0m\n");
		}
		//zielony - \x1B[92m
		//czerwony - \x1B[91m
		//reset - \033[0m
		else if (i == 2)
		{
			for (int k = 0; k < 10; k++)
			{
				if (k < 9)
				{
					przerwy(20); printf(" \x1B[92m%d \xba\033[0m", k + 1);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 154);
					for (int j = 0; j < 9; j++)
					{
						ustawkolor(plansza1[k][j]); printf(" %c ", plansza1[k][j]);
					}
					ustawkolor(plansza1[k][9]); printf(" %c", plansza1[k][9]); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
					printf("\x1B[92m\xba\033[0m\t        \x1B[91m%d\xba\033[0m", k + 1);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 156);
					for (int j = 0; j < 9; j++)
					{
						kolorplanszyprzeciwnika(plansza2[k][j]); printf(" %c ", plansza2[k][j]);
					}
					kolorplanszyprzeciwnika(plansza2[k][9]); printf(" %c", plansza2[k][9]);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
					printf("\x1B[91m\xba\033[0m");
					printf("\n");
				}
				else
				{
					przerwy(20); printf("\x1B[92m%d \xba\033[0m", k + 1);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 154);
					for (int j = 0; j < 9; j++)
					{
						ustawkolor(plansza1[k][j]); printf(" %c ", plansza1[k][j]);
					}
					ustawkolor(plansza1[k][9]); printf(" %c", plansza1[k][9]); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
					printf("\x1B[92m\xba\t       \x1B[91m%d\xba\033[0m", k + 1);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 156);
					for (int j = 0; j < 9; j++)
					{
						kolorplanszyprzeciwnika(plansza2[k][j]); printf(" %c ", plansza2[k][j]);
					}
					kolorplanszyprzeciwnika(plansza2[k][9]); printf(" %c", plansza2[k][9]); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 156);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
					printf("\x1B[91m\xba\033[0m");
					printf("\n");
				}
			}
		}
		else if (i == 3)
		{
			przerwy(20); printf("   \x1B[92m\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\t         \x1B[91m\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\033[0m\n");
		}
	}
}


void render_api::b��d_krytyczny()
{
	clear_screen();
	for (int i = 0; i < 13; i++)
		cout << ("\n");
	przerwy(45); cout << ("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(45); cout << ("\xba                          \xba\n");
	przerwy(45); cout << ("\xba                          \xba\n");
	przerwy(45); cout << ("\xba     B\210\245d krytyczny !     \xba\n");
	przerwy(45); cout << ("\xba                          \xba\n");
	przerwy(45); cout << ("\xba                          \xba\n");
	przerwy(45); cout << ("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	przerwy(45);
}

void render_api::render_planszy_gra(char plansza1[10][10], char plansza2[10][10], char plansza2_1[10][10], char plansza2_2[10][10], int typ, unsigned int& oddane_strzaly_1, unsigned int& oddane_strzaly_2, unsigned int& trafienia_1, unsigned int& trafienia_2) {

	
}


void render_api::render_planszy(char plansza1[10][10], char plansza2[10][10]) {

	
}

void render_api::nie_ma_opcji() {
	cout << "\nNiestety taka opcja nie istnieje. Spr\242buj ponownie ! :)";
	Czyszczenie_Bufora();//funkcja czyszczaca bufor
	printf("\nTw\242j wyb\242r:\t");
}

void render_api::ustawiasz_statek(int typ, int nr) {
	printf("Ustawiasz statek %d masztowy(%d/%d) !\nPodaj wsp\242\210rz\251dn\245 X Y: \t",typ, nr, 5-typ);
}

void render_api::nie_mo�na_postawi�_statku() {
	printf("\nNie mo\276na postawi\206 statku na tej pozycji !\nPodaj now\245 wsp\242\210rz\251dn\245 X Y: \t");
}

void render_api::podaj_orientacj�() {
	printf("Podaj orientacj\251 statku\n1 - w g\242r\251\n2 - w prawo\n3 - w lewo\n4 - w d\242\210\n");
}

void render_api::podaj_nazw�_pliku_do_zapisania_gry() {
	clear_screen();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	przerwy(32); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(32); printf("\xba                                                   \xba\n");
	przerwy(32); printf("\xba        Podaj nazw\251 pliku do zapisania gry:        \xba\n");
	przerwy(32); printf("\xba                                                   \xba\n");
	przerwy(32); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

	przerwy(55);
}

void render_api::nie_uda�o_si�() {
	cout << endl << "Niestety nie uda\210o sie utworzy\206 pliku o podanej nazwie !";
}

void render_api::zapisano_pomy�lnie() {
	clear_screen();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	przerwy(32); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(32); printf("\xba                                                   \xba\n");
	przerwy(32); printf("\xba                Zapisano pomy\230lnie !               \xba\n");
	przerwy(32); printf("\xba                                                   \xba\n");
	przerwy(32); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

}

void render_api::wczytano_pomy�lnie() {
	clear_screen();
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
	przerwy(40); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(40); printf("\xba                                    \xba\n");
	przerwy(40); printf("\xba         Wczytano \033[92mpomy\230lnie\033[0m !       \xba\n");
	przerwy(40); printf("\xba                                    \xba\n");
	przerwy(40); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

}

void render_api::zaczyna(char* nick1) {
	for (int i = 3; i > 0; i--)//informacja kto zaczyna gre po wczytaniu stanu gry
	{
		system("cls");//czyszczenie ekranu
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		przerwy(40); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
		przerwy(40); printf("\xba                                    \xba\n");

		przerwy(40); printf("\xba        Zaczyna \033[92m%s\033[0m ! %d         \xba\n", nick1, i);
		przerwy(40); printf("\xba                                    \xba\n");
		przerwy(40); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
		Sleep(1000);
	}
}

void render_api::statystyki(char* nick, char* nick1, char* nick2, int oddane_strza�y1, int oddane_strza�y2, int trafienia1, int trafienia2) {
	system("cls");//czyszczenie ekranu
	printf("\n\n\n\n\n\n\n");
	przerwy(55); printf("Wygra\210 %s!", nick);
	string tekst = ("\xba                       %s:                         \xba\n", nick1);
	int wolnemiejsce = (int)(120 - tekst.length()) / 3.5;

	printf("\n\n\n\n");
	przerwy(wolnemiejsce); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
	przerwy(wolnemiejsce); printf("\xba                                                     \xba\n");
	przerwy(wolnemiejsce); printf("\xba                      STATYSTYKI:                    \xba\n");
	przerwy(wolnemiejsce); printf("\xba\t%s:                                      \xba\n", nick1);
	przerwy(wolnemiejsce); printf("\xba Oddanych strza\210\242w: %d \tTrafione strza\210y:  %d \xba\n", oddane_strza�y1, trafienia1);
	przerwy(wolnemiejsce); printf("\xba                                                     \xba\n");
	przerwy(wolnemiejsce); printf("\xba\t%s:                                     \xba\n", nick2);
	przerwy(wolnemiejsce); printf("\xba Oddanych strza\210\242w: %d \tTrafione strza\210y:   %d \xba\n", oddane_strza�y2, trafienia2);
	przerwy(wolnemiejsce); printf("\xba                                                     \xba\n");
	przerwy(wolnemiejsce); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
	Sleep(1000);
	przerwy(50); system("PAUSE");
}
