#include <math.h>

#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>


using namespace std;

ifstream inputFile;

bool contains(string s, char c) { return s.find(c) != string::npos; }

string part1() {
    int result = 0;
    for (int i = 0; i < 200; i++) {
        string str;
        for (int j = 0; j < 11; j++) inputFile >> str;

        for (int j = 0; j < 4; j++) {
            inputFile >> str;
            if (str.size() == 2 || str.size() == 3 || str.size() == 4 ||
                str.size() == 7)
                result++;
        }
    }
    return to_string(result);
}
string part2() {
    int result = 0;
    for (int i = 0; i < 200; i++) {
        int _1i = -1, _4i = -1;
        string str, diff = "";
        vector<int> resi;
        vector<string> ress;
        vector<string> five_long, six_long;
        for (int j = 0; j < 10; j++) {
            inputFile >> str;
            if (str.size() == 2) {
                resi.push_back(1);
                ress.push_back(str);
                _1i = ress.size() - 1;
            } else if (str.size() == 3) {
                resi.push_back(7);
                ress.push_back(str);
            } else if (str.size() == 4) {
                resi.push_back(4);
                ress.push_back(str);
                _4i = ress.size() - 1;
            } else if (str.size() == 7) {
                resi.push_back(8);
                ress.push_back(str);
            } else if (str.size() == 5) {
                five_long.push_back(str);
            } else if (str.size() == 6) {
                six_long.push_back(str);
            }
        }
        for (auto &&e : ress[_4i])
            if (!contains(ress[_1i], e)) diff += e;

        for (int j = 0; j < 3; j++) {
            if (contains(five_long[j], ress[_1i][0]) &&
                contains(five_long[j], ress[_1i][1])) {
                resi.push_back(3);
                ress.push_back(five_long[j]);
                five_long.erase(five_long.begin() + j);
                break;
            }
        }
        for (int j = 0; j < 2; j++) {
            if (contains(five_long[j], diff[0]) &&
                contains(five_long[j], diff[1])) {
                resi.push_back(5);
                ress.push_back(five_long[j]);
                five_long.erase(five_long.begin() + j);
                break;
            }
        }
        resi.push_back(2);
        ress.push_back(five_long[0]);
        five_long.erase(five_long.begin());

        for (int j = 0; j < 3; j++) {
            if (contains(six_long[j], ress[_4i][0]) &&
                contains(six_long[j], ress[_4i][1]) &&
                contains(six_long[j], ress[_4i][2]) &&
                contains(six_long[j], ress[_4i][3])) {
                resi.push_back(9);
                ress.push_back(six_long[j]);
                six_long.erase(six_long.begin() + j);
                break;
            }
        }
        for (int j = 0; j < 2; j++) {
            if (contains(six_long[j], diff[0]) &&
                contains(six_long[j], diff[1])) {
                resi.push_back(6);
                ress.push_back(six_long[j]);
                six_long.erase(six_long.begin() + j);
                break;
            }
        }
        resi.push_back(0);
        ress.push_back(six_long[0]);
        six_long.erase(six_long.begin());

        for (auto &e : ress) sort(e.begin(), e.end());

        inputFile >> str; 

        for (int j = 0; j < 4; j++) {
            inputFile >> str;
            sort(str.begin(), str.end());
            for (int x = 0; x < 10; x++) {
                if (str == ress[x]) {
                    result += resi[x] * pow(10, (3 - j));
                    break;
                }
            }
        }
    }
    return to_string(result);
}

int main() {
    cout << "2021/08:" << endl;

    inputFile.open("2021/08/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2021/08/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}

