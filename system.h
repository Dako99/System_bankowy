#include <iostream>
#include <cstdlib>			//m.in rand()
#include <string>
#include <conio.h>
#include <vector>


#include <time.h>			//czas

using namespace std;

//delkaracja klas, 
//aby nie bylo problemow ze 
//w pierwszej klasie odwolujemy sie do ostatniej

class Uzytkownik;
class Odbiorca;
class Pracownik;
class Konto;
class Historia;	//work in progress



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
	//dodanie listy odbiorcow
	vector <Odbiorca> odbiorcy;
	//konstruktor do poprawy, pesel jako string
	Uzytkownik(string = "", string = "", string = "", string = "", string = "", long double = 0, float = 0);
	~Uzytkownik();			//destruktor
	string Imie();
	string Nazwisko();
	string Pesel();
	string Login();
	string Haslo();
	string hasloPot;
	//string Urodzenie();

	void dodaj();			//dodawanie konta
	void ZmianaHasla();
	void zplku();
	void WpiszHaslo();
	int NrKonta();
	void Saldo();
	void Wplata();
	void Wyplata();
	void Zapis();
	void Odczyt();
	

};

class Pracownik :protected Uzytkownik {// 
	//atrybuty
private:
	//atrybuty uprawnienia Admina
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


// utworzenie klasy odbiorca
class Odbiorca {
public: //private moze?
	string nazwa;
	int numer_konta;
};


class Konto {
	//atrybuty
public:
	int numer_konta;
	float saldo;
	//a moze saldo zamiast float to long ale na koñcu podzielic przez 100?
	float kasa;

	//metody
	float Saldo();
	void Wplata();
	void Wyplata();

};


class Historia {

};