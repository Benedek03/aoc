#include "../common/puzzle.hpp"

class Solution : public Puzzle {
   public:
    Solution(std::string inputFileName = "inputs//.txt")
        : Puzzle(inputFileName) {}
    std::string part1() { return "TODO"; }
    std::string part2() { return "TODO"; }
};

int main() {
    Solution s = Solution();
    s.solve();
}
