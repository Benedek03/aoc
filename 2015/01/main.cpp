#include <fstream>
#include <iostream>

std::ifstream inputFile;

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

int main() {
    std::cout << "2015/01:" << std::endl;

    inputFile.open("2015/01/input.txt");
    if (!inputFile.is_open()) {
        std::cout << "file is not open!" << std::endl;
        return 1;
    }
    std::cout << "part1: " << part1() << std::endl;
    inputFile.close();

    inputFile.open("2015/01/input.txt");
    if (!inputFile.is_open()) {
        std::cout << "file is not open!" << std::endl;
        return 1;
    }
    std::cout << "part2: " << part2() << std::endl;
    inputFile.close();
}


