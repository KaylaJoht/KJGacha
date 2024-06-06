
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
	vector<int> cardNumber;
	cardNumber = { 1,1,1,3,4,4,5,6,6,6,6,6,7,7,8,9,10 };
	int size{ 0 };
	size = cardNumber.size();
	/*
	cout << "The size of the array is: " << size;
	for (int i = 0; i < size; i++) {
		cout << "\n" << cardNumber[i];
	}
	*/

	cout << "Numbers and their repetition";
	for (int i = 0; i < size; i++) {
		int k{ 1 };
		if (cardNumber[i] != 0) {
			cout << "\n" << cardNumber[i];
			for (int j = i+1; j < size; j++) {
				if (cardNumber[j] == cardNumber[i]) {
					k = k + 1;
					cardNumber[j] = 0;
				}
			}
			cout << " x" << k;

		}
	}
}