#include <fstream>
#include <iostream>

using namespace std;

ifstream inputFile;

string part1() {
    int x = 0, y = 0, X;
    string instruction;

    while (inputFile >> instruction >> X) {
        if (instruction == "forward")
            x += X;
        else if (instruction == "down")
            y += X;
        else
            y -= X;
    }
    return to_string(y * x);
}
string part2() {
    int x = 0, y = 0, aim = 0, X;
    string instruction;

    while (inputFile >> instruction >> X) {
        if (instruction == "down")
            aim += X;
        else if (instruction == "up")
            aim -= X;
        else {
            x += X;
            y += X * aim;
        }
    }
    return to_string(y * x);
}

int main() {
    cout << "2021/02:" << endl;

    inputFile.open("2021/02/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2021/02/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}
