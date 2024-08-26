#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

// 60. Write a Program to Implement Single-Level Inheritance
class Parent {
    public:
        void print() { cout << "This is a parent class." << endl; }
};

class Child : Parent {
    public:
        void print() { cout << "This is a child class." << endl; }
};

void No60() {
    cout << "No. 60: Single-Level Inheritance" << endl;
    Parent p; Child c;
    p.print(); c.print();   // Notice how the child class' function overrides the parent's
}

// 59. Write a Program to Implement the Concept of Function Overriding or Runtime Polymorphism

// 58. Write a Program to Implement the Concept of Operator Overloading

// 57. Write a Program to Implement the Concept of Compile-Time Polymorphism or Function Overloading
int add(int x, int y) {
    return x + y;
}

float add(float x, float y) {
    return x + y;
}

void No57() {
    cout << "No. 57: Function Overloading" << endl;
    int a, b; float c, d;   // Variables for their upcoming respective functions

    // Add ints
    cout << "Enter an integer: "; cin >> a;
    cout << "Enter another integer: "; cin >> b;
    cout << a << " + " << b << " = " << add(a,b) << endl;

    // Add floats, notice sthe same function name but with different variables
    cout << "Enter a FLOAT: "; cin >> c;
    cout << "Enter another float: "; cin >> d;
    cout << c << " + " << d << " = " << add(c,d) << endl;
}

// 56. Write a Program to Implement the Concept of Abstraction

// 55. Write a Program to Implement the Use of Encapsulation
class Encap {
    private:
        int x;
    public:
        void set(int n) { x = n; }
        int get() { return x; }
};

void No55() {
    cout << "No. 55: Encapsulation" << endl;
    
    int num;
    Encap obj;

    cout << "Enter a number: "; cin >> num;

    obj.set(num);
    cout << "The number of obj is: " << obj.get() << endl;
}

// 54. Write a Program for Octal to Binary Conversion
// Copy pasted No. 51, edited to be opoosite of No. 53
string otob(int n) {
    // Key-value dictionary/map when reading by 3 digits at a time
    map<char, string> convert = {
        {'0', "000"}, {'1', "001"}, {'2', "010"}, {'3', "011"},
        {'4', "100"}, {'5', "101"}, {'6', "110"}, {'7', "111"}
    };
    string bin = "";

    // Iterate through chars of string and convert to 3 digit binary number
    for (auto &c : to_string(n))
        bin += convert[c];

    // Erase leading 0's for aestethic purpose
    for (int i = 0; i < bin.length(); i++)
        if (bin.at(i) == '1') {
            bin.erase(bin.begin(), bin.begin() + i); break;
        }
    return bin;
}

void No54() {
    cout << "No. 54: Octal to Binary" << endl;

    int octal;

    cout << "Enter a number in decimal: ";
    cin >> octal;    // input the number in hexadecimal format
    cout << octal << " in binary form is " << otob(octal) << endl;   // output the number in decimal format

    // No55();
}


// 53. Write a Program for Binary to Octal Conversion
string btoo(string n) {
    // Key-value dictionary/map when reading by 3 digits at a time
    map<string, char> convert = {
        {"000", '0'}, {"001", '1'}, {"010", '2'}, {"011", '3'},
        {"100", '4'}, {"101", '5'}, {"110", '6'}, {"111", '7'}
    };
    string oct = "";        // Return statement

    // Iterate through string 3 digits at a time and convert to correct octal
    for (int i = 0; i < n.length(); i += 3)
        oct += convert[n.substr(i, 3)];

    return oct;
}

void No53() {
    cout << "No. 53: Binary to Octal" << endl;

    string bin;
    bool isBin = false;

    // Check if string is in binary - all characters are a 0 or 1
    while (!isBin) {
        bool binVal = true; // Binary validation - check if string is in binary

        cout << "Enter a number in binary format (digits 0 or 1): ";
        cin >> bin;

        // Check if string is in binary
        for (auto &c : bin) {
            if (c != '0' && c != '1') {
                binVal = false; break;  // Assign binary validation to false if not a 0 or 1
            }
        }

        if (binVal)
            isBin = true;
        else
            cout << "This is not a valid binary number." << endl;
    }

    // Insert 0's as necessary to fit binary-to-octal format (3 digits each)
    if (bin.length() % 3 == 1)
        bin.insert(0, "00");
    else if (bin.length() % 3 == 2)
        bin.insert(bin.begin(), '0');
    
    cout <<  bin << " in octal form is " << btoo(bin) << endl;   // output the number in hexadecimal format

    No54();
}

// 52. Write a Program for Decimal to Hexadecimal Conversion
void No52() {
    // Copy pasted No. 49, swapped decimal & hexadecimal
    cout << "No. 52: Decimal to Hexadecimal" << endl;

    int decimal;

    cout << "Enter a number: ";
    cin >> decimal;
    cout <<  decimal << " in hexadecimal form is " << hex << decimal << endl;   // output the number in hexadecimal format
}

// 51. Write a Program for Decimal Octal Conversion
void No51() {
    // Copy pasted No. 48, swapped decimal and octal 
    cout << "No. 51: Decimal to Octal" << endl;

    int decimal;

    cout << "Enter a number: ";
    cin >> decimal;
    cout << decimal << " in octal form is " << oct << decimal << endl;   // output the number in octal format

    No52();
}

// 50. Write a Program for Decimal to Binary Conversion
// No std::bin, this function will convert it by long division
string dtob(int n) {
    stack<string> dtb;
    string bin = "";

    // Binary long division
    while (n != 0 && n != 1) {
        dtb.push(to_string(n % 2)); n /= 2;
    }

    dtb.push(to_string(n % 2)); // Push last digit which should be 1 or 0 at this point.

    while (!dtb.empty()) {
        bin += dtb.top(); dtb.pop();    // Append binary digits to return string
    }

    return bin;
}

void No50() {
    cout << "No. 50: Decimal to Binary" << endl;

    int decimal;

    cout << "Enter a number in decimal: ";
    cin >> decimal;    // input the number in hexadecimal format
    cout << decimal << " in binary form is " << dtob(decimal) << endl;   // output the number in decimal format

    No51();
}

// 49. Write a Program for Hexadecimal to Decimal Conversion
void No49() {
    cout << "No. 49: Hexadecimal to Decimal" << endl;

    int hexdec;

    cout << "Enter a number in hexadecimal (digits 0-9, A-F): ";
    cin >> hex >> hexdec;    // input the number in hexadecimal format
    cout << hex << hexdec << " in decimal form is " << dec << hexdec << endl;   // output the number in decimal format
}

// 48. Write a Program for Octal to Decimal Conversion
void No48() {
    cout << "No. 48: Octal to Decimal" << endl;

    int octal;

    cout << "Enter a number in octal (digits 0-7): ";
    cin >> oct >> octal;    // input the number in octal format
    cout << oct << octal << " in decimal form is " << dec << octal << endl;   // output the number in decimal format

    No49();
}

// TODO: Find method for this problem
// 47. Write a Program to Find the Maximum and Minimum of the Two Numbers Without Using the Comparison Operator
void No47() {
    cout << "No. 47: Max & Min w/o Comparison" << endl;

    int x, y;

    cout << "Enter a number: "; cin >> x;
    cout << "Enter another: "; cin >> y;

    No48();
}

// 46. Write a Program to Check for the Equality of Two Numbers Without Using Arithmetic or Comparison Operator
void No46() {
    cout << "No. 46: Equality Check w/o Arithmetic or Comparison Operators" << endl;

    int x, y;
    bool match = true;

    cout << "Enter number 1: "; cin >> x;
    cout << "Enter number 2: "; cin >> y;

    // Bitwise XOR operator, which doesn't seem to be a comparison operator in the documentation
    cout << x << " and " << y << (x ^ y ? " are NOT " : " are ") << "a match." << endl;
}

// 45. Write a Program to Print the Maximum Value of an Unsigned int Using One’s Complement (~) Operator
void No45() {
    cout << "No. 45: Max Value of Unsigned Int With Complement Operator" << endl;

    cout << "Max value of unsigned int is " << (unsigned int)~0 << endl;

    No46();
}

// 44. Write a Program to  Swap the Values of Two Variables Without Using any Extra Variable
void No44() {
    cout << "No. 44: Swap Number w/o Extra Variable" << endl;

    int x, y;

    cout << "Enter a number: "; cin >> x;
    cout << "Enter another: "; cin >> y;

    cout << "Before: x = " << x << ", y = " << y << endl;
    // Unsure whether this passes because std::swap does use an extra varaible (T temp),
    // but *I'm* not explicitly using this extra variable, will comment out an alternative just in case
    swap(x,y);

    // Alternative
    // y -= x; x += y; y = x - y;

    cout << "After: x = " << x << ", y = " << y << endl;
}

// TODO: Find method for this problem
// 43. Write a Program to Print All Natural Numbers up to N Without Using a Semi-Colon
void No43() {
    int n = -1, i = 0;
    while (n < 0) {
        cout << "Enter a number: ";
        cin >> n;

        if (n < 0)
            cout << "That is not a valid number." << endl;
    }

    No44();
}

// 42. Write a Program to Count the Sum of Numbers in a String
void No42() {
    cout << "No. 42: String to Sum" << endl;

    string input;
    int sum = 0;

    cin.ignore();
    cout << "Enter a string with numbers: ";
    getline(cin, input);

    for (auto c : input) {
        if ((int)c >= 48 && (int)c <= 57)   // ASCII value
            sum += (int)c - 48;             // Subtract to convert from ASCII value to symbol (decimal #'s)
    }

    cout << "Sum = " << sum << endl;
    No43();
}

// 41. Write a Program to Calculate the Factorial of a Number Using Recursion
int factorial (int n) {     // Copy pasted No. 36
    if (n == 0 || n == 1)
        return 1;
    
    return n * factorial(n-1);
}

void No41() {
    cout << "No. 41: Factorial Recursion" << endl;

    int n = -1;

    while (n < 0) {
        cout << "Enter a number to calculate the factorial: ";
        cin >> n;

        if (n < 0)
            cout << "That is not a valid number." << endl;
    }

    cout << n << "! = " << factorial(n) << endl;

    No42();
}

int main() {
    No55();
    return 0;
}