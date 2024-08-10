#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cmath>
#include <vector>

using namespace std;

// 20. Write a Program to Calculate the Greatest Common Divisor of Two Numbers
int gcd (int a, int b) {
    vector<int> mult1, mult2;

    /* Brute force, but at most half of the possible multiples
    as going over the other half will be redundant */
    for (int i = max(a, b) / 2; i > 1; i--) {
        if (a % i == 0)
            mult1.push_back(i);
        if (b % i == 0)
            mult2.push_back(i);
    }

    // Linearly search for GCD
    for (auto i : mult1) {
        for (auto j : mult2) {
            if (j == i) {
                return j;
            }
        }
    }

    return 1;
}

void No20() {
    cout << "No. 20: Greatest Common Divisor" << endl;

    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    cout << "The Greatest Common Divisor of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;
}

// 19. Write a Program to Find the Nth Term of the Fibonacci Series

void No19() {
    cout << "No. 19: Nth Term Fibonacci" << endl;

    int n = -1;

    while (n < 0) {
        cout << "Enter a number: ";
        cin >> n;

        if (n < 0)
            cout << "That is not a valid number..." << endl;
    }

    float phi = (sqrt(5) + 1) / 2;
    float fib = (pow(phi, n) - pow(-(1/phi), n)) / sqrt(5);

    cout << "The nth term of the fibonacci sequence is: " << (int)fib << endl;

    No20();
}

// 18. Write a Program to Check Whether a Number is an Armstrong Number or Not
void No18() {
    cout << "No. 18: Armstrong #?" << endl;

    int num, power, sum = 0;
    string numStr;

    cout << "Input a number: ";
    cin >> num;

    numStr = to_string(num);
    power = numStr.length();

    for (auto c : numStr) {
        sum += pow(c - '0', power);
    }

    cout << num << (num == sum ? " is " : " is NOT ") << "an armstrong number." << endl;

    No19();
}

// 17. Write a Program to Check Palindrome
void No17() {
    cout << "No. 17: Palindrome?" << endl;

    stack<char> palinChar;
    string input, inputLower = "";
    bool isPalin = true;

    cout << "Enter a single word: ";
    cin >> input;

    for (auto c : input)
        inputLower += tolower(c);

    int half = input.length() % 2 == 0 ? input.length() / 2 : input.length() / 2 + 1;

    for (int i = 0; i < input.length() / 2; i++) {
        palinChar.push(inputLower.at(i));
    }
    for (int i = half; i < input.length(); i++) {
        if (inputLower.at(i) != palinChar.top()) {
            isPalin = false;
            break;
        }
        palinChar.pop();
    }

    cout << input << (isPalin ? " is " : " is NOT ") << "a palindrome." << endl;

    No18();
}

// 16. Write a Program to Check the Prime Number
void No16() {
    cout << "No. 16: Prime Number?" << endl;

    int num = 0; bool isPrime = true;

    while (num < 1) {
        cout << "Enter a positive number: ";
        cin >> num;

        if (num < 1)
            cout << "This is not a positive number." << endl;
    }

    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }

    cout << num << (isPrime ? " is " : " is NOT ") << "a prime number." << endl;

    No17();
}

// 15. Write a Program to Find a Leap Year or Not
void No15() {
    cout << "No. 15: Leap Year?" << endl;

    int year; bool isLeapYear = false;

    cout << "Enter a year: ";
    cin >> year;

    if (year % 4 == 0) {
        isLeapYear = true;
        if (year % 100 == 0) {
            isLeapYear = false;
            if (year % 400 == 0)
                isLeapYear = true;
        }
    }

    cout << year << " is " << (isLeapYear ? "a leap year." : "NOT a leap year.") << endl;

    No16();
}

// 14. Write a Program to Find the Factorial of a Number Using Loops
void No14() {
    cout << "No. 14: Factorial" << endl;

    unsigned int num;
    unsigned long long fact = 1;

    cout << "Enter a number for factorial: ";
    cin >> num;

    if (num > 1) {
        for (int i = 2; i <= num; i++)
            fact *= i;
    }

    cout << fact << endl;

    No15();
}

// 13. Write a Program to Find the Sum of the First N Natural Numbers
int No13_Recursive(int n) {
    if (n == 0) return n;
    else return n + No13_Recursive(n-1);
}

void No13() {
    cout << "No. 13: Sum of first N natural #'s" << endl;

    unsigned int n = 0;

    while (n < 1) {
        cout << "Enter a natural number: ";
        cin >> n;

        if (n < 1)
            cout << "That is not a natural number." << endl;
    }
    
    cout << "The sum is " << No13_Recursive(n) << "." << endl;

    No14();
}

// 12. Write a Program to Remove Spaces From a String
void No12() {
    cout << "No. 12: Remove Spaces from String" << endl;

    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    for (auto c : input) {
        if (isspace(c)) continue;
        cout << c;
    }

    cout << endl;

    No13();
}

// 11. Write a Program to Remove All Characters From a String Except Alphabets
void No11() {
    cout << "No. 11: Remove all non-alphabetic characters" << endl;

    string input;

    cout << "Enter a string: ";
    getline(cin, input);

    for (auto c : input) {
        if(!isalpha(c)) continue;
        cout << c;
    }

    cout << endl;

    No12();
}

// 10. Write a Program to Remove the Vowels from a String
void No10() {
    cout << "No. 10: Remove Vowels" << endl;

    string input, output;

    cout << "Enter a string: ";
    getline(cin, input);

    for (auto c : input) {
        char lower_c = tolower(c);
        if (lower_c == 'a' || lower_c == 'e' || lower_c == 'i' ||
            lower_c == 'o' || lower_c == 'u' || lower_c == 'y')
                continue;
        cout << c;
    }

    cout << endl;

    No11();
}

// 9. Write a Program to Count the Number of Vowels 
void No9() {
    cout << "No. 9: # of Vowels" << endl;

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
    cout << "No. 8: Toggle characters upper/lowercase" << endl;

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
    cout << "No. 7: String length" << endl;

    string input;

    cout << "Enter a string: ";
    cin.ignore();
    getline(cin, input);
    cout << "The length of string " << input << " is " << input.size() << endl; // Not strlen

    No8();
}

// 6. Write a Program to Print Check Whether a Character is an Alphabet or Not
void No6() {
    cout << "No. 6: Alphabetic or not?" << endl;

    // Same as 5 but trimmed
    char input;
    cout << "Enter a character: ";
    cin >> input;

    cout << input << " is" << (isalpha(input) ? "" : " NOT") << " an alphabetic character." << endl;

    No7();
}

// 5. Write a Program to Check Whether a Character is a Vowel or Consonant
void No5() {
    cout << "No. 5: Vowel or Consonant?" << endl;

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
    cout << "No. 4: ASCII Value" << endl;
    char ascii;

    cout << "Enter a character: ";
    cin >> ascii;
    cout << ascii << "'s ASCII value is " << (int)ascii << endl;

    No5();
}

// 3. C++ Program To Check Whether Number is Even Or Odd
void No3() {
    cout << "No. 3: Even or Odd?" << endl;
    int num;

    cout << "Enter a number: ";
    cin >> num;
    cout << num << " is an " << (abs(num % 2) == 1 ? "odd" : "even") << " number." << endl;

     No4();
}

// 2. Write a Program to Find the Greatest of the Three Numbers.
void No2() {
    cout << "No. 2: Greatest of 3 numbers" << endl;

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
    cout << "No. 1: Positive or Negative?" << endl;
    
    int num = 0;
    cout << "Enter a number: ";
    cin >> num;
    cout << num << " is a " << (num >= 0 ? "positive" : "negative") << " number." << endl;

    No2();
}

int main() {
    No1();
    return 0;
}