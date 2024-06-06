

#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <array>
#include "GachaList.h"
using namespace std;

//Gacha functions definitions
//This is the Gacha constructor. It takes information and sets it to the correct data members
Gacha::Gacha(string unitRarity, string idol, string setName, int setNumber) {
	rarity = unitRarity;
	name = idol;
	set = setName;
	number = setNumber;
}

Gacha::Gacha(string unitRarity, string idol, string setName, string setNumber) {
	rarity = unitRarity;
	name = idol;
	set = setName;
	number = toInt(setNumber);
}

int Gacha::toInt(string num) {
	int n;
	n = stoi(num);
	return n;
}

//Get Functions to return private member data.

//Gets the rarity from the card
string Gacha::GetRarity() {
	return rarity;
}

//Gets the name of the idol on the card
string Gacha::GetName() {
	return name;
}

//Gets the set that the card is part of
string Gacha::GetSet() {
	return set;
}

//Gets the identification number for the card
int Gacha::GetNumber() {
	return number;
}

//Prints the rarity, name, and set
string Gacha::toString() {
	std::ostringstream output;
	output << rarity
		<< " " << name << ": " << set << " version";
	return output.str();
}