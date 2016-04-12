#include "Card.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

#include <vector>
#include <stack>

void showCards(Card*, int);
stack<Card*> shuffleCards(Card*, int); //funkcja miesza karty
void game(stack<Card*>, stack<Card*>, int);  //funkcja przeprowadza gre i zwraca nr gracza-zwyciezcy

int main(int argc, char const *argv[])
{
	system("clear");
	printf("CARDS WARS!\n\n");
	int n=52;
	Card *cards = new Card[n];

	stack <Card*> Pl1;  //karty 1 i 2 gracza
	stack <Card*> Pl2;

	stack <Card*> deck = shuffleCards(cards, n); //deck zawiera stos przemieszanych kart, teraz trzeba je rozdac


	while(deck.size()!=0)
	{
		Pl1.push(deck.top());
		deck.pop();
		Pl2.push(deck.top());
		deck.pop();
	}

	printf("# INFO: Cards are gived to players.\n");

	printf("\nPRESS ENTER TO START THE GAME.");
	getchar();
	game(Pl1, Pl2, n);


	delete[] cards;
	printf("\n# INFO: Cards deleted. Memory free.\n\n");
}

void showCards(Card* cards, int n)
{
	for(int i=0; i<n; i++)
	{
		cout << "["<<i+1<<"]" << cards[i].description() << endl;
	}
}

stack<Card*> shuffleCards(Card* cards, int n)
{
	vector <Card*> shuffler;
	stack <Card*> deck;

	printf("# INFO: Number of cards: %d\n", n);

	srand(time(NULL));

	shuffler.push_back(cards);

	for (int i=0; i<n-1; i++)
	{
		int where=1+rand()%shuffler.size();
		shuffler.insert(shuffler.begin()+where, cards+i);
	}

	for(vector<Card*>::iterator it=shuffler.begin(); it!=shuffler.end(); it++)
	{
		deck.push(*it);
	}	
	printf("# INFO: Shuffled.\n");
	return deck;
}

void game(stack<Card*> Pl1, stack<Card*> Pl2, int n)
{
	stack<Card*> Help; //stack pomocniczy, do wkladania karty pod spod talii
	Card* actCard; //gdzies trzeba odlozyc karte ktora akurat sie gra, nie?
	int whoWin;  //kto wygral bitwe?
	int l=0;

	for (;Pl1.size()!=0 && Pl2.size()!=0;l++)
	{
		system("clear");
		printf("You have %d cards.\n", Pl1.size());
		printf("BATTLES: %d\n\n", l);

		cout << "Your next card: " + (Pl1.top())->description();

		printf("\n                                [ENTER] to battle!");
		getchar();

		cout << "Enemy card: " + (Pl2.top())->description() + "\n" << endl;
		//Ustalamy czyja karta byla lepsza:

		printf("!!!   ");
		cout << Pl1.top()->description() + "  VS  " + Pl2.top()->description();
		printf("   !!!\n\n");

		if (Pl1.top()->typeVal() > Pl2.top()->typeVal()) whoWin=1;
		if (Pl1.top()->typeVal() < Pl2.top()->typeVal()) whoWin=2;

		if (Pl1.top()->typeVal() == Pl2.top()->typeVal())
		{
			if (Pl1.top()->colorVal() > Pl2.top()->colorVal())
			{
				whoWin=1;
			}
			else whoWin=2;
		}
		if (whoWin==1)
		{

				printf("You won a battle! :)");
			if (Pl2.size()!=0)
			{
				actCard=Pl1.top(); //odkladam karte ktora gralem
				Pl1.pop(); //i zdejmuje ja ze stosu

				while(Pl1.size()>0)  //potem na inny stos odkladam po kolei karty
				{
					Help.push(Pl1.top());
					Pl1.pop();
				}
				//odkladam zdobyta karte:
				Pl1.push(Pl2.top());
				Pl2.pop();
				//...i wczesniej odlozona karte:
				Pl1.push(actCard);
				
				//oraz pozostale:
				while(Help.size()>0)
				{
					Pl1.push(Help.top());
					Help.pop();
				}
			}
		}
		else
		{   //ANALOGICZNIE:
				printf("You lose a battle! :(");
			if (Pl1.size()!=0)
			{
				actCard=Pl2.top(); //odkladam karte ktora gralem
				Pl2.pop(); //i zdejmuje ja ze stosu

				while(Pl2.size()>0)  //potem na inny stos odkladam po kolei karty
				{
					Help.push(Pl2.top());
					Pl2.pop();
				}
				//teraz odkladam zdobyta karte:
				Pl2.push(Pl1.top());
				Pl1.pop();
				//...i wczesniej odlozona karte:
				Pl2.push(actCard);
				
				//oraz pozostale:
				while(Help.size()>0)
				{
					Pl2.push(Help.top());
					Help.pop();
				}
			}
		}
		printf("\n                                [ENTER]\n");
		getchar();	
//		if (Pl1.size()==0 || Pl2.size()==0) break;
	}
	system("clear");
	if (Pl1.size()==0)
	{
		printf("YOU LOSE THE WAR!\n");
	}

	if (Pl2.size()==0)
	{
		printf("YOU WIN THE WAR!\n");
	}

	printf("\nBattles: %d\n                                [ENTER]", l);
	getchar();
}