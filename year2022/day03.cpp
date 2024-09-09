#include <fstream>
#include <iostream>

using namespace std;

int part1(ifstream &f) { 
    string s;
    int r = 0;
    while (getline(f, s)) {
        int l = s.length() / 2;
        string s1 = s.substr(0, l);
        string s2 = s.substr(l, l);
        for (auto &&c : s1) {
            if (s2.find(c) != std::string::npos) {
                if (c <= 97)
                    r += c - 38;
                else
                    r += c - 96;
                break;
            }
        }
    }
    return r;
}

int part2(ifstream &f) { 
    string s1, s2, s3;
    int r = 0;
    while (getline(f, s1) && getline(f, s2) && getline(f, s3)) {
        for (auto &&c : s1) {
            if (s2.find(c) != std::string::npos &&
                s3.find(c) != std::string::npos) {
                if (c <= 97)
                    r += c - 38;
                else
                    r += c - 96;
                break;
            }
        }
    }
    return r;
}

int main() {
    ifstream f;
    f.open("inputs/2022/3.txt");
    cout << "part1: " << part1(f) << endl;
    f.close();
    f.open("inputs/2022/3.txt");
    cout << "part2: " << part2(f) << endl;
    f.close();
}
