#include <iostream>
#include <cstdlib>
#include <string>

#include <fstream>
#include <conio.h>
#include <vector>


using namespace std;

class Uzytkownik {

	//atrybuty
public:			
//protected:	?
//private:		- nie dziala z aktualnym mainem
	string imie;
	string nazwisko;
	double pesel;
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
	double Pesel();
	string Login();
	string Haslo();
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