#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

int part1(ifstream &f) {
    string s;
    int c = 0, m = 0;
    while (getline(f, s)) {
        if (s == "")
            c = 0;
        else {
            c += stoi(s);
            if (c > m)
                m = c;
        }
    }
    return m;
}

int part2(ifstream &f) {
    string s;
    priority_queue<int> q;
    int c = 0, r = 0;
    while (getline(f, s)) {
        if (s == "") {
            q.push(c);
            c = 0;
        } else
            c += stoi(s);
    }
    for (size_t i = 0; i < 3; i++) {
        r += q.top();
        q.pop();
    }

    return r;
}

int main() {
    ifstream f;
    f.open("inputs/2022/1.txt");
    cout << "part1: " << part1(f) << endl;
    f.close();
    f.open("inputs/2022/1.txt");
    cout << "part2: " << part2(f) << endl;
    f.close();
}
