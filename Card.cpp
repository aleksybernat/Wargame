#include "Card.h"

using namespace std;

int Card::_type_counter=2;  //odpowiada za typ karty
int Card::_color_counter=1;


Card::Card()
{
	if (_color_counter==1) _color=kier;
	if (_color_counter==2) _color=pik;
	if (_color_counter==3) _color=karo;
	if (_color_counter==4) _color=trefl;

	_type=_type_counter++;
	if (_type_counter==15) {_type_counter=2; _color_counter++;}
}

string Card::type()
{
	if (_type==2) {return "Dwojka";}
	if (_type==3) {return "Trojka";}
	if (_type==4) {return "Czworka";}
	if (_type==5) {return "Piatka";}
	if (_type==6) {return "Szostka";}
	if (_type==7) {return "Siodemka";}
	if (_type==8) {return "Osemka";}
	if (_type==9) {return "Dziewiatka";}
	if (_type==10) {return "Dziesiatka";}
	if (_type==11) {return "Walet";}
	if (_type==12) {return "Dama";}
	if (_type==13) {return "Krol";}
	if (_type==14) {return "As";}
}

string Card::color()
{
	if (_color==kier) {return "Kier";}
	if (_color==pik) {return "Pik";}
	if (_color==karo) {return "Karo";}
	if (_color==trefl) {return "Trefl";}
}

int Card::colorVal()
{
	if (_color==kier) {return 4;}
	if (_color==pik) {return 3;}
	if (_color==karo) {return 2;}
	if (_color==trefl) {return 1;}
}

string Card::description()
{
	return type() + " " + color();
}