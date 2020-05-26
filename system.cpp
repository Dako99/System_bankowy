#include "system.h"
#include <fstream>			//obsluga plikow


using namespace std;

//metody:
//Konstruktor, destruktor i metody dost�pu do zmiennych danych konta

Uzytkownik::Uzytkownik(string i, string n, string l, string h, string p, long double nr, float s)
{
	imie = i;
	nazwisko = n;
	login = l;
	haslo = h;
	pesel = p;
	numer_konta = nr;
	saldo = s;
};

Uzytkownik::~Uzytkownik()
{
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
string Uzytkownik::Login()
{
	return this->login;
};
string Uzytkownik::Haslo()
{
	return this->haslo;
};

// end


void Uzytkownik::dodaj()	//dodaje u�ytkownika do systemu
{
	/*cout << "Nacisnij dowolny klawisz aby kontynuowac" << endl;
	cout << "Nacisnij Esc aby anulowac" << endl;

	int input = _getch();
	if (input != 27) {*/

	cout << "Podaj imie: " << endl;
	cin >> this->imie;
	cout << "Podaj nazwisko: " << endl;
	cin >> this->nazwisko;

	do
	{
		//=aoti(pesel.s_str());
		cout << "Podaj pesel: " << endl;
		cin >> this->pesel;

		//poprawna d�ugosc nr pesel
		while (stod(pesel) < 1000 || stod(pesel) > 100000000000) {
			cout << "\a" << "Nieprawidlowy nr pesel" << endl;
			cout << "Podaj pesel ponownie: " << endl;
			cin >> this->pesel;
		}

		//obs�uga daty urodzenia na podstawie nr pesel przy uzyciu substringa
		int rk = stoi(pesel.substr(0, 2));
		int msc = stoi(pesel.substr(2, 2));
		int dz = stoi(pesel.substr(4, 2));

		//ROCZNIK 00 and up
		//Osoby urodzone w roku 2000 i p�niej maj� powi�kszony numer miesi�ca o liczb� 20

		if ((13 > msc) && (msc > 0)) rk = rk + 1900;
		else if ((33 > msc) && (msc > 20)) {
			msc = (msc - 20);
			rk = rk + 2000;
			if (rk > (2020 - 18)) {
				cout << "\a" << "Zalozyc konto moze tylko osoba pelnoletnia" << endl << endl;
				dodaj();
			}
		}
		else cout << endl << "Nieprawidlowy nr pesel (data)" << endl;

		cout << endl << "*dla testow*" << endl;
		cout << "rok: " << rk << endl;
		cout << "msc: " << msc << endl;
		cout << "dzien: " << dz << endl;
		cout << "*dla testow*" << endl << endl;

		if ((33 < msc < 20) && (13 > msc > 0) && (32 > dz > 0)) {
			Uzytkownik::data_urodzenia nowy = { rk, msc, dz };
			//dz = this->data_urodzenia.dzien;
			break;
		}
	} while (1);


	cout << "Podaj login: " << endl;
	cin >> this->login;
	cout << "Podaj haslo: (ukryc przy wprowadzaniu)" << endl;
	cin >> this->haslo;

	string hasloPot;
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
}


void Uzytkownik::Zapis()
{
	ofstream plik("BazaDanych.txt", fstream::out | fstream::app);

	plik << this->imie << endl;
	plik << this->nazwisko << endl;
	plik << this->pesel << endl;
	plik << this->login << endl;
	plik << this->haslo << endl;
	plik << haslo << endl;

	plik.close();

	cout << "Konto zostalo zapisane pomyslnie" << endl;
};





void Uzytkownik::Odczyt()
{
	string const plik("BazaDanych.txt");
	ofstream mojStrumien(plik.c_str());

	if (mojStrumien) {
		mojStrumien << "Imie: " << this->imie << endl;
		mojStrumien << "Nazwisko: " << this->nazwisko << endl;
		mojStrumien << "Pesel: " << this->pesel << endl;
		mojStrumien << "Nazwa uzytkownika: " << this->login << endl;
		mojStrumien << "Haslo: " << this->haslo << endl;
	}
	else {
		cout << "BLAD: nie mo�na otworzy� pliku." << endl;
	}



	//fstream plik("BazaDanych.txt", fstream::in);		//bez out i app nie bedzie dzialac

	//if (plik.good() == false) {
	//	cout << "Plik nie istnieje";
	//	//exit(0);
	//	//break;
	//}
	//else {
	//	int aktualny_nr = 1;
	//	string linia;
	//	int nr_konta = 0;
	//	while (getline(plik, linia)) //(skad,gdzie) 0=nie uda�o sie pobrac
	//	{
	//		switch (aktualny_nr) {
	//		case 1:imie = linia; break;
	//		case 2:nazwisko = linia; break;
	//		case 3:pesel = linia; break;
	//		case 4:login = linia; break;
	//		case 5:haslo = linia; break;
	//		}

	//	}
	//	plik.close();
	//}

	//cout << "K" << endl;

};


//poczatek obs�ugi hasla

void Uzytkownik::ZmianaHasla()
{
	string test;					//int?
	string nowe_haslo;				//int?
	string nowe_haslo1;				//int?
	int a = 0;

	cout << "Podaj obecne haslo: ";
	cin >> test;
	while (test != this->haslo) {
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
	system("PAUSE");
};

void Uzytkownik::WpiszHaslo()		// przyda sie jako funkcja do potwierdzania wplat, wyplat itd.
{

	string HASLO;
	cout << "W celu potwiedzenia wpisz haslo: ";
	cin >> HASLO;
	int zmienna = _getch();
	while (HASLO != this->haslo && zmienna != 27)
	{
		cout << "Podane haslo jest bledne, sprobuj ponownie: ";
		cin >> HASLO;

	}

	/*string HASLO;
	cout << "W celu potwiedzenia wpisz haslo: ";
	cin >> HASLO;
	while (HASLO != this->haslo) {
		cout << "Podane haslo jest bledne, sprobuj ponownie: ";
		cin >> HASLO;
		int input = _getch();
		if (input == 27) break;
	} */

};

//Koniec obs�ugi hasla


// Obs�uga kasy
void Uzytkownik::Saldo()
{
	cout << "Twoj stan konta to: " << this->saldo << " zl" << endl;
	system("PAUSE");
};


void Uzytkownik::Wyplata()
{ //kwota
	float wyplata;
	cout << "Podaj kwote jaka chcesz wyplacic" << endl;
	cout << "0 aby wyjsc" << endl;
	cin >> wyplata;
	while ((this->saldo - wyplata) < 0 || wyplata < 0)
	{
		cout << "Podana kwota powoduje debet, badz jest ujemna, wprowadz inna: " << endl;
		cin >> wyplata;
	}
	//	this->saldo -= wyplata;
	this->saldo = this->saldo - wyplata;
	if (wyplata = 0) cout << "Transakcja anulowana" << endl;
	else cout << "Pomyslnie wyplacono pieniadze." << endl;
	system("PAUSE");
};


void Uzytkownik::Wplata()
{	//kwota			//je�eli u�ytkownik ma kilka kont, to spytac na ktore konto
	float wplata;
	cout << "Podaj kwote jaka chcesz wplacic" << endl;
	cin >> wplata;
	while (wplata < 0)
	{
		cout << "Podana kwota jest ujemna, wprowadz inna: " << endl;
		cin >> wplata;
	}
	//	this->saldo += wplata;
	saldo = saldo + wplata;  //czy moze tak?
	cout << "Pomyslnie wplacono pieniadze." << endl;
	system("PAUSE");
};


// koniec obs�ugi kasy


//Nr konta mysle, ze starczy 5 cyfr, w long double miesci sie 15, z czego przez notacje z e nie wyswietli nawet 10
//Numer konta zapisac mozna do innego pliku, przez co przy zapisie bazy, nie zmieni sie on po restarcie programu,
//Wrzucam tylko t� funkcje, dzisiaj nocka zarwana i praktycznie 0 progresu :(

int Uzytkownik::NrKonta()
{
	srand(time(NULL));

	int nr_Konta = (rand() % 100000) + 10001;
	this->numer_konta = nr_Konta;
	return this->numer_konta;
};


// Plus jeszcze ta, ale tutaj wywala mi b��d prze�adowania bufora i nie wiem co dalej, problem prawdopodobnie,
//le�y w p�tli.





void Pracownik::dodaj()
{
	//jakie� bajerki
	cout << "Witaj pracowniku" << endl;
	Uzytkownik::dodaj();

}

void Pracownik::ZmianaHasla()
{
	//jakie� bajerki
	cout << "Witaj pracowniku" << endl;
	Uzytkownik::ZmianaHasla();

}

void Pracownik::Odczyt()
{
	//jakie� bajerki
	cout << "Witaj pracowniku" << endl;
	Uzytkownik::Odczyt();

}

Pracownik::Pracownik(string pL, string pH)
{
	pLogin = pL;
	pHaslo = pH;
}

Pracownik::~Pracownik()
{

}