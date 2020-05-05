#include <iostream>
#include <cstdlib>
#include <string>

#include <fstream>
#include <conio.h>
#include <vector>


using namespace std;

class Uzytkownik {

	//atrybuty
public:			//protected:?
		
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
	string hasloPot;

	//metody
public:
	//Uzytkownik();			//konstruktor? 
	//~Uzytkownik()			//destruktor?
	void dodaj();			//dodawanie konta
	void ZmianaHasla();
	void zplku();
};

class Pracownik :protected Uzytkownik {// 
	//atrybuty

	//jakieœ atrybuty uprawnienia Admina


	//metody
	void dodaj();			//dodawanie konta
	void ZmianaHasla();
	void zplku();
	
	//jakieœ i metody uprawnienia Admina

};

class Konto {
	//atrybuty
public:
	int numer_konta;
	float saldo;

};