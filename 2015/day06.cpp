#include <sstream>

#include "../common/puzzle.hpp"

class Solution : public Puzzle {
    enum class Command { turn_on, turn_off, toggle };
    Command getCommand(std::stringstream& ss) {
        std::string s;
        ss >> s;
        if (s == "toggle") return Command::toggle;
        ss >> s;
        if (s == "on")
            return Command::turn_on;
        else
            return Command::turn_off;
    }
    void getCordinates(std::stringstream& ss, size_t& sx, size_t& sy,
                       size_t& ex, size_t& ey) {
        ss >> sx;
        ss.ignore(1);
        ss >> sy;
        ss.ignore(9);
        ss >> ex;
        ss.ignore(1);
        ss >> ey;
    }

   public:
    Solution(std::string inputFileName = "inputs/2015/6.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        bool grid[1000][1000]{false};

        std::string s;
        while (std::getline(inputFile, s)) {
            std::stringstream ss(s);
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
        return std::to_string(n);
    }
    std::string part2() {
        int grid[1000][1000]{false};

        std::string s;
        while (std::getline(inputFile, s)) {
            std::stringstream ss(s);
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
        return std::to_string(n);
    }
};

int main() {
    Solution d = Solution();
    d.solve();
}

