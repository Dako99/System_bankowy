#include "system.h"
#include <Windows.h>		//zamina koloru,
#include <winbase.h>		//aktualny czas
#include <fstream>			//obsluga plikow


using namespace std;


int main() {

	setlocale(LC_ALL, "polish");		//jezyk polski

	SYSTEMTIME st;						//funkcja czasu lokalnego
	GetLocalTime(&st);
	Historia nowa_operacja;				//tworzy obiekt w klasie historia

	vector <Uzytkownik> lista;			//lista wektorowa klasy użytkownik, zawiera dane do kont 
	Uzytkownik nowy;					//tworzy obiekt w klasie uzytkownik
	Pracownik osoba;					//tworzy obiekt w klasie pracownik
	vector <Pracownik> konto;			//lista wektorowa (zawierająca jeden rekord, dane do logowania admina)
	Odbiorca nowy_odbiorca;				//tworzy obiekt w klasie odbiorca
	string login, haslo;

	osoba.DodajPracownika();
	konto.push_back(osoba);

	cout << "Ladowanie Systemu Bankowego" << endl;	//progres bar
	float progres = 0.0;
	while (progres < 1.0) {
		int bar = 50;
		cout << "[";
		int pos = bar * progres;
		for (int i = 0; i < bar; ++i) {
			if (i < pos) cout << "=";
			else if (i == pos) cout << ">";
			else cout << " ";
		}
		cout << "] " << int(progres * 101.0) << " %\r";
		cout.flush();
		progres += 0.005;		//przykladowow
	}
	cout << endl;

	//menu glowne
	int menu_c = 0;
	int menu_min = 0, menu_max = 3;
	//menu użytkownika
	int menu_d = 0;
	int m_min = 0, m_max = 10, in;

	int a = 0;
	float kwota=0;
	int input;

	while (true) {
		system("cls");
		cout << "Po menu poruszaj sie strzalkami gora / dol" << endl;
		cout << "Aby wybrac opcje przy ktorej jest wskaznik nacisnij Enter" << endl;
		cout << (menu_c == 0 ? "> " : "  ") << "Zaloguj sie do systemu" << endl;
		cout << (menu_c == 1 ? "> " : "  ") << "Zaloz konto" << endl;
		cout << (menu_c == 2 ? "> " : "  ") << "Administracja <weryfikacja>" << endl;
		cout << (menu_c == 3 ? "> " : "  ") << "Zamknij program" << endl;

		input = _getch();

		if (input == 0 || input == 224)							//numpad lub strzalki
			switch (_getch()) {
			case 80: if (menu_c < menu_max) menu_c++; else cout << "\a"; break;	//UP
			case 72: if (menu_c > menu_min) menu_c--; else cout << "\a"; break;	//DOWN	
			}
		if (input == 13)										//Enter
			switch (menu_c) {

			case 0:		//zaloguj się
				cout << "Podaj login" << endl;
				cin >> login;
				cout << "Podaj haslo" << endl;
				cin >> haslo;
				for (int i = 0; i < lista.size(); i++)
				{
					if (lista[i].Login() == login && lista[i].Haslo() == haslo)
					{
						cout << "Zalogowano" << endl;
						system("PAUSE");
						system("cls");
						while (a == 0) {
							system("cls");
							cout << "Zalogowano na koncie " << lista[i].Imie() << " " << lista[i].Nazwisko() << endl;
							cout << (menu_d == 0 ? "> " : "  ") << "Pokaz dane mojego konta" << endl;
							cout << (menu_d == 1 ? "> " : "  ") << "Pokaz historie wykonanych operacji na koncie" << endl;
							cout << (menu_d == 2 ? "> " : "  ") << "Pokaz zaplanowane operacje" << endl;
							cout << (menu_d == 3 ? "> " : "  ") << "Dodaj odbiorce przelewu" << endl;
							cout << (menu_d == 4 ? "> " : "  ") << "Zrob przelew" << endl;
							cout << (menu_d == 5 ? "> " : "  ") << "Wyplac gotowke" << endl;
							cout << (menu_d == 6 ? "> " : "  ") << "Wplac gotowke" << endl;
							cout << (menu_d == 7 ? "> " : "  ") << "Sprawdz saldo" << endl;
							cout << (menu_d == 8 ? "> " : "  ") << "Zmien haslo" << endl;
							cout << (menu_d == 9 ? "> " : "  ") << "Wyloguj" << endl;
							cout << (menu_d == 10 ? "> " : "  ") << "Usun konto" << endl;


							in = _getch();
							if (input == 0 || in == 224)
								switch (_getch()) {
								case 80: if (menu_d < m_max) menu_d++; else cout << "\a"; break;
								case 72: if (menu_d > m_min) menu_d--; else cout << "\a"; break;
								}

							if (in == 13)
								switch (menu_d) {

								case 0: //pokaz dane konta
									cout << "Imie: " << lista[i].Imie() << endl;
									cout << "Nazwisko: " << lista[i].Nazwisko() << endl;
									cout << "Nr PESEL: " << lista[i].Pesel() << endl;
									cout << "Numer konta: " << lista[i].NrKonta() << endl;
									cout << "Data urodzenia: " << lista[i].dzien <<"."<<lista[i].miesiac<<"."<<lista[i].rok<<" r." << endl;
									system("PAUSE");
									break;

								case 1: //historia operacji na koncie
									cout << "Historia operacji na koncie jest pusta" << endl;


									for (int j = 0; j < lista[i].historia_operacji.size(); j++) {
										cout << lista[i].historia_operacji[j].godzina << ":" << lista[i].historia_operacji[j].minuta << " " <<
											lista[i].historia_operacji[j].dzien << "." << lista[i].historia_operacji[j].miesiac << "." <<
											lista[i].historia_operacji[j].rok << " " << lista[i].historia_operacji[j].operacja << " ";
										if (lista[i].historia_operacji[j].operacja == "przelew") {
											cout << "na konto " << lista[i].historia_operacji[j].konto_docelowe << " ";
										}
										cout << lista[i].historia_operacji[j].kwota << " zl" << endl;
									}
									system("PAUSE");
									break;


								case 2: //pokaz zaplanowane operacje
									//lista[i].Odczyt();
									cout << "Imie: " << lista[i].Imie() << endl;
									cout << "Nazwisko: " << lista[i].Nazwisko() << endl;
									cout << "Nr PESEL: " << lista[i].Pesel() << endl;
									cout << "Numer konta: " << lista[i].NrKonta() << endl;
									cout << "Data urodzenia: " << lista[i].dzien << "." << lista[i].miesiac << "." << lista[i].rok << " r." << endl;
									system("PAUSE");

									break;
								case 3:  //Dod. odbiorce przelewu
								{ //całośc w klamrze
									cout << endl << "Podaj nazwe nowego odbiorcy (jednym slowem)" << endl;	//w przypadku kilku słów nie zadziała
									cin >> nowy_odbiorca.nazwa;

									int zmienna = 0;
									for (int j = 0; j < lista[i].odbiorcy.size(); j++) {
										if (nowy_odbiorca.nazwa == lista[i].odbiorcy[j].nazwa) {
											cout << "Podana nazwa jest juz zarezerwowana dla innego odbiorcy" << endl;
											zmienna = 1;
											system("PAUSE");
											break;
										}
									}
									if (zmienna == 0) {
										cout << "Podaj numer konta odbiorcy " << endl;
										cin >> nowy_odbiorca.numer_konta;
										for (int j = 0; j < lista[i].odbiorcy.size(); j++) {
											if (nowy_odbiorca.numer_konta == lista[i].odbiorcy[j].numer_konta) {
												cout << "Podany numer jest juz zarezerwowany dla innego odbiorcy" << endl;
												zmienna = 1;
												system("PAUSE");
												break;
											}

										}
									}

									if (zmienna == 0) {
										lista[i].odbiorcy.push_back(nowy_odbiorca);
										cout << "Pelna lista odbiorcow:" << endl;

										for (int j = 0; j < lista[i].odbiorcy.size(); j++) {
											cout << lista[i].odbiorcy[j].nazwa << " " << lista[i].odbiorcy[j].numer_konta << endl;
										}
										system("pause");
									}
								}
								break;
								case 4: //Zrob przelew
								{
									cout << "Podaj nazwe odbiorcy przelewu ";
									cin >> nowy_odbiorca.nazwa;

									int pomoc = 0;
									for (int j = 0; j < lista[i].odbiorcy.size(); j++) {
										if (nowy_odbiorca.nazwa == lista[i].odbiorcy[j].nazwa) {
											nowy_odbiorca.numer_konta = lista[i].odbiorcy[j].numer_konta;
											pomoc = 1;
											break;
										}
									}

									if (pomoc == 0) {
										cout << "Podaj numer konta odbiorcy przelewu" << endl;
										cin >> nowy_odbiorca.numer_konta;
									}

									// część odpowiedzialna za zrobienie przelewu

									cout << "Podaj kwot jaka chcesz przela odbiorcy: ";
									cin >> kwota;
									if (kwota > lista[i].Saldo()) {
										cout << "Nie masz wystarczajaco duzo srodkow na koncie :( ";
										system("PAUSE");
										break;
									}

									SYSTEMTIME st;
									GetLocalTime(&st);
									cout << "Obecny czas" << endl;
									cout << "	Rok: " << st.wYear << endl;
									cout << "	Miesiac: " << st.wMonth << endl;
									cout << "	Dzien: " << st.wDay << endl;
									cout << "	Godzina: " << st.wHour << endl;
									cout << "	Minuta: " << st.wMinute << endl << endl;
									int dzien, miesiac, rok, minuta, godzina;
									cout << "Podaj termin planowanej operacji" << endl;
									cout << "Podaj rok ";
									cin >> rok;
									cout << "Podaj miesiac ";
									cin >> miesiac;
									cout << "Podaj dzien ";
									cin >> dzien;
									cout << "Podaj godzine ";
									cin >> godzina;
									cout << "Podaj minute ";
									cin >> minuta;
									if (rok < st.wYear) {
										cout << "Nie mozna zrobic operacji w przeszlosci";
										break;
									}
									if (rok == st.wYear && miesiac < st.wMonth) {
										cout << "Nie mozna zrobic operacji w przeszlosci";
										break;
									}
									if (rok == st.wYear && miesiac == st.wMonth && dzien < st.wDay) {
										cout << "Nie mozna zrobic operacji w przeszlosci";
										break;
									}
									if (rok == st.wYear && miesiac == st.wMonth && dzien == st.wDay && godzina < st.wHour) {
										cout << "Nie mozna zrobic operacji w przeszlosci";
										break;
									}
									if (rok == st.wYear && miesiac == st.wMonth && dzien == st.wDay && godzina == st.wHour && minuta < st.wHour) {
										cout << "Nie mozna zrobic operacji w przeszlosci";
										system("PAUSE");
										break;
									}
									if (miesiac > 12 || dzien > 31 || godzina > 24 || minuta > 59) {
										cout << "Blad przy wprowadzaniu danych";
										system("PAUSE");
										break;
									}
									cout << "Mysle.." << endl;
									while (1) {
										if (rok == st.wYear && miesiac == st.wMonth && dzien == st.wDay && godzina == st.wHour && minuta == st.wMinute) {
											//lista[i].Saldo() -= kwota;
											for (int j = 0; j < lista.size(); j++) {
												if (nowy_odbiorca.numer_konta == lista[j].NrKonta()) {
													//lista[j].NrKonta() += kwota;
													break;
												}
											}
											cout << "Zrobiono przelew";

											break;
										}
									}


									nowa_operacja.rok = st.wYear;
									nowa_operacja.miesiac = st.wMonth;
									nowa_operacja.dzien = st.wDay;
									nowa_operacja.godzina = st.wHour;
									nowa_operacja.minuta = st.wMinute;
									nowa_operacja.kwota = kwota;
									nowa_operacja.operacja = "przelew";
									nowa_operacja.konto_docelowe = nowy_odbiorca.numer_konta;
									lista[i].historia_operacji.push_back(nowa_operacja);



									system("PAUSE");
								}
								break;
								case 5: //Wyplata
									lista[i].WpiszHaslo();
									lista[i].Wyplata();

									nowa_operacja.rok = st.wYear;
									nowa_operacja.miesiac = st.wMonth;
									nowa_operacja.dzien = st.wDay;
									nowa_operacja.godzina = st.wHour;
									nowa_operacja.minuta = st.wMinute;
									nowa_operacja.kwota = kwota;
									nowa_operacja.operacja = "wplata";
									lista[i].historia_operacji.push_back(nowa_operacja);

									break;
								case 6:	//Wplata
									lista[i].WpiszHaslo();
									lista[i].Wplata();

									nowa_operacja.rok = st.wYear;
									nowa_operacja.miesiac = st.wMonth;
									nowa_operacja.dzien = st.wDay;
									nowa_operacja.godzina = st.wHour;
									nowa_operacja.minuta = st.wMinute;
									nowa_operacja.kwota = kwota;
									nowa_operacja.operacja = "wyplata";
									lista[i].historia_operacji.push_back(nowa_operacja);

									break;
								case 7: //sprawdz Saldo
									cout<<"Twoje saldo wynosi: "<<lista[i].Saldo()<<" zl"<<endl;
									system("PAUSE");
									break;
								case 8: //Zmiana Hasła
									lista[i].WpiszHaslo();
									lista[i].ZmianaHasla();
									cout << "Zaloguj sie ponownie" << endl;
									login = "";
									haslo = "";
									a = 1;
									break;
								case 9:	//wylogowanie
								{
									a = 1;
									login = "";
									haslo = "";
									cout << "Trwa Wylogowywanie z Konta, Prosimy Czekac..." << endl;
									Sleep(2137);
									cout << "Wylogowanie Poprawne" << endl;
									cout << "Dziekujemy i do zobaczenia" << endl;
								}
								break;
								case 10: //usun konto
								{
									lista[i].WpiszHaslo();
									lista.erase(lista.begin() + i);
									cout << "Pomyslnie usunieto konto" << endl;
									login = "";
									haslo = "";
									a = 1;
									break;
								}

								}
						}
					}
				}
				if (a == 0) {
					cout << "Niepoprawne login lub haslo" << endl;
					system("PAUSE");
					// dodac: ponow probe, wyjdz 
				}
				else {
					//cout << "Pomyslnie wylogowano" << endl;
					system("PAUSE");
					a = 0;
				}
				break; // brak niego to nie bug a feature

			case 1:		//załóż konto
				nowy.Dodaj();
				lista.push_back(nowy);
				break;
			case 2:
				cout << "Podaj tajny login ADMINistratora: ";
				cin >> login;
				cout << "Podaj tajne haslo ADMINistratora: ";
				cin >> haslo;
				while(login == konto[0].PracownikLogin() && haslo == konto[0].PracownikHaslo())
				{
					int p;
					cout << "Nacisnij 0 aby wylogowac" << endl;
					cout << "Nacisnij 1 aby wyswietlic baze Klientow"<<endl;

					cin >> p;
					switch (p)
					{
					case 0:
						login = "";
						haslo = "";
					break;

					case 1:
						cout << "Wczytuje dane..." << endl;
						Sleep(2137);
						for (int k = 0; k < lista.size(); k++)
						{
							cout << lista[k].Imie() << endl;
							cout << lista[k].Nazwisko() << endl;
							cout << lista[k].Pesel() << endl;
							cout << lista[k].Login() << endl;
							cout << lista[k].NrKonta() << endl;
							cout << lista[k].Saldo() << endl;
							cout << endl;
						}
					}
				}
				system("PAUSE");
				break;
			case 3:		//zamknij program
				for (int j = 0; j < lista.size(); j++)
				{
					lista[j].Zapis();
				}
				exit(0);
			}
	}
	return 0;
}