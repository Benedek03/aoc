#include <queue>
#include <vector>

#include "../common/puzzle.hpp"

using namespace std;

class Solution : public Puzzle {
    struct pos {
        int x, y;
    };

   public:
    Solution(std::string inputFileName = "inputs/2022/12.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        vector<vector<char>> hm;
        pos s, e;

        string line;
        for (int x = 0; inputFile >> line; x++) {
            vector<char> vc;
            for (size_t y = 0; y < line.length(); y++) {
                switch (line[y]) {
                    case 'S':
                        s = {x, (int)y};
                        vc.push_back('a');
                        break;
                    case 'E':
                        e = {x, (int)y};
                        vc.push_back('z');
                        break;
                    default:
                        vc.push_back(line[y]);
                        break;
                }
            }
            hm.push_back(vc);
        }

        int h = hm.size(), w = hm[0].size();
        vector<pos> dirs = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
        vector<vector<int>> r(h, vector<int>(w, -1));
        r[s.x][s.y] = 0;
        queue<pos> q;
        q.push(s);

        while (!q.empty()) {
            pos c = q.front();
            q.pop();

            for (auto &&d : dirs) {
                pos a = {c.x + d.x, c.y + d.y};
                if (a.x >= 0 && a.y >= 0 && a.x < h && a.y < w &&
                    r[a.x][a.y] == -1 && hm[a.x][a.y] <= hm[c.x][c.y] + 1) {
                    q.push(a);
                    r[a.x][a.y] = r[c.x][c.y] + 1;
                }
            }
        }
        return to_string(r[e.x][e.y]);
    }
    std::string part2() {
        vector<vector<char>> hm;
        pos s, e;

        string line;
        for (int x = 0; inputFile >> line; x++) {
            vector<char> vc;
            for (size_t y = 0; y < line.length(); y++) {
                switch (line[y]) {
                    case 'S':
                        s = {x, (int)y};
                        vc.push_back('a');
                        break;
                    case 'E':
                        e = {x, (int)y};
                        vc.push_back('z');
                        break;
                    default:
                        vc.push_back(line[y]);
                        break;
                }
            }
            hm.push_back(vc);
        }

        int h = hm.size(), w = hm[0].size();
        vector<pos> dirs = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
        int min = 99999;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (hm[i][j] != 'a') break;

                vector<vector<int>> r(h, vector<int>(w, -1));
                queue<pos> q;
                r[i][j] = 0;
                q.push({i, j});
                while (!q.empty()) {
                    pos c = q.front();
                    q.pop();

                    for (auto &&d : dirs) {
                        pos a = {c.x + d.x, c.y + d.y};
                        if (a.x >= 0 && a.y >= 0 && a.x < h && a.y < w &&
                            r[a.x][a.y] == -1 &&
                            hm[a.x][a.y] <= hm[c.x][c.y] + 1) {
                            q.push(a);
                            r[a.x][a.y] = r[c.x][c.y] + 1;
                        }
                    }
                }
                if (min > r[e.x][e.y]) min = r[e.x][e.y];
            }
        }
        return to_string(min);
    }
};

int main() {
    Solution s = Solution();
    s.solve();
}
