#include <iostream>
#include <string>

using namespace std;

int main()
{
    int result = 0;
    for (int i = 0; i < 200; i++)
    {
        string str;
        for (int j = 0; j < 11; j++)
            cin >> str;

        for (int j = 0; j < 4; j++)
        {
            cin >> str;
            if (str.size() == 2 || str.size() == 3 || str.size() == 4 || str.size() == 7)
                result++;
        }
    }
    cout << result << "\n";
}
