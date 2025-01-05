#include <set>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

fstream inputFile;

string part1() {
    set<pair<int, int>> s;
    s.insert({0, 0});

    int x = 0, y = 0;
    char ch;
    while (inputFile >> ch) {
        switch (ch) {
            case '>':
                x++;
                break;
            case '<':
                x--;
                break;
            case '^':
                y++;
                break;
            case 'v':
                y--;
                break;
        }
        s.insert({x, y});
    }
    return to_string(s.size());
}
string part2() {
    set<pair<int, int>> s;
    s.insert({0, 0});

    int x = 0, y = 0, rx = 0, ry = 0;
    bool robot = true;
    char ch;
    while (inputFile >> ch) {
        if (!robot) {
            switch (ch) {
                case '>':
                    x++;
                    break;
                case '<':
                    x--;
                    break;
                case '^':
                    y++;
                    break;
                case 'v':
                    y--;
                    break;
            }
            s.insert({x, y});
        } else {
            switch (ch) {
                case '>':
                    rx++;
                    break;
                case '<':
                    rx--;
                    break;
                case '^':
                    ry++;
                    break;
                case 'v':
                    ry--;
                    break;
            }
            s.insert({rx, ry});
        }
        robot = !robot;
    }
    return to_string(s.size());
}

int main() {
    cout << "2015/03:" << endl;

    inputFile.open("2015/03/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2015/03/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}

