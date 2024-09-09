#include "../common/puzzle.hpp"

class Solution : public Puzzle {
   public:
    Solution(std::string inputFileName = "inputs/2023/1.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        int sum = 0;
        std::string line;
        while (std::getline(inputFile, line)) {
            sum += (line[line.find_first_of("0123456789")] - '0') * 10 +
                   (line[line.find_last_of("0123456789")] - '0');
        }
        return std::to_string(sum);
    }
    std::string part2() {
        const char* cc[9] = {"one", "two",   "three", "four", "five",
                             "six", "seven", "eight", "nine"};

        int sum = 0;
        std::string line;
        while (std::getline(inputFile, line)) {
            size_t first = line.find_first_of("0123456789");
            size_t last = line.find_last_of("0123456789");

            for (size_t i = 0; i < line.length(); i++) {
                for (size_t j = 0; j < 9; j++) {
                    if (line.substr(i, line.length() - i).find(cc[j]) == 0) {
                        if (i < first) {
                            line[i] = j + 1 + '0';
                            first = i;
                        } else if (i > last) {
                            line[i] = j + 1 + '0';
                            last = i;
                        }
                    }
                }
            }

            sum += (line[first] - '0') * 10 + (line[last] - '0');
        }
        return std::to_string(sum);
    }
};

int main() {
    Solution s = Solution();
    s.solve();
}
