#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    const int lines = 1000, columns = 12;
    int gamma = 0, epsilon = 0;

    int common[columns] = {0};
    for (int i = 0; i < lines; i++)
    {
        string in;
        cin >> in;
        for (int j = 0; j < columns; j++)
        {
            if (in[j] == '1')
                common[j]++;
            else
                common[j]--;
        }
    }

    for (int j = 0; j < columns; j++)
    {
        if (common[j] > 0)
            gamma += pow(2, columns - j - 1);
        else
            epsilon += pow(2, columns - j - 1);
    }

    cout << gamma * epsilon << "\n";
}