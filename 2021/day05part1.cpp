#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x1, x2, y1, y2;
    vector<vector<int>> diagram(1000, vector<int>(1000));
    for (int i = 0; i < 500; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        if (!(x1 == x2 || y1 == y2))
            continue;
        if (y1 == y2)
        {
            if (x1 > x2)
            {
                int tmp = x1;
                x1 = x2;
                x2 = tmp;
            }
            for (int j = x1; j <= x2; j++)
                diagram[j][y1]++;
        }
        if (x1 == x2)
        {
            if (y1 > y2)
            {
                int tmp = y1;
                y1 = y2;
                y2 = tmp;
            }
            for (int j = y1; j <= y2; j++)
                diagram[x1][j]++;
        }
    }
    int count = 0;
    for (auto &&row : diagram)
        for (auto &&i : row)
            if (i > 1)
                count++;
    cout << count << "\n";
}