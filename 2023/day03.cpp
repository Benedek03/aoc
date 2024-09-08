#include <vector>

#include "../common/puzzle.hpp"

class Solution : public Puzzle {
   public:
    Solution(std::string inputFileName = "inputs/2023/3.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        std::vector<std::string> v;
        std::string s;
        while (inputFile >> s) v.push_back(s);
        int sum = 0;
        for (size_t i = 0; i < v.size(); i++) {
            for (size_t j = 0; j < v[i].size(); j++) {
                if (isdigit(v[i][j])) {
                    bool b = false;
                    s = "";
                    s.push_back(v[i][j]);
                    if (i > 0 && v[i - 1][j] != '.' && !isdigit(v[i - 1][j]))
                        b = true;
                    if (!b && i > 0 && j > 0 && v[i - 1][j - 1] != '.' &&
                        !isdigit(v[i - 1][j - 1]))
                        b = true;
                    if (!b && j > 0 && v[i][j - 1] != '.' &&
                        !isdigit(v[i][j - 1]))
                        b = true;
                    if (!b && i < v.size() - 1 && j > 0 &&
                        v[i + 1][j - 1] != '.' && !isdigit(v[i + 1][j - 1]))
                        b = true;
                    if (!b && i < v.size() - 1 && v[i + 1][j] != '.' &&
                        !isdigit(v[i + 1][j]))
                        b = true;
                    while (j + 1 < v[i].size() && isdigit(v[i][++j])) {
                        s.push_back(v[i][j]);
                        if (!b && i > 0 && v[i - 1][j] != '.' &&
                            !isdigit(v[i - 1][j]))
                            b = true;
                        if (!b && i < v.size() - 1 && v[i + 1][j] != '.' &&
                            !isdigit(v[i + 1][j]))
                            b = true;
                    }
                    if (!b && i > 0 && v[i - 1][j] != '.' &&
                        !isdigit(v[i - 1][j]))
                        b = true;
                    if (!b && v[i][j] != '.' && !isdigit(v[i][j])) b = true;
                    if (!b && i < v.size() - 1 && v[i + 1][j] != '.' &&
                        !isdigit(v[i + 1][j]))
                        b = true;

                    if (b) sum += stoi(s);
                }
            }
        }
        return std::to_string(sum);
    }
    std::string part2() {
        std::vector<std::string> v;
        std::string s;
        while (inputFile >> s) v.push_back(s);
        long long int sum = 0;
        for (size_t i = 0; i < v.size(); i++) {
            for (size_t j = 0; j < v[i].size(); j++) {
                if (v[i][j] == '*') {
                    std::vector<std::string> v2;
                    if (i > 0 && isdigit(v[i - 1][j])) {
                        s = "";
                        size_t k = j;
                        s.push_back(v[i - 1][k]);
                        while (k > 0 && isdigit(v[i - 1][--k]))
                            s.insert(0, 1, v[i - 1][k]);
                        k = j;
                        while (k < v[i - 1].size() - 1 &&
                               isdigit(v[i - 1][++k]))
                            s.push_back(v[i - 1][k]);
                        v2.push_back(s);
                    } else {
                        if (i > 0 && j > 0 && isdigit(v[i - 1][j - 1])) {
                            s = "";
                            size_t k = j - 1;
                            s.push_back(v[i - 1][k]);
                            while (k > 0 && isdigit(v[i - 1][--k]))
                                s.insert(0, 1, v[i - 1][k]);
                            v2.push_back(s);
                        }
                        if (i > 0 && j < v[i].size() &&
                            isdigit(v[i - 1][j + 1])) {
                            s = "";
                            size_t k = j + 1;
                            s.push_back(v[i - 1][k]);
                            while (k < v[i - 1].size() - 1 &&
                                   isdigit(v[i - 1][++k]))
                                s.push_back(v[i - 1][k]);
                            v2.push_back(s);
                        }
                    }
                    if (j > 0 && isdigit(v[i][j - 1])) {
                        s = "";
                        size_t k = j - 1;
                        s.push_back(v[i][k]);
                        while (k > 0 && isdigit(v[i][--k]))
                            s.insert(0, 1, v[i][k]);
                        v2.push_back(s);
                    }
                    if (j < v[i].size() && isdigit(v[i][j + 1])) {
                        s = "";
                        size_t k = j + 1;
                        s.push_back(v[i][k]);
                        while (k < v[i].size() - 1 && isdigit(v[i][++k]))
                            s.push_back(v[i][k]);
                        v2.push_back(s);
                    }
                    if (i < v.size() - 1 && isdigit(v[i + 1][j])) {
                        s = "";
                        size_t k = j;
                        s.push_back(v[i + 1][k]);
                        while (k > 0 && isdigit(v[i + 1][--k]))
                            s.insert(0, 1, v[i + 1][k]);
                        k = j;
                        while (k < v[i + 1].size() - 1 &&
                               isdigit(v[i + 1][++k]))
                            s.push_back(v[i + 1][k]);
                        v2.push_back(s);
                    } else {
                        if (i < v.size() - 1 && j > 0 &&
                            isdigit(v[i + 1][j - 1])) {
                            s = "";
                            size_t k = j - 1;
                            s.push_back(v[i + 1][k]);
                            while (k > 0 && isdigit(v[i + 1][--k]))
                                s.insert(0, 1, v[i + 1][k]);
                            v2.push_back(s);
                        }
                        if (i < v.size() - 1 && j < v[i].size() &&
                            isdigit(v[i + 1][j + 1])) {
                            s = "";
                            size_t k = j + 1;
                            s.push_back(v[i + 1][k]);
                            while (k < v[i + 1].size() - 1 &&
                                   isdigit(v[i + 1][++k]))
                                s.push_back(v[i + 1][k]);
                            v2.push_back(s);
                        }
                    }
                    if (v2.size() == 2) sum += stoi(v2[0]) * stoi(v2[1]);
                }
            }
        }
        return std::to_string(sum);
    }
};

int main() {
    Solution s = Solution();
    s.solve();
}
