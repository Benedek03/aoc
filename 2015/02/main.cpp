#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

ifstream inputFile;

class Box {
    int width, height, length;

    public:
    Box(stringstream line) {
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
        int slack = min(side1, min(side2, side3));
        return surfaceArea + slack;
    }
    int requiredRibbon() {
        int bow = width * height * length;
        int perim1 = 2 * (width + height);
        int perim2 = 2 * (width + length);
        int perim3 = 2 * (height + length);
        return bow + min(perim1, min(perim2, perim3));
    }
};

string part1() {
    int sum = 0;
    string line;
    while (getline(inputFile, line)) {
        Box b = Box(stringstream(line));
        sum += b.requiredWrappingPaper();
    }
    return to_string(sum);
}
string part2() {
    int sum = 0;
    string line;
    while (getline(inputFile, line)) {
        Box b = Box(stringstream(line));
        sum += b.requiredRibbon();
    }
    return to_string(sum);
}

int main() {
    cout << "2015/02:" << endl;

    inputFile.open("2015/02/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2015/02/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}
