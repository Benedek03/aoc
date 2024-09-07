#ifndef PUZZLE_HPP
#define PUZZLE_HPP

#include <fstream>
#include <iostream>

class Puzzle {
   protected:
    std::ifstream inputFile;
    void resetFile() {
        inputFile.clear();
        inputFile.seekg(0);
    }
    virtual std::string part1() = 0;
    virtual std::string part2() = 0;

   public:
    Puzzle(std::string inputFileName = "") {
        inputFile.open(inputFileName);
        if (!inputFile.is_open()) throw "Can't open file";
    }
    void solve(std::ostream& os = std::cout) {
        resetFile();
        os << "part1: " << part1() << std::endl;
        resetFile();
        os << "part2: " << part2() << std::endl;
    }
    virtual ~Puzzle() { inputFile.close(); }
};

#endif
