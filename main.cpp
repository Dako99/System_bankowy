#include "system.h"

#include <Windows.h>		//zamina koloru, czas
#include <winbase.h>		//aktualny czas
//#include <time.h>			//czas

using namespace std;


int main() {

	setlocale(LC_ALL, "polish");		//jezyk polski

	vector <Uzytkownik> lista;
	Uzytkownik nowy;				//tworzy obiekt
	Odbiorca nowy_odbiorca;
	string login, haslo;

	//cout << "£adowanie Systemu Bankowego" << endl;	//fake progres
	//float progres = 0.0;
 //	while (progres < 1.0) {
	//	int bar = 50;
	//	cout << "[";
	//	int pos = bar * progres;
	//	for (int i = 0; i < bar; ++i) {
	//		if (i < pos) cout << "=";
	//		else if (i == pos) cout << ">";
	//		else cout << " ";
	//	}
	//	cout << "] " << int(progres * 101.0) << " %\r";
	//	cout.flush();
	//	progres += 0.005;		//przykladowow
	//}
	//cout << endl;

	//srand(time(NULL));
	//int losowa = rand() % 1000 + 0;
	//= ((float)rand() / RAND_MAX) * 1;

	//menu glowne
	int menu_c = 0;
	int menu_min = 0, menu_max = 2;
	//menu u¿ytkownika
	int menu_d = 0;
	int m_min = 0, m_max = 10, in;

	int a = 0;
	float kwota;
	int input;

	while (true) {
		system("cls");
		/*HANDLE kolor;                             //zamina koloru
		kolor = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(kolor, 10);
		SetConsoleTextAttribute(kolor, 6);*/
		cout << "Po menu poruszaj sie strzalkami gora / dol" << endl;
		cout << "Aby wybrac opcje przy ktorej jest wskaznik nacisnij Enter" << endl;
		cout << (menu_c == 0 ? "> " : "  ") << "Zaloguj sie do systemu" << endl;
		cout << (menu_c == 1 ? "> " : "  ") << "Zaloz konto" << endl;

		cout << (menu_c == 2 ? "> " : "  ") << "Zamknij program" << endl;

		input = _getch();

		if (input == 0 || input == 224)							//numpad lub strzalki
			switch (_getch()) {
			case 80: if (menu_c < menu_max) menu_c++; else cout << "\a"; break;	//UP
			case 72: if (menu_c > menu_min) menu_c--; else cout << "\a"; break;	//DOWN	
			}
		if (input == 13)										//Enter
			switch (menu_c) {

			case 0:		//zaloguj siê
				cout << "Podaj login" << endl;
				cin >> login;
				cout << "Podaj haslo (Fajnie jakby nie bylo widac)" << endl;
				cin >> haslo;
				for (int i = 0; i < lista.size(); i++) {
					if (lista[i].Login() == login && lista[i].Haslo() == haslo) {
						cout << "Zalogowano" << endl;
						system("PAUSE");
						system("cls");
						while (true) {
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
									cout << "Numer konta: " << "<Trzeba dodac>" << endl;
									cout << "Data urodzenia: " << "<Trzeba dodac>" << endl;
									system("PAUSE");
									break;
								case 1:
									cout << "Historia operacji na koncie jest pusta" << endl;
									system("PAUSE");
									break;
								case 2:

									break;
								case 3:  //ca³y case musi byæ w klamrze, bo inaczej nie zadzia³a
								{
									cout << endl << "Podaj nazwe nowego odbiorcy (jednym slowem)" << endl;	//w przypadku kilku s³ów nie zadzia³a
									cin >> nowy_odbiorca.nazwa;

									/*int zmienna = 0;
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
									}*/
								}
								break;
								case 4: //Zrob przelew
								{
									cout << "Podaj nazwe odbiorcy przelewu ";
									cin >> nowy_odbiorca.nazwa;

									int pomoc = 0;
									/*for (int j = 0; j < lista[i].odbiorcy.size(); j++) {
										if (nowy_odbiorca.nazwa == lista[i].odbiorcy[j].nazwa) {
											nowy_odbiorca.numer_konta = lista[i].odbiorcy[j].numer_konta;
											pomoc = 1;
											break;
										}
								}*/

								if (pomoc == 0) {
									cout << "Podaj numer konta odbiorcy przelewu" << endl;
									cin >> nowy_odbiorca.numer_konta;

								}

								// czêœæ odpowiedzialna za zrobienie przelewu
								cout << "Podaj kwotê jaka chcesz przelaæ odbiorcy ";
								cin >> kwota;
								/*if (kwota > lista[i].saldo) {
									cout << "Nie masz wystarczajaco duzo srodkow na koncie :( ";
									system("PAUSE");
									break;
								}*/

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
								/*while (1) {
									if (rok == st.wYear && miesiac == st.wMonth && dzien == st.wDay && godzina == st.wHour && minuta == st.wMinute) {
										lista[i].saldo = lista[i].saldo - kwota;
										for (int j = 0; j < lista.size(); j++) {
											if (nowy_odbiorca.numer_konta == lista[j].numer_konta) {
												lista[j].numer_konta = lista[j].numer_konta + kwota;
												break;
											}
										}
										cout << "Zrobiono przelew";

										break;
									}
								}*/
								system("PAUSE");
								}
							break;
			case 5:
				lista[i].WpiszHaslo();
				lista[i].Wyplata();
				break;
			case 6:
				lista[i].WpiszHaslo();
				lista[i].Wplata();
				break;
			case 7: //sprawdz saldo
				lista[i].Saldo();
				break;
			case 8: //zmiana has³a
				lista[i].WpiszHaslo();
				lista[i].ZmianaHasla();
				cout << "Zaloguj sie ponownie" << endl;
				login = "";
				haslo = "";
				a = 1;
				break;
			case 9:	//wylogowanie i zamkniêcie
				a = 1;
				login = "";
				haslo = "";
				break;
			case 10:
				lista[i].WpiszHaslo();
				lista.erase(lista.begin() + i);
				cout << "Pomyslnie usunieto konto" << endl;
				login = "";
				haslo = "";
				a = 1;
				//wypierdala jakis vector w kosmos
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
			cout << "Pomyslnie wylogowano" << endl;
			system("PAUSE");
			a = 0;
		}
		break;

			case 1:		//za³ó¿ konto
				nowy.dodaj();
				lista.push_back(nowy);
				break;

			case 2:		//zamknij program
				for (int j = 0; j < lista.size(); j++)
				{
					lista[j].Zapis();
				}
				exit(0);
	}
}
return 0;
}