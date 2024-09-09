#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int part1(ifstream &f) { 
    vector<char> q;
    char c;
    q.push_back(' ');
    for (size_t i = 0; i < 3; i++) {
        f >> c;
        q.push_back(c);
    }
    int i = 3;
    while (f >> c) {
        i++;
        q.erase(q.begin());
        q.push_back(c);

        bool found = false;
        for (size_t i = 0; i < q.size(); i++)
            for (size_t j = 0; j < q.size(); j++)
                if (!found && i != j && q[i] == q[j]) {
                    found = true;
                }

        if (!found) break;
    }
    return i;
}

int part2(ifstream &f) { 
    vector<char> q;
    char c;
    q.push_back(' ');
    for (size_t i = 0; i < 13; i++) {
        f >> c;
        q.push_back(c);
    }
    int i = 13;
    while (f >> c) {
        i++;
        q.erase(q.begin());
        q.push_back(c);

        bool found = false;
        for (size_t i = 0; i < q.size(); i++)
            for (size_t j = 0; j < q.size(); j++)
                if (!found && i != j && q[i] == q[j]) {
                    found = true;
                }

        if (!found) break;
    }
    return i;
}

int main() {
    ifstream f;
    f.open("inputs/2022/6.txt");
    cout << "part1: " << part1(f) << endl;
    f.close();
    f.open("inputs/2022/6.txt");
    cout << "part2: " << part2(f) << endl;
    f.close();
}
