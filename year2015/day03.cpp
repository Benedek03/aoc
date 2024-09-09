#include <set>
#include <utility>

#include "../common/puzzle.hpp"

class Solution : public Puzzle {
   public:
    Solution(std::string inputFileName = "inputs/2015/3.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        std::set<std::pair<int, int>> s;
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
        return std::to_string(s.size());
    }
    std::string part2() {
        std::set<std::pair<int, int>> s;
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
        return std::to_string(s.size());
    }
};

int main() {
    Solution d = Solution();
    d.solve();
}
