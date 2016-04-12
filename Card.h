#pragma once
#include <string>

using namespace std;

enum clr {kier, pik, karo, trefl};

class Card
{
private:
	
	clr _color;
	int _type;
	static int _type_counter;  //typ karty
	static int _color_counter; //kolor karty

public:
	Card();

	static int typeCounter() {return _type_counter;}
	static int colorCounter() {return _color_counter;}

	string type();  //zwraca typ karty jako string
	string color(); //zwraca nazwe koloru karty
	int typeVal() {return _type;}
	int colorVal(); //zwraca wartosc numeryczna koloru karty


	string description(); //pelen opis karty

};