#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool contains(string s, char c)
{
    return s.find(c) != std::string::npos;
}

int main()
{
    int result = 0;
    for (int i = 0; i < 200; i++)
    {
        int _1i = -1, _4i = -1;
        string str, diff = "";
        vector<int> resi;
        vector<string> ress;
        vector<string> five_long, six_long;
        for (int j = 0; j < 10; j++)
        {
            cin >> str;
            if (str.size() == 2)
            {
                resi.push_back(1);
                ress.push_back(str);
                _1i = ress.size() - 1;
            }
            else if (str.size() == 3)
            {
                resi.push_back(7);
                ress.push_back(str);
            }
            else if (str.size() == 4)
            {
                resi.push_back(4);
                ress.push_back(str);
                _4i = ress.size() - 1;
            }
            else if (str.size() == 7)
            {
                resi.push_back(8);
                ress.push_back(str);
            }
            else if (str.size() == 5)
            {
                five_long.push_back(str);
            }
            else if (str.size() == 6)
            {
                six_long.push_back(str);
            }
        }
        for (auto &&e : ress[_4i])
            if (!contains(ress[_1i], e))
                diff += e;

        for (int j = 0; j < 3; j++)
        {
            if (contains(five_long[j], ress[_1i][0]) && contains(five_long[j], ress[_1i][1]))
            {
                resi.push_back(3);
                ress.push_back(five_long[j]);
                five_long.erase(five_long.begin() + j);
                break;
            }
        }
        for (int j = 0; j < 2; j++)
        {
            if (contains(five_long[j], diff[0]) && contains(five_long[j], diff[1]))
            {
                resi.push_back(5);
                ress.push_back(five_long[j]);
                five_long.erase(five_long.begin() + j);
                break;
            }
        }
        resi.push_back(2);
        ress.push_back(five_long[0]);
        five_long.erase(five_long.begin());

        for (int j = 0; j < 3; j++)
        {
            if (contains(six_long[j], ress[_4i][0]) && contains(six_long[j], ress[_4i][1]) && contains(six_long[j], ress[_4i][2]) && contains(six_long[j], ress[_4i][3]))
            {
                resi.push_back(9);
                ress.push_back(six_long[j]);
                six_long.erase(six_long.begin() + j);
                break;
            }
        }
        for (int j = 0; j < 2; j++)
        {
            if (contains(six_long[j], diff[0]) && contains(six_long[j], diff[1]))
            {
                resi.push_back(6);
                ress.push_back(six_long[j]);
                six_long.erase(six_long.begin() + j);
                break;
            }
        }
        resi.push_back(0);
        ress.push_back(six_long[0]);
        six_long.erase(six_long.begin());

        for (auto &e : ress)
            sort(e.begin(), e.end());

        cin >> str; // |

        for (int j = 0; j < 4; j++)
        {
            cin >> str;
            sort(str.begin(), str.end());
            for (int x = 0; x < 10; x++)
            {
                if (str == ress[x])
                {
                    result += resi[x] * pow(10, (3 - j));
                    break;
                }
            }
        }

        /** /
        cout << "diff: " << diff << "\n";
        cout << "known:\n";
        for (int j = 0; j < ress.size(); j++)
            cout << resi[j] << ": " << ress[j] << "\n";
        cout << "five long:\n";
        for (auto &&e : five_long)
            cout << e << "\n";
        cout << "six long:\n";
        for (auto &&e : six_long)
            cout << e << "\n";
        /**/
    }
    cout << result << "\n";
}
