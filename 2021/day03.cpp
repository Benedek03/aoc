#include <cmath>
#include <vector>

#include "../common/puzzle.hpp"

class Solution : public Puzzle {
   public:
    Solution(std::string inputFileName = "inputs/2021/3.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        int common[12] = {0};
        std::string in;

        while (inputFile >> in) {
            for (int j = 0; j < 12; j++) {
                if (in[j] == '1')
                    common[j]++;
                else
                    common[j]--;
            }
        }

        int gamma = 0, epsilon = 0;
        for (int j = 0; j < 12; j++) {
            if (common[j] > 0)
                gamma += std::pow(2, 11 - j);
            else
                epsilon += std::pow(2, 11 - j);
        }

        return std::to_string(gamma * epsilon);
    }
    std::string part2() {
        std::vector<std::string> input;
        std::string s;
        while (inputFile >> s) input.push_back(s);

        std::vector<std::string> oxVector(input);
        std::vector<std::string> ocVector(input);
        for (int i = 0; i < 12; i++) {
            if (oxVector.size() != 1) {
                int common = 0;
                long unsigned int j = 0;
                for (long unsigned int j = 0; j < oxVector.size(); j++) {
                    if (oxVector[j][i] == '1')
                        common++;
                    else
                        common--;
                }
                char good = common >= 0 ? '1' : '0';
                while (j != oxVector.size()) {
                    if (oxVector[j][i] != good)
                        oxVector.erase(oxVector.begin() + j);
                    else
                        j++;
                }
            }
            if (ocVector.size() != 1) {
                int common = 0;
                long unsigned int j = 0;
                for (long unsigned int j = 0; j < ocVector.size(); j++) {
                    if (ocVector[j][i] == '1')
                        common++;
                    else
                        common--;
                }
                char good = common < 0 ? '1' : '0';
                while (j != ocVector.size()) {
                    if (ocVector[j][i] != good)
                        ocVector.erase(ocVector.begin() + j);
                    else
                        j++;
                }
            }
        }

        int ox = 0, oc = 0;
        for (int j = 0; j < 12; j++) {
            if (oxVector[0][j] == '1') ox += pow(2, 11 - j);
            if (ocVector[0][j] == '1') oc += pow(2, 11 - j);
        }
        return std::to_string(ox * oc);
    }
};

int main() {
    Solution s = Solution();
    s.solve();
}
