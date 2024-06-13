#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


int* readFile(const string& fileName, int& numItems);

//PRE: Takes in array and value to look for
//POST: searches array for value and returns true or false
int inArray(const int* array, int value, int numItems);

//PRE: Takes in array and value of index
//POST: changes value at index and returns old value
int modifyAndReturnValue(int* array, int numItems, int index, int newValue);

//PRE: Takes in array and value
//POST: adds to end
int* addToArray(int* array, int& numItems, int& capacity, int newValue);

//PRE: Takes in array and value
//POST: if found removes value from array
int* delFromArray(int* array, int& numItems, int index);