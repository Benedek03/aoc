#include <fstream>
#include <iostream>

using namespace std;

int part1(ifstream &f) { 
    int total = 0;
    string s;
    while (getline(f, s)) {
        char a = s[0] - 64;
        char b = s[2] - 87;
        total += b;
        
        // 0  -> draw
        // -1 -> W
        // -2 -> L
        // 2  -> W
        // 1  -> L
        switch (a - b) {
            case 0:
                total += 3;
                break;
            case -1:
                total += 6;
                break;
            case 2:
                total += 6;
                break;
            case 1:
                break;
            case -2:
                break;
        }
    }
    return total;
}

int part2(ifstream &f) { 
    int total = 0;
    string s;
    while (getline(f, s)) {
        char a = s[0] - 64;
        char b = s[2] - 87;
        total += (b - 1) * 3;

        switch (b) {
            case 1:
                total += a - 1;
                if (a == 1) total += 3;
                break;
            case 2:
                total += a;
                break;
            case 3:
                total += a + 1;
                if (a == 3) total -= 3;
                break;
        }
    }
    return total;
}

int main() {
    ifstream f;
    f.open("inputs/2022/2.txt");
    cout << "part1: " << part1(f) << endl;
    f.close();
    f.open("inputs/2022/2.txt");
    cout << "part2: " << part2(f) << endl;
    f.close();
}
