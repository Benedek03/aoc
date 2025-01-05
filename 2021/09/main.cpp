#include <algorithm>
#include <stack>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

ifstream inputFile;

string part1() {
    vector<vector<int>> heightmap(100, vector<int>(100));
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++) {
            char a;
            inputFile >> a;
            a = a -'0';
            heightmap[i][j] = a;
        }

    int res = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            bool lowpoint = true;
            if (i > 0 && heightmap[i - 1][j] <= heightmap[i][j])
                lowpoint = false;
            if (i < 99 && heightmap[i + 1][j] <= heightmap[i][j])
                lowpoint = false;
            if (j > 0 && heightmap[i][j - 1] <= heightmap[i][j])
                lowpoint = false;
            if (j < 99 && heightmap[i][j + 1] <= heightmap[i][j])
                lowpoint = false;
            if (lowpoint) res += 1 + heightmap[i][j];
        }
    }
    return to_string(res);
}
string part2() {
    vector<vector<int>> map(100, vector<int>(100, 0));
    vector<int> res(3, 0);
    stack<pair<int, int>> s;
    int curr;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++) {
            char a;
            inputFile >> a;
            a = a -'0';
            if (a == 9) map[i][j] = -1;
        }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j] == 1) continue;
            curr = 0;
            s.push({i, j});
            map[i][j] = 1;
            while (!s.empty()) {
                int x = s.top().first, y = s.top().second;
                s.pop();
                if (i > 0 && map[x - 1][y] == 0) {
                    map[x - 1][y] = 1;
                    s.push({x - 1, y});
                    curr++;
                }
                if (x < 99 && map[x + 1][y] == 0) {
                    map[x + 1][y] = 1;
                    s.push({x + 1, y});
                    curr++;
                }
                if (y > 0 && map[x][y - 1] == 0) {
                    map[x][y - 1] = 1;
                    s.push({x, y - 1});
                    curr++;
                }
                if (y < 99 && map[x][y + 1] == 0) {
                    map[x][y + 1] = 1;
                    s.push({x, y + 1});
                    curr++;
                }
            }
            sort(res.begin(), res.end());
            if (res[0] < curr) res[0] = curr;
        }
    }
    return to_string(res[0] * res[1] * res[2]);
}

int main() {
    cout << "2021/09:" << endl;

    inputFile.open("2021/09/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2021/09/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}
