#include <fstream>
#include <iostream>

using namespace std;

int part1(ifstream &f) { 
    int ff, fs, sf, ss, result = 0;
    char c;
    while (f >> ff >> c >> fs >> c >> sf >> c >> ss)
        if ((ff <= sf && fs >= ss) || (sf <= ff && ss >= fs))
            result++;
    return result;
}

int part2(ifstream &f) { 
    int ff, fs, sf, ss, result = 0;
    char c;
    while (f >> ff >> c >> fs >> c >> sf >> c >> ss)
        if ((sf >= ff && sf <= fs) ||
            (ss >= ff && ss <= fs) ||
            (ff >= sf && ff <= ss) ||
            (fs >= sf && fs <= ss))
            result++;
    return result;
}

int main() {
    ifstream f;
    f.open("inputs/2022/4.txt");
    cout << "part1: " << part1(f) << endl;
    f.close();
    f.open("inputs/2022/4.txt");
    cout << "part2: " << part2(f) << endl;
    f.close();
}
