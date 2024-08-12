#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <ctime>

using namespace std;

// 30. Write a Program to Print the Hourglass Pattern
void No30() {       // Copy paste No 28, edited reverse
    cout << "No. 30: Hourglass Pattern" << endl;

    int size = -1;
    stack<string> layer;

    while (size < 0) {
        cout << "Enter the size (# layers) of the hourglass: ";
        cin >> size;

        if (size < 0)
            cout << "This is not a valid size." << endl;
    }
    
    // Determine start position of stars
    bool isEven = size % 2 == 0;
    const int start = size / 2 - (int)isEven;

    for (int i = size; i >= (isEven ? 2 : 1); i -= 2) {
        string line = "";

        int j = 0;  // Reversed space count
        while (isEven ? j <= start - (i / 2) : j < start - (i / 2)) {
            line += " "; j++;
        }

        j = i;      // Reversed star count
        while (j > 0) { line += "*"; j--; }

        line += "\n";
        cout << line;
        layer.push(line);
    }

    layer.pop();    // Pop center of hourglass
    while (!layer.empty()) {
        cout << layer.top(); layer.pop();
    }
}

// 29. Write a Program to Print a Pyramid Pattern
void No29() {    // Copy pasted No. 28, trimmed & edited
    cout << "No. 29: Pyramid Pattern" << endl;

    int size = -1;

    while (size < 0) {
        cout << "Enter the size (# layers) of the pyramid: ";
        cin >> size;

        if (size < 0)
            cout << "This is not a valid size." << endl;
    }
    
    int numSpaces = size - 1;   // Max # of spaces in pyramid is n-1

    // To account for aesthetic, spaces are added appropriate to pyramid regardless of even/odd number of layers
    for (int i = 1; i <= size; i++) {
        int j = numSpaces;
        while (j > 0) { cout << " "; j--; }

        j = i;
        while (j > 0) { cout << "* "; j--; }

        cout << endl;
        numSpaces--;
    }

    No30();
}

// 28. Write a Program to Print a Diamond Pattern
void No28() {
    cout << "No. 28: Diamond Pattern" << endl;

    int size = -1;
    stack<string> layer;

    while (size < 0) {
        cout << "Enter the size (# layers) of the diamond: ";
        cin >> size;

        if (size < 0)
            cout << "This is not a valid size." << endl;
    }
    
    // Determine start position of stars
    bool isEven = size % 2 == 0;
    const int start = size / 2 - (int)isEven;

    for (int i = (isEven ? 2 : 1); i <= size; i += 2) {
        string line = "";

        // First layer has n/2 preceding spaces in odd number of layers : (n/2)-1 spaces in even
        // Each layer up to halfway of diamond subtracts number of preceding spaces
        int j = start - (i / 2);
        while (isEven ? j >= 0 : j > 0) { line += " "; j--; }

        // Each layer has i stars up to halfway of diamond
        j = i;
        while (j > 0) { line += "*"; j--; }

        line += "\n";
        cout << line;
        layer.push(line);
    }

    layer.pop();    // Pop center of diamond
    while (!layer.empty()) {
        cout << layer.top(); layer.pop();
    }

    No29();
}

// 27. Write a Program to Check if Two Strings are Anagram or Not
void No27() {
    cout << "No. 27: Anagram?" << endl;

    string str1, str2;
    bool isAnagram = true;

    cout << "Enter string 1: "; cin >> str1;
    cout << "Enter string 2: "; cin >> str2;

    // Auto check string length, unequal length means not anagram
    if (str1.length() != str2.length()) {
        isAnagram = false;
    } else {
        // Sort characters in string & iterate both sequences at same time to check matching chars
        string str1_sort = str1, str2_sort = str2;
        sort(str1_sort.begin(), str1_sort.end());
        sort(str2_sort.begin(), str2_sort.end());

        for (int i = 0; i < str1_sort.length(); i++) {
            if (str1_sort.at(i) != str2_sort.at(i)) {
                isAnagram = false; break;
            }
        }
    }

    cout << str1 << " and " << str2 << (isAnagram ? " are " : " are NOT ") << "an anagram." << endl;

    No28();
}

// 26. Write a Program to Check if the Given String is Palindrome or Not
void No26() {       // Copy pasted No. 17, trimmed
    cout << "No. 26: Palindrome?" << endl;

    stack<char> palinChar;
    string input, inputLower = "";
    bool isPalin = true;

    cout << "Enter a single word: ";
    cin >> input;

    for (auto &c : input)
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

    No27();
}

// 25. Write a Program to Calculate the Sum of Elements in an Array
void No25() {
    cout << "No 25: Sum of array elements" << endl;

    int size = -1, sum = 0; const int max = 10; // Capping at a max for easy human interaction

    while (size < 1 || size > max) {
        cout << "Enter an array size of 1 to " << max << ": ";
        cin >> size;

        if (size < 1 || size > max)
            cout << "Invalid size. Try again." << endl;
    }

    int *arr = new int[size];    // Pointer array of input size

    // MANUALLY assign
    for (int i = 0; i < size; i++) {
        int num;

        cout << "Enter a number " << i+1 << ": ";
        cin >> num;
        arr[i] = num;
    }

    for (int i = 0; i < size; i++) {
        sum += arr[i];  // Summation
    }

    cout << "Sum: " << sum << endl;
    delete arr;         // Clear pointer

    No26();
}

// 24. Write a Program to Find the Second Smallest Element in an Array
void No24() {       // Copy paste No. 23, added sort to search 2nd element
    cout << "No. 24: Second Smallest Element in Array" << endl;

    srand(time(nullptr));
    int size = 0;

    while (size < 1) {
        cout << "Enter a number of array elements: ";
        cin >> size;

        if (size < 1)
            cout << "Not a valid number!" << endl;
    }
    
    int *arr = new int[size];    // Pointer array of input size

    // Randomly assign
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }

    // Uncomment blocks below if you want to see the sort in action
    /*
    cout << "Before: ";
    for (int i = 0; i < size; i++) {
        if (i == 10) {
            cout << "..."; break;
        }
        cout << arr[i] << (i != size-1 ? ", " : "");
    }
    cout << endl;
    */

    sort(arr, arr + size);

    /*
    cout << "After: ";
    for (int i = 0; i < size; i++) {
        if (i == 10) {
            cout << "..."; break;
        }
        cout << arr[i] << (i != size-1 ? ", " : "");
    }
    cout << endl;
    */
    cout << "Second element is: " << arr[1] << endl;

    delete arr; // Clear pointer

    No25();
}


// 23. Write a Program to Find the Smallest and Largest Element in an Array
void No23() {
    cout << "No. 23: Smallest & Largest Element in Array" << endl;

    srand(time(nullptr));
    int size = 0;

    while (size < 1) {
        cout << "Enter a number of array elements: ";
        cin >> size;

        if (size < 1)
            cout << "Not a valid number!" << endl;
    }
    
    int *arr = new int[size];    // Pointer array of input size

    // Randomly assign
    for (int i = 0; i < size; i++) {
        arr[i] = rand();
    }

    // List out array, ellipses added for size over 10
    for (int i = 0; i < size; i++) {
        if (i == 10) {
            cout << "..." << endl; break;
        }
        cout << arr[i] << (i != size-1 ? ", " : "");
    }
        
    cout << "Max element: " << *max_element(arr, arr + size) << endl;
    cout << "Min element: " << *min_element(arr, arr + size) << endl;

    delete arr; // Clear pointer

    No24();
}

// 22. Write a Program for Finding the Roots of a Quadratic Equation
void No22() {
    cout << "No. 22: Roots of Quadratic Equation" << endl;
    int a = 0, b, c;

    // Prevent divide by 0
    while (a == 0) {
        cout << "_x^2 + ?x + ? = 0" << endl; cin >> a;
        cout << a << "x^2 + _x + ? = 0" << endl; cin >> b;
        cout << a << "x^2 + " << b << "x + _ = 0" << endl; cin >> c;
        cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;

        if (a == 0)
            cout << "Error: a cannot be 0." << endl;
    }

    if ((pow(b,2) - 4 * a * c) < 0)
        cout << "NO SOLUTION AVAILABLE" << endl;
    else {
        float x1 = (-b + sqrtf(pow(b,2) - 4 * a * c)) / (2 * a);
        float x2 = (-b - sqrtf(pow(b,2) - 4 * a * c)) / (2 * a);

        cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
    }

    No23();
}

// 21. Write a Program to Calculate the Lowest Common Multiple (LCM) of Two Numbers
int gcd (int a, int b) {        // Copy paste No. 20, added LCM formula
    vector<int> mult1, mult2;

    /* Brute force, but at most half of the possible multiples
    as going over the other half will be redundant */
    for (int i = max(a, b) / 2; i > 1; i--) {
        if (a % i == 0)
            mult1.push_back(i);
        if (b % i == 0)
            mult2.push_back(i);
    }

    // Brute force GCD
    for (auto &i : mult1) {
        for (auto &j : mult2) {
            if (j == i) {
                return j;
            }
        }
    }

    return 1;
}

void No21() {
    cout << "No. 21: Lowest Common Multiple:" << endl;

    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    int lcm = abs(num1) * abs(num2) / gcd(num1, num2);
    cout << "The Lowest Common Multiple of " << num1 << " and " << num2 << " is " << lcm << endl;

    No22();
}

int main() {
    No21();

    return 0;
}