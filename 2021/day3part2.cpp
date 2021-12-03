#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    vector<string> input(1000);
    for (int i = 0; i < 1000; i++)
        cin >> input[i];

    vector<string> oxVector(input);
    vector<string> ocVector(input);
    for (int i = 0; i < 12; i++)
    {
        if (oxVector.size() != 1)
        {
            int common = 0, j = 0;
            for (int j = 0; j < oxVector.size(); j++)
            {
                if (oxVector[j][i] == '1')
                    common++;
                else
                    common--;
            }
            char good = common >= 0 ? '1' : '0';
            while (j != oxVector.size())
            {
                if (oxVector[j][i] != good)
                    oxVector.erase(oxVector.begin() + j);
                else
                    j++;
            }
        }
        if (ocVector.size() != 1)
        {
            int common = 0, j = 0;
            for (int j = 0; j < ocVector.size(); j++)
            {
                if (ocVector[j][i] == '1')
                    common++;
                else
                    common--;
            }
            char good = common < 0 ? '1' : '0';
            while (j != ocVector.size())
            {
                if (ocVector[j][i] != good)
                    ocVector.erase(ocVector.begin() + j);
                else
                    j++;
            }
        }
    }

    int ox = 0, oc = 0;
    for (int j = 0; j < 12; j++)
    {
        if (oxVector[0][j] == '1')
            ox += pow(2, 11 - j);
        if (ocVector[0][j] == '1')
            oc += pow(2, 11 - j);
    }
    cout << ox * oc << "\n";
}