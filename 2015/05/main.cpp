#include <string>
#include <fstream>
#include <iostream>

using namespace std;

ifstream inputFile;

bool is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool is_bad(string s) {
    return (s == "ab" || s == "cd" || s == "pq" || s == "xy");
}

string part1() {
    int n = 0;
    string line;
    while (getline(inputFile, line)) {
        int vowels = 0;
        bool dub = false, bad = false;
        for (size_t i = 0; i < line.length() - 1; i++) {
            if (is_bad(line.substr(i, 2))) {
                bad = true;
                break;
            }
            if (is_vowel(line[i])) vowels++;
            if (line[i] == line[i + 1]) dub = true;
        }
        if (is_vowel(line[line.length() - 1])) vowels++;
        if (vowels >= 3 && dub && !bad) n++;
    }
    return to_string(n);
}
string part2() {
    int n = 0;
    string line;
    while (getline(inputFile, line)) {
        bool r1 = false;
        bool r2 = false;
        for (size_t i = 0; i < line.length() - 2; i++) {
            if (r1 && r2) break;
            if (line[i] == line[i + 2]) r1 = true;
            if (line.substr(i + 2, line.length() - i - 2)
                    .find(line.substr(i, 2)) != string::npos)
                r2 = true;
        }
        if (r1 && r2) n++;
    }
    return to_string(n);
}

int main() {
    cout << "2015/05:" << endl;

    inputFile.open("2015/05/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2015/05/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}
