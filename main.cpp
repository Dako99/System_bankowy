#include "system.h"

//#include <Windows.h>		//zamina koloru, czas
//#include <time.h>			//czas

using namespace std;

int main() {

	setlocale(LC_ALL, "polish");		//jezyk polski

	vector <Uzytkownik> lista;
	Uzytkownik nowy;				//tworzy obiekt
	string login, haslo;
	

	cout << "£adowanie Systemu Bankowego" << endl;	//fake progres
	
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
	cout << endl;

	//srand(time(NULL));
	//int losowa = rand() % 1000 + 0;
	//= ((float)rand() / RAND_MAX) * 1;

	int menu_c = 0;					//menu glowne
	int menu_min = 0, menu_max = 2;

	int menu_d = 0;					//menu u¿ytkownika
	int m_min = 0, m_max = 8, in;

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
							cout << (menu_d == 8 ? "> " : "  ") << "Wyloguj i wyjdz" << endl;
							cout << (menu_d == 9 ? "> " : "  ") << "Zmieñ has³o" << endl;


							in = _getch();
							if (input == 0 || in == 224)
								switch (_getch()) {
								case 80: if (menu_d < m_max) menu_d++; else cout << "\a"; break;
								case 72: if (menu_d > m_min) menu_d--; else cout << "\a"; break;
								}
							if (in == 13)
								switch (menu_d) {

								case 0: //pokaz dane konta
									cout << "imie: " << lista[i].imie << endl;
									cout << "nazwisko: " << lista[i].nazwisko << endl;
									cout << "numer konta: " << "Trzeba dodac" << endl;
									system("PAUSE");
									break;
								case 1:
									cout << "Historia operacji na koncie jest pusta" << endl;
									system("PAUSE");
									break;
								case 2:
									break;
								case 3:
									break;
								case 4:
									break;
								case 5:
									break;
								case 6:
									break;
								case 7: //wylogowanie
									//jakis logout
									break;
								case 8: //wylogowanie i zamkniêcie
									exit(0);
									break;
								case 9:
									break;
								}
						}
					}

				}
				cout << "Niepoprawne login lub haslo" << endl;
				system("PAUSE");
				// dodac: ponow probe, wyjdz 
				break;

			case 1:		//za³ó¿ konto
				nowy.dodaj();
				lista.push_back(nowy);
				break;

			case 2:		//zamknij program
				exit(0);
			}
	}
	return 0;

}