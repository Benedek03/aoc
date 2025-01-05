#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

ifstream inputFile;
vector<vector<int>> grid;

enum class Command { turn_on, turn_off, toggle };
Command getCommand(stringstream& ss) {
    string s;
    ss >> s;
    if (s == "toggle") return Command::toggle;
    ss >> s;
    if (s == "on")
        return Command::turn_on;
    else
        return Command::turn_off;
}
void getCordinates(stringstream& ss, size_t& sx, size_t& sy,
                    size_t& ex, size_t& ey) {
    ss >> sx;
    ss.ignore(1);
    ss >> sy;
    ss.ignore(9);
    ss >> ex;
    ss.ignore(1);
    ss >> ey;
}

string part1() {
    grid = vector<vector<int>>(1000, vector<int>(1000, 0));

    string s;
    while (getline(inputFile, s)) {
        stringstream ss(s);
        size_t sx, sy, ex, ey;
        Command c = getCommand(ss);
        getCordinates(ss, sx, sy, ex, ey);

        for (size_t i = sx; i <= ex; i++) {
            for (size_t j = sy; j <= ey; j++) {
                if (c == Command::toggle)
                    grid[i][j] = !grid[i][j];
                else if (c == Command::turn_on)
                    grid[i][j] = true;
                else if (c == Command::turn_off)
                    grid[i][j] = false;
            }
        }
    }

    int n = 0;
    for (size_t i = 0; i <= 999; i++)
        for (size_t j = 0; j <= 999; j++)
            if (grid[i][j]) n++;
    return to_string(n);
}
string part2() {
    grid = vector<vector<int>>(1000, vector<int>(1000, 0));

    string s;
    while (getline(inputFile, s)) {
        stringstream ss(s);
        size_t sx, sy, ex, ey;
        Command c = getCommand(ss);
        getCordinates(ss, sx, sy, ex, ey);

        for (size_t i = sx; i <= ex; i++) {
            for (size_t j = sy; j <= ey; j++) {
                if (c == Command::toggle)
                    grid[i][j] += 2;
                else if (c == Command::turn_on)
                    grid[i][j] += 1;
                else if (c == Command::turn_off && grid[i][j] >= 1)
                    grid[i][j] -= 1;
            }
        }
    }

    int n = 0;
    for (size_t i = 0; i <= 999; i++)
        for (size_t j = 0; j <= 999; j++) n += grid[i][j];
    return to_string(n);
}

int main() {
    cout << "2015/06:" << endl;

    inputFile.open("2015/06/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2015/06/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}
