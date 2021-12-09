#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    vector<vector<int>> map(100, vector<int>(100, 0));
    vector<int> res(3, 0);
    stack<pair<int, int>> s;
    int curr;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
        {
            int a;
            cin >> a;
            if (a == 9)
                map[i][j] = -1;
        }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (map[i][j] == 1)
                continue;
            curr = 0;
            s.push({i, j});
            map[i][j] = 1;
            while (!s.empty())
            {
                int x = s.top().first, y = s.top().second;
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
    cout << res[0] * res[1] * res[2] << "\n";
}