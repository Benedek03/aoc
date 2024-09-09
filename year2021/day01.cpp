#include "../common/puzzle.hpp"

class Solution : public Puzzle {
   public:
    Solution(std::string inputFileName = "inputs/2021/1.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        int last, curr, result = 0;
        inputFile >> last;
        while (inputFile >> curr) {
            if (curr > last) result++;
            last = curr;
        }
        return std::to_string(result);
    }
    std::string part2() {
        int a, b, c, last, curr, result = 0;
        inputFile >> a;
        inputFile >> b;
        inputFile >> c;
        last = a + b + c;
        a = b;
        b = c;
        while (inputFile >> c) {
            curr = a + b + c;
            if (curr > last) result++;
            last = curr;
            a = b;
            b = c;
        }
        return std::to_string(result);
    }
};

int main() {
    Solution s = Solution();
    s.solve();
}
