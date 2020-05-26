#include <iostream>			//input/output
#include <cstdlib>			//m.in rand()
#include <string>			//class string
#include <conio.h>			//getch()
#include <vector>			//dynamiczne tablice


#include <time.h>			//czas

using namespace std;

//delkaracja klas, 
//aby nie bylo problemow ze 
//w pierwszej klasie odwolujemy sie do ostatniej

class Uzytkownik;
class Odbiorca;
class Pracownik;
class Konto;
class Historia;


class Uzytkownik {

	//atrybuty
private:
	string imie;
	string nazwisko;
	string pesel;			//lepiej niz double albo long, dla daty
	struct data_urodzenia {
		int rok;
		int miesiac;
		int dzien;
	};
	string login;
	string haslo;

	int numer_konta;
	float saldo;



	//metody
public:

	vector <Odbiorca> odbiorcy;				//dodanie listy odbiorcow
	vector <Historia> historia_operacji;	//historia operacji

	Uzytkownik(string = "", string = "", string = "", string = "", string = "", long double = 0, float = 0);
	~Uzytkownik();			//destruktor
	string Imie();
	string Nazwisko();
	string Pesel();
	string Login();
	string Haslo();

	//string Urodzenie();

	void dodaj();			//dodawanie konta
	void ZmianaHasla();
	void WpiszHaslo();
	int NrKonta();
	void Saldo();
	void Wplata();
	void Wyplata();
	void Zapis();
	void Odczyt();

};

class Pracownik :protected Uzytkownik { //dziedziczenie

	//atrybuty (uprawnienia Admina)
private:
	string pLogin;
	string pHaslo;

	//metody i uprawnienia Admina
public:
	Pracownik(string = "admin", string = "admin");
	~Pracownik();
	void dodaj();			//dodawanie konta
	void ZmianaHasla();
	void Odczyt();

};


class Odbiorca {
public: //private moze?
	string nazwa;
	int numer_konta;
};


class Konto {

	//atrybuty
public:
	int numer_konta;
	float saldo; //ewentualnie jako long i na koñcu podzielic przez 100
	float kasa;

	//metody
	float Saldo();
	void Wplata();
	void Wyplata();

};


class Historia {
public:
	string operacja;
	int rok, miesiac, dzien, godzina, minuta, konto_docelowe; //data operacji
	float kwota;
};