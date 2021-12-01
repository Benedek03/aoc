#include <iostream>

using namespace std;

int main()
{
    int last, curr, result = 0;
    cin >> curr;
    for (int i = 0; i < 1999; i++)
    {
        last = curr;
        cin >> curr;
        if (curr > last)
            result++;
    }
    cout << result << "\n";
}