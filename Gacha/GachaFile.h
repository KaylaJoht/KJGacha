#pragma once
#ifndef GachaFile_h
#define GachaFile_h
#include <string>
#include "GachaList.h"
//Creates a list of pointers to GachaList
class GachaFile {
private:
	int size;
	Gacha** List;
public:
	//Default constructor
	GachaFile();

	//Default Destructor
	~GachaFile();
	//Functions
	void Grow(int, int);//Resizes the list
	int GetSize();//Returns size of the list
	int NewSize(const std::string);//Sets a new size
	bool ReadFile(const std::string);//Takes in a file and reads it's elements
	bool PrintList();//Prints a smaller version of the list to standard output

	Gacha *& operator[](int);//Overriden subscript operator
};
#endif#