#include <vector>

#include "../common/puzzle.hpp"

using namespace std;

class Solution : public Puzzle {
   public:
    Solution(std::string inputFileName = "inputs/2021/6.txt")
        : Puzzle(inputFileName) {}
    std::string part1() {
        int arr[9] = {0};
        for (int i = 0; i < 300; i++) {
            int a;
            inputFile >> a;
            inputFile.ignore(1);
            arr[a]++;
        }
        for (int i = 0; i < 80; i++) {
            int tmp = arr[0];
            for (int j = 0; j < 8; j++) arr[j] = arr[j + 1];
            arr[6] += tmp;
            arr[8] = tmp;
        }
        int sum = 0;
        for (int i = 0; i < 9; i++) sum += arr[i];
        cout << sum << "\n";
        return "TODO";
    }
    std::string part2() {
        long int arr[9] = {0};
        for (int i = 0; i < 300; i++) {
            int a;
            inputFile >> a;
            inputFile.ignore(1);
            arr[a]++;
        }
        for (int i = 0; i < 256; i++) {
            long int tmp = arr[0];
            for (int j = 0; j < 8; j++) arr[j] = arr[j + 1];
            arr[6] += tmp;
            arr[8] = tmp;
        }
        long int sum = 0;
        for (int i = 0; i < 9; i++) sum += arr[i];
        cout << sum << "\n";
        return "TODO";
    }
};

int main() {
    Solution s = Solution();
    s.solve();
}
