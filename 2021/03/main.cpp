#include <cmath>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

ifstream inputFile;

string part1() {
    int common[12] = {0};
    string in;

    while (inputFile >> in) {
        for (int j = 0; j < 12; j++) {
            if (in[j] == '1')
                common[j]++;
            else
                common[j]--;
        }
    }

    int gamma = 0, epsilon = 0;
    for (int j = 0; j < 12; j++) {
        if (common[j] > 0)
            gamma += pow(2, 11 - j);
        else
            epsilon += pow(2, 11 - j);
    }

    return to_string(gamma * epsilon);
}
string part2() {
    vector<string> input;
    string s;
    while (inputFile >> s) input.push_back(s);

    vector<string> oxVector(input);
    vector<string> ocVector(input);
    for (int i = 0; i < 12; i++) {
        if (oxVector.size() != 1) {
            int common = 0;
            long unsigned int j = 0;
            for (long unsigned int j = 0; j < oxVector.size(); j++) {
                if (oxVector[j][i] == '1')
                    common++;
                else
                    common--;
            }
            char good = common >= 0 ? '1' : '0';
            while (j != oxVector.size()) {
                if (oxVector[j][i] != good)
                    oxVector.erase(oxVector.begin() + j);
                else
                    j++;
            }
        }
        if (ocVector.size() != 1) {
            int common = 0;
            long unsigned int j = 0;
            for (long unsigned int j = 0; j < ocVector.size(); j++) {
                if (ocVector[j][i] == '1')
                    common++;
                else
                    common--;
            }
            char good = common < 0 ? '1' : '0';
            while (j != ocVector.size()) {
                if (ocVector[j][i] != good)
                    ocVector.erase(ocVector.begin() + j);
                else
                    j++;
            }
        }
    }

    int ox = 0, oc = 0;
    for (int j = 0; j < 12; j++) {
        if (oxVector[0][j] == '1') ox += pow(2, 11 - j);
        if (ocVector[0][j] == '1') oc += pow(2, 11 - j);
    }
    return to_string(ox * oc);
}

int main() {
    cout << "2021/03:" << endl;

    inputFile.open("2021/03/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2021/03/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}
