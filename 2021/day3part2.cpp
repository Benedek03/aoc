#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    const int lines = 1000, columns = 12;
    vector<string> input(lines);
    for (int i = 0; i < lines; i++)
        cin >> input[i];

    vector<string> asd(input);
    for (int i = 0; i < columns; i++)
    {
        if (asd.size() == 1)
            break;
        int common = 0;
        for (int j = 0; j < asd.size(); j++)
        {
            if (asd[j][i] == '1')
                common++;
            else
                common--;
        }
        char good = common >= 0 ? '1' : '0';
        int j = 0;
        while (j != asd.size())
        {
            if (asd[j][i] != good)
                asd.erase(asd.begin() + j);
            else
                j++;
        }
    }
    vector<string> asd1(input);
    for (int i = 0; i < columns; i++)
    {
        if (asd1.size() == 1)
            break;
        int common = 0;
        for (int j = 0; j < asd1.size(); j++)
        {
            if (asd1[j][i] == '1')
                common++;
            else
                common--;
        }
        char good = common < 0 ? '1' : '0';
        int j = 0;
        while (j != asd1.size())
        {
            if (asd1[j][i] != good)
                asd1.erase(asd1.begin() + j);
            else
                j++;
        }
    }

    int ox = 0;
    for (int j = 0; j < columns; j++)
    {
        if (asd[0][j] == '1')
            ox += pow(2, columns - j - 1);
    }
    int oc = 0;
    for (int j = 0; j < columns; j++)
    {
        if (asd1[0][j] == '1')
            oc += pow(2, columns - j - 1);
    }
    cout << ox * oc << "\n";
}