#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

ifstream inputFile;

string part1() {
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
    return to_string(sum);
}
string part2() {
    long long arr[9] = {0};
    for (int i = 0; i < 300; i++) {
        int a;
        inputFile >> a;
        inputFile.ignore(1);
        arr[a]++;
    }
    for (int i = 0; i < 256; i++) {
        long long tmp = arr[0];
        for (int j = 0; j < 8; j++) arr[j] = arr[j + 1];
        arr[6] += tmp;
        arr[8] = tmp;
    }
    long long sum = 0;
    for (int i = 0; i < 9; i++) sum += arr[i];
    return to_string(sum);
}

int main() {
    cout << "2021/06:" << endl;

    inputFile.open("2021/06/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2021/06/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}