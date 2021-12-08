#include <iostream>

using namespace std;

int main()
{
    long int arr[9] = {0};
    for (int i = 0; i < 300; i++)
    {
        int a;
        cin >> a;
        arr[a]++;
    }
    for (int i = 0; i < 256; i++)
    {
        long int tmp = arr[0];
        for (int j = 0; j < 8; j++)
            arr[j] = arr[j + 1];
        arr[6] += tmp;
        arr[8] = tmp;
    }
    long int sum = 0;
    for (int i = 0; i < 9; i++)
        sum += arr[i];
    cout << sum << "\n";
}