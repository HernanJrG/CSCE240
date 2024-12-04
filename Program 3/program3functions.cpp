#include <iostream>

using std::cout;
using std::endl;
using std::string;

void convertToLowerCase(char letters[], int size) {
    for (int i = 0; i < size; i++) {
        letters[i] = tolower(letters[i]);
    }
}

void highestFrequency(char letters[], int size) {
    int frequency[26] = {0};
    int maxCount = 0;

    for (int i = 0; i < size; i++) {
        if (letters[i] >= 'a' && letters[i] <= 'z') {
            frequency[letters[i] - 'a']++;
            if (frequency[letters[i] - 'a'] > maxCount) {
                maxCount = frequency[letters[i] - 'a'];
            }
        }
    }

    char highestChars[26];
    int highestCount = 0;

    for (int i = 0; i < 26; i++) {
        if (frequency[i] == maxCount) {
            highestChars[highestCount] = 'a' + i;
            highestCount++;
        }
    }

    if (highestCount > 1) {
        cout << "Highest frequency characters (appeared " << maxCount << " times in the file): ";
    } else {
        cout << "Highest frequency character (appeared " << maxCount << " times in the file): ";
    }

    for (int i = 0; i < highestCount; i++) {
        if (i > 0) {
            if (i == highestCount - 1) {
                cout << " and ";
            } else {
                cout << ", ";
            }
        }
        cout << highestChars[i];
    }
    cout << endl;
}

void lowestFrequency(char letters[], int size) {
    int frequency[26] = {};

    for (int i = 0; i < size; i++) {
        if (letters[i] >= 'a' && letters[i] <= 'z') {
            frequency[letters[i] - 'a']++;
        }
    }

    int minFrequency = size;
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > 0 && frequency[i] < minFrequency) {
            minFrequency = frequency[i];
        }
    }

    int zeroCount = 0;
    for (int i = 0; i < 26; i++) {
        if (frequency[i] == 0) {
            zeroCount++;
        }
    }

    if (zeroCount > 0) {
        cout << "Lowest frequency characters (appeared 0 times in the file): ";
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (frequency[i] == 0) {
                count++;
                if (count == 1) {
                    cout << char('a' + i);
                } else if (count < zeroCount) {
                    cout << ", " << char('a' + i);
                } else {
                    cout << ", and " << char('a' + i) << endl;
                }
            }
        }
    } else {
        cout << "Lowest frequency characters (appeared " << minFrequency << " time in the file): ";
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (frequency[i] == minFrequency) {
                count++;
                if (count == 1) {
                    cout << char('a' + i);
                } else if (count < minFrequency) {
                    cout << ", " << char('a' + i);
                } else {
                    cout << ", and " << char('a' + i) << endl;
                }
            }
        }
    }
    cout << endl;
}

void listFrequency(char letters[], int size) {
    int frequency[26] = {};

    for (int i = 0; i < size; i++) {
        if (letters[i] >= 'a' && letters[i] <= 'z') {
            frequency[letters[i] - 'a']++;
        }
    }

    char letterArray[26];
    int frequencyArray[26];
    for (int i = 0; i < 26; i++) {
        letterArray[i] = 'a' + i;
        frequencyArray[i] = frequency[i];
    }

    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (frequencyArray[i] < frequencyArray[j] ||
                (frequencyArray[i] == frequencyArray[j] && letterArray[i] > letterArray[j])) {
                int tempFreq = frequencyArray[i];
                frequencyArray[i] = frequencyArray[j];
                frequencyArray[j] = tempFreq;

                char tempChar = letterArray[i];
                letterArray[i] = letterArray[j];
                letterArray[j] = tempChar;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        cout << letterArray[i] << ": " << frequencyArray[i] << endl;
    }
    cout << endl;
}

void frequencyGraph(char letters[], int size) {
    int frequency[26] = {};

    for (int i = 0; i < size; i++) {
        if (letters[i] >= 'a' && letters[i] <= 'z') {
            frequency[letters[i] - 'a']++;
        }
    }

    int maxNumberOfRows = 0;
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > maxNumberOfRows) {
            maxNumberOfRows = frequency[i];
        }
    }

    for (int row = maxNumberOfRows; row > 0; row--) {
        cout << row << " ";
        for (int i = 0; i < 26; i++) {
            if (frequency[i] >= row) {
                cout << "*";
            } else {
                cout << " ";
            }

            if (i < 25) {
                cout << " ";
            }
        }
        cout << endl;
    }

    cout << "  ";
    for (int i = 0; i < 26; i++) {
        cout << char('a' + i);
        if (i < 25) {
            cout << " ";
        }
    }
    cout << endl;
}

#include "program3functions.h"

