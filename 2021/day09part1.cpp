#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> heightmap(100, vector<int>(100));
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            cin >> heightmap[i][j];

    int res = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            bool lowpoint = true;
            if (i > 0 && heightmap[i - 1][j] <= heightmap[i][j])
                lowpoint = false;
            if (i < 99 && heightmap[i + 1][j] <= heightmap[i][j])
                lowpoint = false;
            if (j > 0 && heightmap[i][j - 1] <= heightmap[i][j])
                lowpoint = false;
            if (j < 99 && heightmap[i][j + 1] <= heightmap[i][j])
                lowpoint = false;
            if (lowpoint)
                res += 1 + heightmap[i][j];
        }
    }
    cout << res << "\n";
}