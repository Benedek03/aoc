#include <iostream>
#include <vector>

using namespace std;

struct tile
{
    bool drawn;
    int value;
};
vector<vector<vector<tile>>> boards(100, vector<vector<tile>>(5, vector<tile>(5)));
vector<int> numbers(100);

void draw(int num)
{
    for (auto &&board : boards)
        for (auto &&row : board)
            for (auto &&e : row)
                if (e.value == num)
                    e.drawn = true;
}
int check()
{
    for (int x = 0; x < boards.size(); x++)
    {
        vector<vector<tile>> board = boards[x];
        for (int i = 0; i < 5; i++)
        {
            if (board[i][0].drawn && board[i][1].drawn && board[i][2].drawn && board[i][3].drawn && board[i][4].drawn)
                return x;
            if (board[0][i].drawn && board[1][i].drawn && board[2][i].drawn && board[3][i].drawn && board[4][i].drawn)
                return x;
        }
    }
    return -1;
}
int main()
{
    for (int i = 0; i < 100; i++)
        cin >> numbers[i];

    for (int i = 0; i < 100; i++)
        for (int x = 0; x < 5; x++)
            for (int y = 0; y < 5; y++)
            {
                tile a;
                a.drawn = false;
                cin >> a.value;
                boards[i][x][y] = a;
            }
    for (int i = 0; i < 100; i++)
    {
        draw(numbers[i]);
        int winningboard = check();
        if (winningboard > -1)
        {
            int sum = 0;
            for (int x = 0; x < 5; x++)
                for (int y = 0; y < 5; y++)
                    if (!boards[winningboard][x][y].drawn)
                        sum += boards[winningboard][x][y].value;
            cout << sum * numbers[i] << "\n";
            return 0;
        }
    }
    cout << "no winnig board was found\n";
}
