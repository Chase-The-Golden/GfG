#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

// 40. Write a Program to Calculate the Length of the String Using Recursion
int No40_Recursion(char s[], int n) {
    const int add = 1;

    if (s[n+1] != '\0')
        return add + No40_Recursion(s, ++n);
    else
        return add;
}

void No40() {       // Copy pasted No. 38
    cout << "No. 40: String Length w/ Recursion" << endl;

    const unsigned int BUFF = 512;
    char input[BUFF];

    cout << "Enter a string: ";
    cin.getline(input, BUFF);

    cout << "Length of string \"" << input << "\": " << No40_Recursion(input, 0) << endl;
}

// 39. Write a Program to Check if the Given String is Palindrome or not Using Recursion
// Forward recursion
string No39_FRecur(char s[], int n) {
    string c(1, s[n]);

    if (n < strlen(s) - 1) 
        return c + No39_FRecur(s, ++n);
    else
        return c;
}

// Backward recursion
string No39_BRecur(char s[], int n) {
    string c(1, s[n]);

    if (n > 0) 
        return c + No39_BRecur(s, n-1);
    else
        return c;
}

void No39() {       // Copy pasted No. 38
    cout << "No. 39: Palindrome? W/ Recursion" << endl;

    const unsigned int BUFF = 512;
    char input[BUFF];

    cout << "Enter a string: ";
    cin.getline(input, BUFF);

    bool isOdd = strlen(input) % 2 == 1;
    int uHalf = strlen(input) / 2; int lHalf = strlen(input) / 2 - (isOdd ? 0 : 1);

    cout << input << (No39_BRecur(input, lHalf) == No39_FRecur(input, uHalf) ? 
        " is " : " is NOT ") << "a palindrome." << endl;

    No40();
}


// 38. Write a C++ Program to Print the Given String in Reverse Order Using Recursion
string No38_Recursion(char s[], int n) {
    string c(1, s[n]);

    if (n > 0) 
        return c + No38_Recursion(s, n-1);
    else
        return c;
}

void No38() {
    cout << "No. 38: Reverse String w/ recursion" << endl;

    const unsigned int BUFF = 512;
    char input[BUFF];

    cout << "Enter a string: ";
    cin.getline(input, BUFF);

    cout << No38_Recursion(input, strlen(input) - 1) << endl;

    No39();
}

// 37. Write a Program to Print the Given String in Reverse Order 
void No37() {
    cout << "No. 37: Reverse String" << endl;

    string input;

    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, input);
    reverse(input.begin(), input.end());

    cout << input << endl;

    No38();
}

// 36. Write a Program to Print the Pascal Triangle
int factorial (int n) {     // Copy pasted No. 14
    if (n == 0 || n == 1)
        return 1;
    
    return n * factorial(n-1);
}

void No36() {
    cout << "No. 36: Pascal's Triangle" << endl;

    int size = -1, num = 0;

    while (size < 0) {
        cout << "Enter the size (# layers) of the pyramid: ";
        cin >> size;

        if (size < 0)
            cout << "This is not a valid size." << endl;
    }

    int numSpaces = size - 1;   // Max # of spaces in pyramid is n-1

    // To account for aesthetic, spaces are added appropriate to pyramid regardless of even/odd number of layers
    for (int i = 0; i < size; i++) {
        int j = numSpaces;
        while (j > 0) { cout << " "; j--; }

        for (j = 0; j <= i; j++) 
            cout << factorial(i) / (factorial(j) * factorial(i - j)) << " ";

        cout << endl;
        numSpaces--;
    }

    No37();
}

// 35. Write a Program to Print Floyd’s Triangle
void No35() {      // Copy pasted No. 32, edited to have numbers instead of stars
    cout << "No. 35: Floyd's Triangle" << endl;

    int size = -1, num = 0;

    while (size < 0) {
        cout << "Enter the size (# layers) of the pyramid: ";
        cin >> size;

        if (size < 0)
            cout << "This is not a valid size." << endl;
    }

    for (int i = 1; i <= size; i++) {
        int j = i;
        for (j = 0; j < i; j++) { cout << ++num << " "; }
        cout << endl;
    }

    No36();
}

// 34. Write a Program to Print a Triangle Star Pattern
void No34() {
    cout << "No. 34: Triangle Pattern" << endl;

    int size = -1;

    while (size < 0) {
        cout << "Enter the size (# layers) of the pyramid: ";
        cin >> size;

        if (size < 0)
            cout << "This is not a valid size." << endl;
    }

    for (int i = 1; i <= size; i++) {
        int j = i;

        for (j = 0; j < i; j++)
            cout << "*";
        cout << endl;
    }

    No35();
}

// 33. Write a Program to print an Inverted Pyramid 
void No33() {       // Copy pasted No. 32, reversed for loop order
    cout << "No. 33: Inverted Pyramid" << endl;

    int size = -1;

    while (size < 0) {
        cout << "Enter the size (# layers) of the pyramid: ";
        cin >> size;

        if (size < 0)
            cout << "This is not a valid size." << endl;
    }
    
    int numSpaces = 0;   // Max # of spaces in pyramid is n-1

    // Removed spaces, now each star has 2 LESS than last layer to maintain aesthetic
    for (int i = size; i > 0; i--) {
        int j = numSpaces;
        while (j > 0) { cout << " "; j--; } numSpaces++;

        j = i * 2 - 1;
        while (j > 0) { cout << "*"; j--; }

        cout << endl;
    }

    No34();
}

// 32. Write a Program to Print a Simple Pyramid Pattern
void No32() {       // Copy pasted No. 29, edited
    cout << "No. 29: Simple Pyramid" << endl;

    int size = -1;

    while (size < 0) {
        cout << "Enter the size (# layers) of the pyramid: ";
        cin >> size;

        if (size < 0)
            cout << "This is not a valid size." << endl;
    }
    
    int numSpaces = size - 1;   // Max # of spaces in pyramid is n-1

    // Removed spaces, now each star has 2 more than last layer to maintain aesthetic
    for (int i = 1; i <= size; i++) {
        int j = numSpaces;
        while (j > 0) { cout << " "; j--; } numSpaces--;

        j = i * 2 - 1;
        while (j > 0) { cout << "*"; j--; }

        cout << endl;
    }

    No33();
}

// 31. Write a Program to Print the Rotated Hourglass Pattern
void No31() {
    cout << "No. 31: Rotated Hourglass" << endl;

    int size = -1;
    stack<string> layer;

    while (size < 0) {
        cout << "Enter the size (# layers) of the hourglass: ";
        cin >> size;
        
        if (size < 0)
            cout << "That is not a valid size." << endl;
    }

    bool isOdd = size % 2;

    for (int i = 0; i < (isOdd ? size / 2 + 1 : size / 2); i++) {
        string line = "";

        for (int j = 0; j < size; j++) {
            if (j < 1 + i || j > size - 2 - i) line += "* ";
            else line += "  ";
        }
        
        line += "\n";
        cout << line;
        layer.push(line);
    }

    if (isOdd) layer.pop();

    while (!layer.empty()) {
        cout << layer.top(); layer.pop();
    }

    No32();
}

int main() {
    No31();
    return 0;
}