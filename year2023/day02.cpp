#include <sstream>

#include "../common/puzzle.hpp"

class Solution : public Puzzle {
    size_t stringToColorIndex(const std::string& s) {
        if (s.substr(0, 3) == "red") return 0;
        if (s.substr(0, 5) == "green") return 1;
        if (s.substr(0, 4) == "blue") return 2;
        return -1;
    }

   public:
    Solution(std::string inputFileName = "inputs/2023/2.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        int cubes[] = {12, 13, 14};
        int res = 0;
        std::string line;
        while (std::getline(inputFile, line)) {
            int gameId;
            bool impossible = false;

            std::stringstream ss(line);

            ss.ignore(5);
            ss >> gameId;
            ss.ignore(2);

            int n;
            std::string col;
            while (ss >> n >> col && !impossible) {
                if (cubes[stringToColorIndex(col)] < n) impossible = true;
            }
            if (!impossible) res += gameId;
        }
        return std::to_string(res);
    }
    std::string part2() {
        int gameId, res = 0;
        std::string line;
        while (std::getline(inputFile, line)) {
            std::stringstream ss(line);
            ss.ignore(5);
            ss >> gameId;
            ss.ignore(2);

            int n;
            std::string col;
            int max[] = {0, 0, 0};
            while (ss >> n >> col) {
                size_t i = stringToColorIndex(col);
                if (max[i] < n) max[i] = n;
            }
            res += max[0] * max[1] * max[2];
        }
        return std::to_string(res);
    }
};

int main() {
    Solution s = Solution();
    s.solve();
}
