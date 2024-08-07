#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 10. Write a Program to Remove the Vowels from a String
void No10() {
    string input, output;

    cout << "Enter a string: ";
    getline(cin, input);

    for (auto c : input) {
        char lower_c = tolower(c);
        if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' ||
            lower_c == 'o' || lower_c == 'u' || lower_c == 'y')
                continue;
        output += c;
    }

    cout << output << endl;
}

// 9. Write a Program to Count the Number of Vowels 
void No9() {
    string input;
    int numVowels = 0;

    cout << "Enter a string: ";
    getline(cin, input);

    for (auto c : input) {
        char lower_c = tolower(c);
        if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' ||
            lower_c == 'o' || lower_c == 'u' || lower_c == 'y')
                numVowels++;
    }

    cout << "There are " << numVowels << " vowels in the string: " << input << endl;

    No10();
}

// 8. Write a Program to Toggle Each Character in a String 
void No8() {
    string input, output;

    cout << "Enter a string: ";
    getline(cin, input);
    
    for (auto c : input) {
        cout << (char)(isupper(c) ? tolower(c) : toupper(c));
    }

    cout << endl;

    No9();
}

// 7. Write a Program to Find the Length of the String Without using strlen() Function 
void No7() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);
    cout << "The length of string " << input << " is " << input.size() << endl; // Technically not strlen

    No8();
}

// 6. Write a Program to Print Check Whether a Character is an Alphabet or Not
void No6() {
    // Same as 5 but trimmed
    char input;
    cout << "Enter a character: ";
    cin >> input;

    cout << input << " is" << (isalpha(input) ? "" : " NOT") << " an alphabetic character." << endl;

    No7();
}

// 5. Write a Program to Check Whether a Character is a Vowel or Consonant
void No5() {
    char input;
    char vowels[] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U', 'y', 'Y'};
    bool isVowel = false;

    cout << "Enter a character: ";
    cin >> input;

    for (auto i : vowels) {
        if (input == i) {
            isVowel = true;
            break;
        }
    }

    if ((input >= 65 && input <= 90) || (input >= 97 && input <= 122))
        cout << input << " is a " << (isVowel ? "vowel" : "consonant") << "." << endl;
    else
        cout << input << " is not an alphabetic character..." << endl;

    No6();
}

// 4. Write a Program to Find the ASCII Value of a Character
void No4() {
    char ascii;

    cout << "Enter a character: ";
    cin >> ascii;
    cout << ascii << "'s ASCII value is " << (int)ascii << endl;

    No5();
}

// 3. C++ Program To Check Whether Number is Even Or Odd
void No3() {
    int num;

    cout << "Enter a number: ";
    cin >> num;
    cout << num << " is an " << (abs(num % 2) == 1 ? "odd" : "even") << " number." << endl;

     No4();
}

// 2. Write a Program to Find the Greatest of the Three Numbers.
void No2() {
    const int arrSize = 3;
    int findMax[arrSize];
    int num = 0;

    for (int i = 0; i < arrSize; i++) {
        cout << "Enter number " << i+1 << ": ";
        cin >> num;
        findMax[i] = num;
    }

    cout << "Max #: " << *max_element(findMax, findMax + arrSize) << endl;

    No3();
}

// 1. Write a C++ Program to Check Whether a Number is a Positive or Negative Number.
void No1() {
    int num = 0;
    cout << "Enter a number: ";
    cin >> num;
    cout << num << " is a " << (num >= 0 ? "positive" : "negative") << " number." << endl;

    No2();
}

int main() {
    No10();
    return 0;
}