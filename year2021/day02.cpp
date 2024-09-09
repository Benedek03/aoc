#include "../common/puzzle.hpp"

class Solution : public Puzzle {
   public:
    Solution(std::string inputFileName = "inputs/2021/2.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        int x = 0, y = 0, X;
        std::string instruction;

        while (inputFile >> instruction >> X) {
            if (instruction == "forward")
                x += X;
            else if (instruction == "down")
                y += X;
            else
                y -= X;
        }
        return std::to_string(y * x);
    }
    std::string part2() {
        int x = 0, y = 0, aim = 0, X;
        std::string instruction;

        while (inputFile >> instruction >> X) {
            if (instruction == "down")
                aim += X;
            else if (instruction == "up")
                aim -= X;
            else {
                x += X;
                y += X * aim;
            }
        }
        return std::to_string(y * x);
    }
};

int main() {
    Solution s = Solution();
    s.solve();
}
