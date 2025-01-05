#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

ifstream inputFile;

struct Tile {
    bool marked;
    int value;
    Tile() {
        marked = false;
        value = 0;
    }
};

struct Board {
    bool won;  // part2
    Tile tiles[5][5];
    Board() { won = false; }
    int unmarkedSum() {
        int sum = 0;
        for (int x = 0; x < 5; x++)
            for (int y = 0; y < 5; y++)
                if (!tiles[x][y].marked) sum += tiles[x][y].value;
        return sum;
    }
    void mark(int n) {
        for (size_t i = 0; i < 5; i++)
            for (size_t j = 0; j < 5; j++)
                if (tiles[i][j].value == n) tiles[i][j].marked = true;
    }
    bool checkForNewWin() {
        if (won) return false;
        for (int x = 0; x < 5; x++) {
            if (tiles[x][0].marked && tiles[x][1].marked &&
                tiles[x][2].marked && tiles[x][3].marked &&
                tiles[x][4].marked) {
                won = true;
                return true;
            } else if (tiles[0][x].marked && tiles[1][x].marked &&
                        tiles[2][x].marked && tiles[3][x].marked &&
                        tiles[4][x].marked) {
                won = true;
                return true;
            }
        }
        return false;
    }
};

int numbers[100];
Board boards[100];

void read() {
    for (size_t i = 0; i < 100; i++) {
        inputFile >> numbers[i];
        inputFile.ignore(1);
    }

    for (size_t i = 0; i < 100; i++)
        for (size_t x = 0; x < 5; x++)
            for (size_t y = 0; y < 5; y++) {
                inputFile >> boards[i].tiles[x][y].value;
            }
}

string part1() {
    read();
    for (int &n : numbers) {
        for (size_t j = 0; j < 100; j++) {
            boards[j].mark(n);
            if (boards[j].checkForNewWin())
                return to_string(boards[j].unmarkedSum() * n);
        }
    }
    return to_string(-1);
}
string part2() {
    read();
    Board last;
    int lastN;
    for (int &n : numbers) {
        for (size_t j = 0; j < 100; j++) {
            boards[j].mark(n);
            if (boards[j].checkForNewWin()) {
                last = boards[j];
                lastN = n;
            }
        }
    }

    return to_string(last.unmarkedSum() * lastN);
}

int main() {
    cout << "2021/04:" << endl;

    inputFile.open("2021/04/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part1: " << part1() << endl;
    inputFile.close();

    inputFile.open("2021/04/input.txt");
    if (!inputFile.is_open()) {
        cout << "file is not open!" << endl;
        return 1;
    }
    cout << "part2: " << part2() << endl;
    inputFile.close();
}
