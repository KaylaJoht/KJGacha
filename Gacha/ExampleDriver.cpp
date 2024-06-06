
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <array>
#include <vector>
#include "GachaFile.h"
using namespace std;

int main() {
	
	GachaFile myList;
	myList.ReadFile("myList cards.txt");
	int mySize;
	mySize = myList.GetSize();
	srand(time(0));
	vector<int> URList;
	vector<int> cardNumber;
	int URSize{ 0 };


	for (int i = 0; i < mySize; i++) {
		if (myList[i]->GetRarity() == "UR") {
			URList.push_back(myList[i]->GetNumber());
			//cout << "\n" << myList[i]->toString();
		//	cout << " " << myList[i]->GetNumber();
		}
	}
	

	
	int x{ 0 };
	URSize = URList.size();
	//Random card algorithm
	for (int i = 0; i < URSize; i++) {
		x = rand() % URSize;
	//	cout << x;
		cardNumber.push_back(URList[x]);
		cout << "\n" << cardNumber[i];
		cout << " " << myList[cardNumber.back()]->toString();
	}
	//std::cout << myList[x]->toString() << std::endl;
//	for (int i = 0; i < URSize; i++) {
//		cout << " " << myList[URList[i]]->toString();
	//}
	
	/*
	vector<int> URList{0};
	GachaFile myList;
	int mySize{ 0 };
	int URSize{ 0 };
	myList.ReadFile("myList cards.txt");
	mySize = myList.GetSize();
	//cout << mySize;
	
	//Version only using myList
	cout << "Version only using myList" << endl;
	for (int i = 0; i < mySize; i++) {
		if (myList[i]->GetRarity() == "R") {
			URList.push_back(myList[i]->GetNumber());
			cout << "\n URLIST =" << URList[i];
			cout << " myList = " << myList[i]->GetNumber();
			cout << "\n" << myList[URList[i]]->toString();
		}
	}

	/*
	vector<int> cardNumber;
	vector<int> kayArray;
	cardNumber = {};
	int size{ 0 };

	GachaFile URList;
	URList.ReadFile("myList cards.txt");
	int URSize = URList.GetSize();
	for (int i = 0; i < URSize; i++) {
		cout << URList[i]->toString();
	}
	/*
	for (int i = 0; i < 20; i++) {
		cardNumber.push_back(100 + (i*10));
	}

	size = cardNumber.size();
	kayArray.resize(size);
	
	for (int i = 0; i < size; i++) {
		int k{ 1 };
		if (cardNumber[i] != 0) {
			cout << "\n" << cardNumber[i];
			for (int j = i + 1; j < size; j++) {
				if (cardNumber[j] == cardNumber[i]) {
					k = k + 1;
					cardNumber[j] = 0;
				}
			}
			cout << " x" << k;
			kayArray[i] = k;
		}
	}
	
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < URSize; j++) {
			if (cardNumber[i] == URList[j]->GetNumber()) {
				cout << "\n" << URList[j]->toString();
				cout << " x" << kayArray[i];
			}
		}
	}
	/*
	cout << "Numbers and their repetition";
	for (int i = 0; i < size; i++) {
		int k{ 1 };
		if (cardNumber[i] != 0) {
			cout << "\n" << cardNumber[i];
			for (int j = i + 1; j < size; j++) {
				if (cardNumber[j] == cardNumber[i]) {
					k = k + 1;
					cardNumber[j] = 0;
				}
			}
			cout << " x" << k;
			kayArray[i] = k;
		}
	}

	cout << "\n KayArray";
	for (int i = 0; i < kayArray.size(); i++) {
		cout << "\n" << kayArray[i];
	}
*/	
}

