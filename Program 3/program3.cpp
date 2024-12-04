#include <iostream>
#include <fstream>
#include "program3functions.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

int main(int argc, char *argv[]) {

    int size = 0;
    char letters[10000] = {};

    string fileName = argv[1];

    ifstream input(fileName);

    if (input.is_open()) {
        while (input.get(letters[size])) {
            size++;
        }
    } else {
        cout << "Failed to open file." << endl;
    }

    input.close();

    convertToLowerCase(letters, size);

    highestFrequency(letters, size);

    lowestFrequency(letters, size);

    listFrequency(letters, size);

    frequencyGraph(letters, size);

    return 0;
}

