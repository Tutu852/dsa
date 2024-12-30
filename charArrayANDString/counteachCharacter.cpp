

#include <iostream>
using namespace std;

void countElementsWithASCII(const string& str) {
    // Array to store counts for each ASCII value
    int asciiCoun[256] = {0};

    // Iterate through the string to count each character
    for (char ch : str) {
        asciiCoun[(int)ch]++;
        
        // Print the character and its count as soon as we encounter it
        cout << "Character: " << ch 
             << " (ASCII: " << (int)ch 
             << "), Count: " << asciiCoun[(int)ch] << endl;
    }
}

int main() {
    string input = "hello";
    countElementsWithASCII(input);
    return 0;
}
