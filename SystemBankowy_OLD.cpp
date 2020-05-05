#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include<vector>
#include<string>

using namespace std;

class Uzytkownik {
public:
	string imie;
	string nazwisko;
	int pesel;
	struct data_urodzenia {
		int dzien;
		int miesiac;
		int rok;
	};
	string login;
	string haslo;

	void dodaj() {
		cout << "Podaj imie" << endl;
		cin >> imie;
		cout << "Podaj nazwisko" << endl;
		cin >> nazwisko;
		cout << "Podaj pesel" << endl;
		cin >> pesel;
		cout << "(Nie wiem jak dodac date urodzenia)" << endl;
		cout << "Podaj login" << endl;
		cin >> login;
		cout << "Podaj haslo (Fajnie gdyby nie bylo go widac przy wprowadzaniu)" << endl;
		cin >> haslo;
		cout << "Utworzono konto" << endl;
		system("PAUSE");
	}

};
class Pracownik {

};
class Konto {
	int numer_konta;
	float saldo;

};
int main() {

	vector <Uzytkownik> lista;
	Uzytkownik nowy;
	string login, haslo;

	int menu_c = 0;
	int menu_min = 0;
	int menu_max = 2;

	int menu_d = 0;
	int m_min = 0, m_max = 7, in;
	int input;
	while (true) {
		system("cls");
		cout << "Po menu poruszaj sie strzalkami gora / dol" << endl;
		cout << "Aby wybrac opcje przy ktorej jest wskaznik nacisnij Enter" << endl;
		cout << (menu_c == 0 ? "> " : "  ") << "Zaloguj sie do systemu" << endl;
		cout << (menu_c == 1 ? "> " : "  ") << "Zaloz konto" << endl;
		cout << (menu_c == 2 ? "> " : "  ") << "Zamknij program" << endl;


		input = _getch();
		if (input == 224)
			switch (_getch()) {
			case 80: if (menu_c < menu_max) menu_c++; break;
			case 72: if (menu_c > menu_min) menu_c--; break;
			}
		if (input == 13)
			switch (menu_c) {

			case 0: //zaloguj się
				cout << "Podaj login" << endl;
				cin >> login;
				cout << "Podaj haslo (Fajnie jakby nie bylo widac)" << endl;
				cin >> haslo;
				for (int i = 0; i < lista.size(); i++) {
					if (lista[i].login == login && lista[i].haslo == haslo) {
						cout << "Zalogowano" << endl;
						system("PAUSE");
						system("cls");
						while (true) {
							system("cls");
							cout << "Zalogowano na koncie " << lista[i].imie << " " << lista[i].nazwisko << endl;
							cout << (menu_d == 0 ? "> " : "  ") << "Pokaz dane mojego konta" << endl;
							cout << (menu_d == 1 ? "> " : "  ") << "Pokaz historie wykonanych operacji na koncie" << endl;
							cout << (menu_d == 2 ? "> " : "  ") << "Pokaz zaplanowane operacje" << endl;
							cout << (menu_d == 3 ? "> " : "  ") << "Dodaj odbiorce przelewu" << endl;
							cout << (menu_d == 4 ? "> " : "  ") << "Zrob przelew" << endl;
							cout << (menu_d == 5 ? "> " : "  ") << "Wyplac gotowke" << endl;
							cout << (menu_d == 6 ? "> " : "  ") << "Wplac gotowke" << endl;
							cout << (menu_d == 7 ? "> " : "  ") << "Wyloguj" << endl;


							in = _getch();
							if (in == 224)
								switch (_getch()) {
								case 80: if (menu_d < m_max) menu_d++; break;
								case 72: if (menu_d > m_min) menu_d--; break;
								}
							if (in == 13)
								switch (menu_d) {

								case 0: //pokaz dane konta
									cout << "imie: " << lista[i].imie << endl;
									cout << "nazwisko: " << lista[i].nazwisko << endl;
									cout << "numer konta: " << "Trzeba dodac" << endl;
									system("PAUSE");
									break;
								case 1: break;
								case 2: break;
								case 3: break;
								case 4: break;
								case 5: break;
								case 6: break;
								case 7: //wylogowanie
									break;

								}
						}
					}
				}
				cout << "Niepoprawne login lub haslo" << endl;
				system("PAUSE");
				break;

			case 1: //załóż konto
				nowy.dodaj();
				lista.push_back(nowy);
				break;

			case 2: //zamknij program
				exit(0);
			}
	}
	return 0;

}
