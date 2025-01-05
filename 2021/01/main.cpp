#include <fstream>
#include <iostream>

using namespace std;

ifstream inputFile;

string part1() {
    int last, curr, result = 0;
    inputFile >> last;
    while (inputFile >> curr) {
        if (curr > last) result++;
        last = curr;
    }
    return to_string(result);
}
string part2() {
    int a, b, c, last, curr, result = 0;
    inputFile >> a;
    inputFile >> b;
    inputFile >> c;
    last = a + b + c;
    a = b;
    b = c;
    while (inputFile >> c) {
        curr = a + b + c;
        if (curr > last) result++;
        last = curr;
        a = b;
        b = c;
    }
    return to_string(result);
}

int main() {
    cout << "2021/01:" << endl;

    inputFile.open("2021/01/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2021/01/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}