#include <iostream>

using namespace std;

int main()
{
    int last, curr, result = 0;
    int a, b, c;
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