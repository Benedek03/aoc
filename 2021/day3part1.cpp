#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    int common[12] = {0};
    for (int i = 0; i < 1000; i++)
    {
        string in;
        cin >> in;
        for (int j = 0; j < 12; j++)
        {
            if (in[j] == '1')
                common[j]++;
            else
                common[j]--;
        }
    }

    int gamma = 0, epsilon = 0;
    for (int j = 0; j < 12; j++)
    {
        if (common[j] > 0)
            gamma += pow(2, 11 - j);
        else
            epsilon += pow(2, 11 - j);
    }
    cout << gamma * epsilon << "\n";
}