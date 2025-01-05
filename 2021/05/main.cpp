#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

ifstream inputFile;

string part1() {
    int x1, x2, y1, y2;
    vector<vector<int>> diagram(1000, vector<int>(1000));
    for (int i = 0; i < 500; i++) {
        inputFile >> x1;
        inputFile.ignore(1);
        inputFile >> y1;
        inputFile.ignore(4);
        inputFile >> x2;
        inputFile.ignore(1);
        inputFile >> y2;

        if (!(x1 == x2 || y1 == y2)) continue;
        if (y1 == y2) {
            if (x1 > x2) {
                int tmp = x1;
                x1 = x2;
                x2 = tmp;
            }
            for (int j = x1; j <= x2; j++) diagram[j][y1]++;
        }
        if (x1 == x2) {
            if (y1 > y2) {
                int tmp = y1;
                y1 = y2;
                y2 = tmp;
            }
            for (int j = y1; j <= y2; j++) diagram[x1][j]++;
        }
    }
    int count = 0;
    for (auto &&row : diagram)
        for (auto &&i : row)
            if (i > 1) count++;
    return to_string(count);
}
string part2() {
    int x1, x2, y1, y2;
    vector<vector<int>> diagram(1000, vector<int>(1000));
    for (int i = 0; i < 500; i++) {
        inputFile >> x1;
        inputFile.ignore(1);
        inputFile >> y1;
        inputFile.ignore(4);
        inputFile >> x2;
        inputFile.ignore(1);
        inputFile >> y2;

        if (x1 == x2 || y1 == y2) {
            if (y1 == y2) {
                if (x1 > x2) {
                    int tmp = x1;
                    x1 = x2;
                    x2 = tmp;
                }
                for (int j = x1; j <= x2; j++) diagram[j][y1]++;
            } else if (x1 == x2) {
                if (y1 > y2) {
                    int tmp = y1;
                    y1 = y2;
                    y2 = tmp;
                }
                for (int j = y1; j <= y2; j++) diagram[x1][j]++;
            }
        } else if (x1 - y1 == x2 - y2) {
            if (x1 > x2) {
                int tmp = x1;
                x1 = x2;
                x2 = tmp;
                tmp = y1;
                y1 = y2;
                y2 = tmp;
            }
            // cout << x1 << "," << y1 << "->" << x2 << "," << y2 << "\n";
            for (int j = 0; j <= x2 - x1; j++) {
                diagram[x1 + j][y1 + j]++;
                // cout << x1 + j << " " << y1 + j << "\n";
            }
        } else if (x1 + y1 == x2 + y2) {
            if (x1 > x2) {
                int tmp = x1;
                x1 = x2;
                x2 = tmp;
                tmp = y1;
                y1 = y2;
                y2 = tmp;
            }
            // cout << x1 << "," << y1 << "->" << x2 << "," << y2 << "\n";
            for (int j = 0; j <= x2 - x1; j++) {
                diagram[x1 + j][y1 - j]++;
                // cout << x1 + j << " " << y1 - j << "\n";
            }
        }
    }
    int count = 0;
    for (auto &&row : diagram)
        for (auto &&i : row)
            if (i > 1) count++;
    return to_string(count);
}

int main() {
    cout << "2021/05:" << endl;

    inputFile.open("2021/05/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2021/05/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}