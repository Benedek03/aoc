#include <algorithm>
#include <sstream>
#include <stack>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

ifstream inputFile;

vector<long long> v;

string part1() {
    int result1 = 0;
    for (int i = 0; i < 106; i++) {
        char c;

        string line;
        getline(inputFile, line);
        stringstream ss(line);

        stack<char> s;
        while (ss >> c) {
            if (c == '(')
                s.push(c);
            else if (c == '[')
                s.push(c);
            else if (c == '{')
                s.push(c);
            else if (c == '<')
                s.push(c);

            else if (c == ')') {
                if (s.top() == '(')
                    s.pop();
                else {
                    result1 += 3;
                    break;
                }
            } else if (c == ']') {
                if (s.top() == '[')
                    s.pop();
                else {
                    result1 += 57;
                    break;
                }
            } else if (c == '}') {
                if (s.top() == '{')
                    s.pop();
                else {
                    result1 += 1197;
                    break;
                }
            } else if (c == '>') {
                if (s.top() == '<')
                    s.pop();
                else {
                    result1 += 25137;
                    break;
                }
            }
        }

        if (!ss.eof())
            while (ss >> c);
        else if (s.size() > 0) {
            long long curr = 0;
            while (!s.empty()) {
                curr *= 5;
                if (s.top() == '(') {
                    s.pop();
                    curr += 1;
                } else if (s.top() == '[') {
                    s.pop();
                    curr += 2;
                } else if (s.top() == '{') {
                    s.pop();
                    curr += 3;
                } else if (s.top() == '<') {
                    s.pop();
                    curr += 4;
                }
            }
            v.push_back(curr);
        }
    }
    return to_string(result1);
}
string part2() {
    sort(v.begin(), v.end());
    return to_string(v[v.size() / 2]);
}

int main() {
    cout << "2021/10:" << endl;

    inputFile.open("2021/10/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2021/10/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}
