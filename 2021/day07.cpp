#include <algorithm>
#include <vector>

#include "../common/puzzle.hpp"

using namespace std;

class Solution : public Puzzle {
   public:
    Solution(std::string inputFileName = "inputs/2021/7.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        vector<int> crabs(1000);
        for (int i = 0; i < 1000; i++) {
            inputFile >> crabs[i];
            inputFile.ignore(1);
        }

        sort(crabs.begin(), crabs.end());

        int least = 1410065407;
        for (int i = 0; i < crabs[999]; i++) {
            int curr = 0;
            for (auto &&crab : crabs) {
                int a = abs(crab - i);
                curr += a;
            }
            if (curr < least) least = curr;
        }
        return std::to_string(least);
    }
    std::string part2() {
        vector<int> crabs(1000);
        for (int i = 0; i < 1000; i++) {
            inputFile >> crabs[i];
            inputFile.ignore(1);
        }
        sort(crabs.begin(), crabs.end());

        int least = 1410065407;
        for (int i = 0; i < crabs[999]; i++) {
            int curr = 0;
            for (auto &&crab : crabs) {
                int a = abs(crab - i);
                curr += a * (a + 1) / 2;
                ;
            }
            if (curr < least) least = curr;
        }
        return std::to_string(least);
    }
};

int main() {
    Solution s = Solution();
    s.solve();
}
