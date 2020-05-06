#include <iostream>
#include <cstdlib>			//m.in rand()
#include <string>


#include <conio.h>
#include <vector>


using namespace std;

class Uzytkownik {

	//atrybuty
public:
	//private:	musi by� ale nie dziala z aktualnym main.cpp
	string imie;
	string nazwisko;
	string pesel; // lepiej niz double albo long, bo mo�na 
	//Sprawdzac poprzez utworzenie substringa (string::substr) z 2 pierwszych liter i stoi
	//Potem 2 kolejne substringujemy i znowu stoi. I tak jeszcze raz i mamy ca�� date uro
	

	struct data_urodzenia {
		int dzien;
		int miesiac;
		int rok;
	};
	string login;
	string haslo;
	string hasloPot;

	//metody
public:
	//Uzytkownik();			//konstruktor? 
	//~Uzytkownik()			//destruktor?
	string Imie();
	string Nazwisko();
	string Pesel();
	string Login();
	string Haslo();

	void dodaj();			//dodawanie konta
	void ZmianaHasla();
	void zplku();
	void WpiszHaslo();

};

class Pracownik :protected Uzytkownik {// 
	//atrybuty

	//jakie� atrybuty uprawnienia Admina


	//metody
	void dodaj();			//dodawanie konta
	void ZmianaHasla();
	void zplku();

	//jakie� i metody uprawnienia Admina

};

class Konto {
	//atrybuty
public:
	int numer_konta;
	float saldo;
	//saldo zamiast float to long ale na ko�cu podzielic przez 100
	float kasa;

	//metody
	float Saldo();
	void Wplata();
	void Wyplata();

};