class rozgrywka
{
protected:
	//zmienne potrzebne do gry
	unsigned int tryb_gry;
	char nick1[21];
	char nick2[21];
	char plansza1_1[10][10];
	char plansza1_2[10][10];
	char plansza2_1[10][10];
	char plansza2_2[10][10];
	unsigned int oddane_strzaly_1;
	unsigned int oddane_strzaly_2;
	unsigned int trafienia_1;
	unsigned int trafienia_2;
public:
	rozgrywka();//konstruktor
	virtual void ustawienia() = 0;//funkcja polimorficzna do ustawienia rzeczy przed rozpoczeciem stzrelania (nick i statki)
	virtual int gra() = 0;//funkcja polimorficzna ktora "przeprowadza" gre
protected:
	void pokaz_plansze(char plansza1[10][10], char plansza2[10][10]);//funkcja pokazujaca odpowiednie plansze
	int czy_wygrana(char plansza[10][10]);//funkcja sprawdza czy ktos juz nie zatopil wszystkich statkow
	void podawanie_pozycji(unsigned int* wspol_x, unsigned int* wspol_y);///funkcja w ktorej uzytkownik podaje X Y statku
	void wygrana(char nick[]);//funkcja wyswietla statystyki jezeli ktos wygral i konczy gre(wraca do menu)
	int strzal(char plansza1[10][10], char plansza2[10][10]);//funkcja w ktorej uzytkownik strzela
	void podawanie_orientacji_statku(unsigned int* orientacja);//funkcja w ktorej uzytkownik podaje orientacje przy stawianiu statku
	int czy_moze_tu_stac(unsigned int wspolrzedna_x, unsigned int wspolrzedna_y, char plansza[10][10]);//funckja sprawdza czy na podanych koordynatach moze stac statek
	void ustawienie_statkow(char plansza1[10][10], char plansza2[10][10]);//funkcja w ktorej ustawia sie statki
public:
	void zapisywanie(void);//funkcja do zapisania postepu gry do pliku
	int wczytywanie(FILE* plik);//funkcja do odczytania postepu gry z pliku
};
