#include "system.h"
#include <fstream>			//obsluga plikow
#include <string>

using namespace std;

//metody:

string Uzytkownik::Haslo()
{
	return this->haslo;
};
string Uzytkownik::Login()
{
	return this->login;
};
string Uzytkownik::Imie()
{
	return this->imie;
};
string Uzytkownik::Nazwisko()
{
	return this->nazwisko;
};
string Uzytkownik::Pesel()
{
	return this->pesel;
};



void Uzytkownik::dodaj() {				//dodaje u¿ytkownika do systemu
	cout << "Podaj imie: " << endl;
	cin >> this->imie;
	cout << "Podaj nazwisko: " << endl;
	cin >> this->nazwisko;
	cout << "Podaj pesel: " << endl;
	cin >> this->pesel;

	if (stod(pesel) < 100000 || stod(pesel) > 10000000000) cout << "\a" << "Nieprawidlowy nr pesel" << endl;
	
	if (stod(pesel) > 100000) {
		//PAMIETAC O ROCZNIKU 00 and up, na razie nie wspiera
		cout << "*dla testow*" << endl;
		cout << "rok: " << stoi(pesel.substr(0, 2)) << endl;
		cout << "msc: " << stoi(pesel.substr(2, 2)) << endl;
		cout << "dzien: " << stoi(pesel.substr(4, 2)) << endl;
		cout << "*dla testow*" << endl << endl;
	}
	//obsluzyc date urodzenia, w razie bledow cofnac sie

	cout << "Podaj login: " << endl;
	cin >> this->login;
	cout << "Podaj haslo: (Fajnie gdyby nie bylo go widac przy wprowadzaniu)" << endl;
	cin >> this->haslo;
	cout << "Potwierdz haslo: " << endl;
	cin >> hasloPot;
	while (haslo != hasloPot) {
		cout << "Hasla nie sa identyczne, wpisz ponownie" << endl;
		cout << "Haslo: " << endl;
		cin >> this->haslo;
		cout << "Potwierdz haslo: " << endl;
		cin >> hasloPot;
	}
	cout << "Konto zostalo utworzone pomyslnie" << endl;
	system("PAUSE");

	ofstream plik("BazaDanych.txt", fstream::out | fstream::app);		//bez out i app nie bedzie dzialac

	plik << this->imie << endl;
	plik << this->nazwisko << endl;
	plik << this->pesel << endl;
	plik << this->login << endl;
	plik << this->haslo << endl;

	plik.close();
}

void Uzytkownik::ZmianaHasla()
{
	string test;					//int
	string nowe_haslo;				//int
	string nowe_haslo1;				//int
	int a = 0;
	cout << "Podaj obecne haslo: ";
	cin >> test;
	while (test != this->haslo)
	{
		cout << "Podane haslo jest nieprawidlowe, wprowadz obecne haslo: ";
		cin >> test;
	}
	while (test == this->haslo && a == 0) {
		cout << "Podaj nowe haslo: ";
		cin >> nowe_haslo;
		while (nowe_haslo == this->haslo)
		{
			cout << "Haslo musi roznic sie od poprzedniego.\n";
			cout << "Podaj haslo ponownie: ";
			cin >> nowe_haslo;

		}
		cout << "Podaj haslo ponownie: ";
		cin >> nowe_haslo1;
		while (nowe_haslo != nowe_haslo1)
		{
			cout << "Podaj haslo ponownie: ";
			cin >> nowe_haslo1;
		}
		a = 1;
	}
	if (nowe_haslo == nowe_haslo1)
	{
		this->haslo = nowe_haslo;
		cout << "Haslo zostalo zmienione.\n";
	}


};


void Uzytkownik::zplku() {

	string const plik("BazaDanych.txt");
	ofstream mojStrumien(plik.c_str());

	if (mojStrumien)
	{
		mojStrumien << "Imie: " << this->imie << endl;
		mojStrumien << "Nazwisko: " << this->nazwisko << endl;
		mojStrumien << "Pesel: " << this->pesel << endl;
		mojStrumien << "Nazwa uzytkownika: " << this->login << endl;
		mojStrumien << "Haslo: " << this->haslo << endl;
	}
	else
	{
		cout << "B£¥D: nie mo¿na otworzyæ pliku." << endl;
	}


}

void Uzytkownik::WpiszHaslo()		// przyda sie jako funkcja do potwierdzania wplat, wyplat itd.
{
	string HASLO;
	cout << "W celu potwiedzenia wpisz haslo: ";
	cin >> HASLO;
	while (HASLO != this->haslo)
	{
		cout << "Podane haslo jest bledne, sprobuj ponownie: ";
		cin >> HASLO;
	}
};



float Konto::Saldo()
{
	return this->saldo;
};
void Konto::Wplata()
{
	float wplata;
	cout << "Podaj kwote jaka chcesz wyplacic";
	cin >> wplata;
	while (wplata < 0)
	{
		cout << "Podana kwota jest ujemna, wprowadz inna: ";
		cin >> wplata;
	}
	this->saldo += wplata;
	cout << "Pomyslnie wplacono pieniadze.";
};
void Konto::Wyplata()
{
	float wyplata;
	cout << "Podaj kwote jaka chcesz wyplacic";
	cin >> wyplata;
	while ((this->saldo - this->kasa) < 0 || wyplata > 0)
	{
		cout << "Podana kwota powoduje debet, badz jest ujemna, wprowadz inna: ";
		cin >> wyplata;
	}
	this->saldo -= wyplata;
	cout << "Pomyslnie wyplacono pieniadze.";
};



void Pracownik::dodaj() {

	//jakieœ bajerki
	cout << "Witaj pracowniku" << endl;
	Uzytkownik::dodaj();

}

void Pracownik::ZmianaHasla() {

	//jakieœ bajerki
	cout << "Witaj pracowniku" << endl;
	Uzytkownik::ZmianaHasla();

}

void Pracownik::zplku() {

	//jakieœ bajerki
	cout << "Witaj pracowniku" << endl;
	Uzytkownik::zplku();

}


// konstruktor

//Uzytkownik::Uzytkownik() {}
//
//Uzytkownik(int..., string..., itd) {
//	this->costam = costam;
//	this->costam = costam;
//	this->costaminnego = costaminnego;
//}


//destruktor
/*
Uzytkownik::~Uzytkownik() {
	cout << "Czy ja mam co sprz¹taæ?" << endl;;
}
*/