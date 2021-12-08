#include <iostream>
#include <vector>

using namespace std;

struct tile
{
    bool drawn;
    int value;
};
struct board
{
    vector<vector<tile>> tiles;
    bool won;
};
vector<board> boards(100);
board last;
int lastNUM;
vector<int> numbers(100);

void draw(int num)
{
    for (auto &&board : boards)
        if (!board.won)
            for (auto &&row : board.tiles)
                for (auto &&e : row)
                    if (e.value == num)
                        e.drawn = true;
}
void check(int num)
{
    for (int i = 0; i < 100; i++)
    {
        if (boards[i].won)
            continue;
        vector<vector<tile>> board = boards[i].tiles;
        for (int x = 0; x < 5; x++)
        {
            if (board[x][0].drawn && board[x][1].drawn && board[x][2].drawn && board[x][3].drawn && board[x][4].drawn)
            {
                boards[i].won = true;
                last = boards[i];
                lastNUM = num;
            }
            else if (board[0][x].drawn && board[1][x].drawn && board[2][x].drawn && board[3][x].drawn && board[4][x].drawn)
            {
                boards[i].won = true;
                last = boards[i];
                lastNUM = num;
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 100; i++)
        cin >> numbers[i];

    for (int i = 0; i < 100; i++)
    {
        board a;
        a.tiles.resize(5, vector<tile>(5));
        for (int x = 0; x < 5; x++)
            for (int y = 0; y < 5; y++)
            {
                tile b;
                cin >> b.value;
                b.drawn = false;
                a.tiles[x][y] = b;
            }
        a.won = false;
        boards[i] = a;
    }
    for (int i = 0; i < 100; i++)
    {
        draw(numbers[i]);
        check(numbers[i]);
    }
    int sum = 0;
    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 5; y++)
            if (!last.tiles[x][y].drawn)
                sum += last.tiles[x][y].value;
    cout << sum * lastNUM << "\n";
    // cout << "no winnig board was found\n";
}
