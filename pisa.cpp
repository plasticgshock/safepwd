#include <iostream>
#include <stdio.h>
#include <immintrin.h>
#include <stdexcept>
#include <string>
using namespace std;

void removeElement(string arr[], int size, int index) {
    if (index < 0 || index >= size) {
        cout << "Index out of bounds" << std::endl;
        return;
    }
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --size; // Reduce the size of the array
}
int findIndex(string arr[], int size, string elem) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == elem) {
            return i;
        }
    }
    return -1; // Element not found
}

string getpass() {
    unsigned int random_value;
    string s_s[3];// aaaa1-aaaaA-aaaa*
    char letters[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    char digits[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    char specials[] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
                       '-', '_', '=', '+', };
    const int n1 = sizeof(letters) / sizeof(letters[0]);
    const int n2 = sizeof(digits) / sizeof(digits[0]);
    const int n3 = sizeof(specials) / sizeof(specials[0]);
    for (int i = 0; i < 3; i++) {
        string s = "";
        for (int j = 0; j < 4; j++) {
            unsigned int random_value;
            if (_rdrand32_step(&random_value)) {
                s += letters[random_value % n1];
            }
            else {cout << "fuck you!";}
        }
        unsigned int random_value;
        if (_rdrand32_step(&random_value)) {
            s += digits[random_value % n2];
            s += specials[random_value % n3];
        }
        else { cout << "fuck you!"; }
        s_s[i] = s;

    }
    string sFinal = "";
    int index = 3;
    for (int i = 0; i < 3; i++) {
        unsigned int random_value;
        if (_rdrand32_step(&random_value)) {
            int choice = random_value % index;
            sFinal += s_s[choice] + "-";
            index--;
            removeElement(s_s, 3 ,findIndex(s_s, 3, s_s[choice]));
        }
        else { cout << "fuck you!"; }
    }
    sFinal.pop_back();
    return sFinal;
}


int main() {
    string amount;
    cout << "How many super-safe passwords do you want?: ";
    cin >> amount;
    try {
        int intAmount = std::stoi(amount);
        for (int i = 0; i < intAmount; i++) { cout << getpass() << endl; }
    }
    catch (...) {
        cout << "fuck you it's not a number! please try again" << endl;
    }
}
