#include <iostream>

using namespace std;

int main()
{
    int a, b, c, last, curr, result = 0;
    cin >> a;
    cin >> b;
    cin >> c;
    curr = a + b + c;
    for (int i = 0; i < 1997; i++)
    {
        last = curr;
        a = b;
        b = c;
        cin >> c;
        curr = a + b + c;
        if (curr > last)
            result++;
    }
    cout << result << "\n";
}