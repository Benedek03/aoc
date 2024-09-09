#include "../common/puzzle.hpp"

using namespace std;

class Solution : public Puzzle {
    int X = 1, cycles = 0;
    string output = "";

    void cycle() {
        if (cycles % 40 == X - 1 || cycles % 40 == X || cycles % 40 == X + 1)
            output += "#";
        else
            output += ".";
        cycles++;
        if (cycles % 40 == 0) {
            output += "\n";
        }
    }

   public:
    Solution(std::string inputFileName = "inputs/2022/10.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        string instuction;
        int V, X = 1, cycles = 0, sum = 0;
        while (inputFile >> instuction) {
            if (instuction == "addx") {
                cycles++;
                if (cycles == 20 || (cycles - 20) % 40 == 0) {
                    sum += cycles * X;
                }
                cycles++;
                if (cycles == 20 || (cycles - 20) % 40 == 0) {
                    sum += cycles * X;
                }
                inputFile >> V;
                X += V;

            } else {
                cycles++;
                if (cycles == 20 || (cycles - 20) % 40 == 0) {
                    sum += cycles * X;
                }
            }
        }
        return to_string(sum);
    }
    std::string part2() {
        string instuction;
        int V;
        while (inputFile >> instuction) {
            if (instuction == "addx") {
                cycle();
                cycle();
                inputFile >> V;
                X += V;

            } else {
                cycle();
            }
        }
        return '\n' + output;
    }
};

int main() {
    Solution s = Solution();
    s.solve();
}
