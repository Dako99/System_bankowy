#include "system.h"


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
double Uzytkownik::Pesel()
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
	cout << "(Nie wiem jak dodac date urodzenia)" << endl;
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

	ofstream plik("BazaDanych.txt");

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