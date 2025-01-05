#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

ifstream inputFile;

string part1() {
    vector<int> crabs(1000);
    for (int i = 0; i < 1000; i++) {
        inputFile >> crabs[i];
        inputFile.ignore(1);
    }

    sort(crabs.begin(), crabs.end());

    int least = 1410065407;
    for (int i = 0; i < crabs[999]; i++) {
        int curr = 0;
        for (auto &&crab : crabs) {
            int a = abs(crab - i);
            curr += a;
        }
        if (curr < least) least = curr;
    }
    return to_string(least);
}
string part2() {
    vector<int> crabs(1000);
    for (int i = 0; i < 1000; i++) {
        inputFile >> crabs[i];
        inputFile.ignore(1);
    }
    sort(crabs.begin(), crabs.end());

    int least = 1410065407;
    for (int i = 0; i < crabs[999]; i++) {
        int curr = 0;
        for (auto &&crab : crabs) {
            int a = abs(crab - i);
            curr += a * (a + 1) / 2;
            ;
        }
        if (curr < least) least = curr;
    }
    return to_string(least);
}

int main() {
    cout << "2021/07:" << endl;

    inputFile.open("2021/07/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2021/07/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}

