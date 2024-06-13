#include "functions.h"

int main() {
    string fileName = "A1input.txt";  // Replace with your file name
    string goAgain;
    int numItems = 0;
    int capacity = 8;
    int* array = readFile(fileName, numItems);

    if (array == nullptr) {
        cout << "Failed to read the file or no data found.\n";
        return -1;
    }

    // Output the read items for verification
    cout << "Initial array contents loaded." << endl;
    cout << "Array size: " << numItems << endl;

while (true) {
    cout << "\nOptions\n"
            "_______________\n"
            "\nFind Value (1)"
            "\nModify Value @ index (2)"
            "\nAdd new value (3)"
            "\nRemove Value (4)" << endl << endl;
    cout << "Choose an option ==> ";
    string userOption;
    try {
        cin >> userOption;
        if ((!stoi(userOption)) || stoi(userOption) < 1 || stoi(userOption) > 4) {
            cout << "Invalid option. Try again." << endl;
            continue;
        }
        if (userOption == "1") {
            int valueToFind;
            cout << "Enter a value to find: ";
            cin >> valueToFind;
            int index = inArray(array, valueToFind, numItems);
            if (index != -1) {
                cout << "Value " << valueToFind << " found at index " << index << ".\n";
            } else {
                cout << "Value " << valueToFind << " not found in the array.\n";
            }
        } else if (userOption == "2") {
            int indexToModify;
            int newValue;
            cout << "Enter the index to modify: ";
            cin >> indexToModify;
            cout << "Enter the new value: ";
            cin >> newValue;
            auto oldValue = modifyAndReturnValue(array, numItems, indexToModify, newValue);
            cout << "Value at index " << indexToModify << " changed from" << oldValue << " to " << newValue
                 << ".\n";
        } else if (userOption == "3") {
            int newValueToAdd;
            cout << "Enter a new value to add: ";
            cin >> newValueToAdd;
            array = addToArray(array, numItems, capacity, newValueToAdd);
            cout << "Added value " << newValueToAdd << " to the array.\n";
        } else if (userOption == "4") {
            int indexToRemove;
            cout << "Enter the index to remove: ";
            cin >> indexToRemove;
            array = delFromArray(array, numItems, indexToRemove);
            cout << "Removed value at index " << indexToRemove << ".\n";
        } else {
            cout << "Invalid option. Please choose a valid option.\n";
        }
    } catch(runtime_error&e) {
        cout << e.what() << "ERROR OCCURRED"<< endl;
    }
    cout << "Do you want to continue? (Y/N) ==>";
    cin >> goAgain;
    if (goAgain != "n" && goAgain != "N") {
        continue;
    } else {
        break;
    }
}
    cout << "Final array contents: ";
    for (int i = 0; i < numItems; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Cleanup
    delete[] array;

    return 0;
};