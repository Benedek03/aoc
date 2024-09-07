#include "../common/puzzle.hpp"

class Solution : public Puzzle {
   public:
    Solution(std::string inputFileName = "inputs/2015/1.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        int floor = 0;
        char ch;
        while (inputFile >> ch) {
            if (ch == '(')
                floor++;
            else if (ch == ')')
                floor--;
        }
        return std::to_string(floor);
    }
    std::string part2() {
        int floor = 0, position = 0;
        char ch;
        while (inputFile >> ch) {
            position++;
            if (ch == '(')
                floor++;
            else if (ch == ')')
                floor--;
            if (floor == -1) return std::to_string(position);
        }
        return std::to_string(-1);
    }
};

int main() {
    Solution s = Solution();
    s.solve();
}
