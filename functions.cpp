#include "functions.h"

int* readFile(const string& fileName, int& numItems) {
    ifstream inFile;
    int* array = new int[8];  // Initial size of 8
    int capacity = 8;
    numItems = 0;

    // Open the file
    inFile.open(fileName);

    // Check if file was opened properly
    if (!inFile.is_open()) {
        cout << "Unable to open file\n";
        delete[] array;
        return nullptr;
    }

    try {
        string inData;
        while (inFile >> inData) {  // Read data from the file
            if (numItems == capacity) {  // Check if resize is needed
                int newCapacity = capacity * 2;
                int* newArray = new int[newCapacity];
                for (int i = 0; i < numItems; i++) {
                    newArray[i] = array[i];
                }
                delete[] array;
                array = newArray;
                capacity = newCapacity;
                cout << "Array size updated to " << capacity << ".\n";
            }
            array[numItems] = stoi(inData);
            numItems++;
        }
    } catch (out_of_range&) {
        cout << "Out of range exception caught\n";
    } catch (invalid_argument&) {
        cout << "Invalid argument exception caught\n";
    }

    inFile.close();
    return array;  // Return the dynamically allocated array
}

int inArray(const int* array, int value, int numItems){
    for (int i = 0; i < numItems; i++) {
        if (array[i] == value) {
            return i;
        }
    }
    return -1;  // Return -1 if value is not found
}


int modifyAndReturnValue(int* array, int numItems, int index, int newValue){
    if (index < 0 || index >= numItems) {
        throw out_of_range("Index out of range");
    }
    int oldValue = array[index];
    array[index] = newValue;
    return oldValue;
}


int* addToArray(int* array, int& numItems, int& capacity, int newValue){
    if (numItems == capacity) {  // Check if resize is needed
        int newCapacity = capacity * 2;
        int* newArray = new int[newCapacity];
        for (int i = 0; i < numItems; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
        capacity = newCapacity;
        cout << "Array size updated to " << capacity << ".\n";
    }
    array[numItems++] = newValue;
    return array;
}


int* delFromArray(int* array, int& numItems, int index){
    if (index < 0 || index >= numItems) {
        throw out_of_range("Index out of range");
    }
    for (int i = index; i < numItems - 1; i++) {
        array[i] = array[i + 1];
    }
    numItems--;
    return array;
}