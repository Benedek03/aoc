#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    vector<vector<int>> map(100, vector<int>(100, 0));
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
        {
            int a;
            cin >> a;
            if (a == 9)
                map[i][j] = -1;
        }

    vector<int> res(3, 0);
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (map[i][j] == 1)
                continue;
            map[i][j] = 1;
            int curr = 0;
            stack<pair<int, int>> s;
            if (i > 0 && map[i - 1][j] == 0)
            {
                map[i - 1][j] = 1;
                s.push({i - 1, j});
                curr++;
            }
            if (i < 99 && map[i + 1][j] == 0)
            {
                map[i + 1][j] = 1;
                s.push({i + 1, j});
                curr++;
            }
            if (j > 0 && map[i][j - 1] == 0)
            {
                map[i][j - 1] = 1;
                s.push({i, j - 1});
                curr++;
            }
            if (j < 99 && map[i][j + 1] == 0)
            {
                map[i][j + 1] = 1;
                s.push({i, j + 1});
                curr++;
            }
            while (!s.empty())
            {
                pair<int, int> a = s.top();
                int x = a.first, y = a.second;
                s.pop();
                if (i > 0 && map[x - 1][y] == 0)
                {
                    map[x - 1][y] = 1;
                    s.push({x - 1, y});
                    curr++;
                }
                if (x < 99 && map[x + 1][y] == 0)
                {
                    map[x + 1][y] = 1;
                    s.push({x + 1, y});
                    curr++;
                }
                if (y > 0 && map[x][y - 1] == 0)
                {
                    map[x][y - 1] = 1;
                    s.push({x, y - 1});
                    curr++;
                }
                if (y < 99 && map[x][y + 1] == 0)
                {
                    map[x][y + 1] = 1;
                    s.push({x, y + 1});
                    curr++;
                }
            }
            sort(res.begin(), res.end());
            if (res[0] < curr)
                res[0] = curr;
        }
    }
    cout << res[0] << " " << res[1] << " " << res[2] << "\n";
    cout << res[0] * res[1] * res[2] << "\n";
}