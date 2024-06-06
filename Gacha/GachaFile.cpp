#include <fstream>
#include <iostream>
#include <iomanip>
#include <array>
#include "GachaFile.h"
using namespace std;

//gacha cptr = new is not being called.
//Brute force my way through. 
//One of the entries is not being thought of as an object, because the constructor is not being called
//Fixing this should fix the other problems.

//Creates a list of size 0
GachaFile::GachaFile() {
    size = 0;
    List = new Gacha* [size];
}

GachaFile::~GachaFile() {
    //Loop to deallocate each memory address
    for (int i = 0; i < size; ++i) {
        delete List[i];
    }
    delete[] List;
}

//If you have a new list, this loops through the list and counts each line
//The total amount of lines would be the new size.
int GachaFile::NewSize(const string filename){
    int newSize = 0;
    string line;
    ifstream myfile(filename);

    while (getline(myfile, line)) {
        ++newSize;
    }
    return newSize;
}

//Resizes a the List of pointers without deleting the values
void GachaFile::Grow(int oldSize, int newSize)
{
    size = newSize;
    Gacha** temp = new Gacha * [size];//Making a tempaorary list big enough to hold the new file
    for (int i = 0; i < size-1; ++i) {
        temp[i] = List[i];//Loading it with the values already held in List
    }
    delete[] List;//Deleting List
    List = new Gacha * [size];
    List = temp;//putting the values back in List
}

//Reads a file and decodes the data
bool GachaFile::ReadFile(const std::string filename) {
    // Open the file for reading
    std::ifstream in;
    in.open(filename);
    if (in.fail()) {
        return false;
    }

    //Calling newSize to get the size of the list
    int numEntries{ 0 };
    numEntries = NewSize(filename);
    int oldSize = size;

    int i{ 0 };             
    string rarity;         
    string name;   
    string set;
    int number;
    //Resizes the list
    Grow(oldSize, numEntries);


    //Loop to read each element of the list
    for (int i = 0; i < numEntries; ++i) {
        in.ignore();
        getline(in, rarity, ',');
        in.ignore();
        getline(in, name, ',');
        in.ignore();
        getline(in, set, ',');
        in.ignore();
        in >> number;
        Gacha* Cptr = new Gacha(rarity, name, set, number);//Making a pointer to the new Gacha object
        List[i] = Cptr;//Adding the pointer to the list
    }
    in.ignore();
    return true;
}

//Prints the contents of the list
bool GachaFile::PrintList() {

    //Output if nothing is in list
    if (size == 0) {
        std::cout << "No items in this list of cards" << std::endl;
        return true;
    }

    //Loops through the List and prints out every value that is stored
    //But only it's rarity, name, and set
    for (int i = 0; i < size; ++i) {
        std::cout << "\n";
        std::cout << List[i]->GetRarity();
        std::cout << " ";
        std::cout << List[i]->GetName();
        std::cout << " ";
        std::cout << List[i]->GetSet();
    }

    std::cout << std::endl;

    return true;
}

//returns the size of a list
int GachaFile::GetSize() {
    return size;
}

//Overriden subscript operator
Gacha*& GachaFile::operator[](int gachaValue) {
    return List[gachaValue];
}
