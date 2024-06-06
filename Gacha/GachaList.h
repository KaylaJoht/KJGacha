/*
	The purpose of this class is to take a line containing 4 pieces of information,
	and separating them into the appropriate parameters. This way when we put in a 
	list of cards, we have all the informtion stored properly.
*/

#ifndef GachaList_h
#define GachaList_h

#include <string>
#include <array>
using namespace std;

//Class Gacha
class Gacha {
private:
	//Private member data
	string rarity;//The rarity of the card
	string name;//The character in the card
	string set;//The set the card is part of
	int number;//The number Identifying the card

public:
	//Constructor
	Gacha(string, string, string, int);
	Gacha(string, string, string, string);
	//Get Functions
	string GetRarity();
	string GetName();
	string GetSet();
	int GetNumber();
	int toInt(string);
	//Prints out special data
	std::string toString();

};
#endif