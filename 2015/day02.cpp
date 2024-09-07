#include <sstream>

#include "../common/puzzle.hpp"

class Solution : public Puzzle {
    class Box {
        int width, height, length;

       public:
        Box(std::stringstream line) {
            line >> width;
            line.ignore(1);
            line >> height;
            line.ignore(1);
            line >> length;
        }
        int requiredWrappingPaper() {
            int side1 = width * height;
            int side2 = width * length;
            int side3 = height * length;
            int surfaceArea = 2 * (side1 + side2 + side3);
            int slack = std::min(side1, std::min(side2, side3));
            return surfaceArea + slack;
        }
        int requiredRibbon() {
            int bow = width * height * length;
            int perim1 = 2 * (width + height);
            int perim2 = 2 * (width + length);
            int perim3 = 2 * (height + length);
            return bow + std::min(perim1, std::min(perim2, perim3));
        }
    };

   public:
    Solution(std::string inputFileName = "inputs/2015/2.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        int sum = 0;
        std::string line;
        while (std::getline(inputFile, line)) {
            Box b = Box(std::stringstream(line));
            sum += b.requiredWrappingPaper();
        }
        return std::to_string(sum);
    }
    std::string part2() {
        int sum = 0;
        std::string line;
        while (std::getline(inputFile, line)) {
            Box b = Box(std::stringstream(line));
            sum += b.requiredRibbon();
        }
        return std::to_string(sum);
    }
};

int main() {
    Solution d = Solution();
    d.solve();
}
