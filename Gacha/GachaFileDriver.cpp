#include <iostream>
#include <cctype>
#include "GachaFile.h"

using namespace std;

int main() {
    GachaFile URList;
    GachaFile SRList;
    GachaFile RList;
    int i{ 0 };
    int size{ 0 };
    int x{ 0 };

    URList.ReadFile("UR cards.txt");
    size = URList.GetSize();

    GachaFile myList;
    myList.Grow(0, 20);

    for (i; i < 20; ++i) {
        cout << "\ni: " << i << " = " << myList[i];
    }
    myList.PrintList();
    /*
    for (i; i <= 17; ++i) {
        int j{ 0 };
        j = i+1;
        cout << "\n";
        cout << myList[i]->GetName();
        cout << myList[j]->GetName();
        cout << myList[i]->GetSet();
        cout << myList[j]->GetSet();

        if ((myList[i]->GetName() == myList[j]->GetName()) && (myList[i]->GetSet() == myList[j]->GetSet())) {
            cout << "\nTrue" << endl;
        }
    }
    */
    
    /*
    for (i; i <= mySize-1; ++i) {
        int k{ 1 };
        if (myList[i] != nullptr) {
           cout << "\n" << myList[i]->toString();
           if (i == mySize-1) {
               break;
           }
           else{
               for (int j = i + 1; j <= mySize-1; ++j) {
                   cout << "\nEntered j loop" << endl;
                   cout << "i = " << i << " and j = " << j << endl;
                   //if ((myList[i]->GetName() == myList[j]->GetName()) && (myList[i]->GetSet() == myList[j]->GetSet())) {
                   //    cout << "Entered if statement" << endl;
                   //    k = k + 1;
                   //    myList[j] == nullptr;
                   //}
                  // cout << "Skipped if statement" << endl;
               }
           }
           cout << " x" << k;
        }
    }
    
    */
    /*
    cout << "Ultra-Rare cards: " << endl;
    */

    //I might be having problems loading up the array    

    //cout << URList[10]->toString();
    /*
    cout << "Super-Rare cards: " << endl;
    SRList.ReadFile("SR cards.txt");
    SRList.PrintList();

    cout << "Rare cards: " << endl;
    RList.ReadFile("R cards.txt");
    RList.PrintList();
    */
    
}