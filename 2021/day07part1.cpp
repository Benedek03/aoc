#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> crabs(1000);
    for (int i = 0; i < 1000; i++)
        cin >> crabs[i];

    sort(crabs.begin(), crabs.end());

    int least = INT32_MAX;
    for (int i = 0; i < crabs[999]; i++)
    {
        int curr = 0;
        for (auto &&crab : crabs)
        {
            int a = abs(crab - i);
            curr += a;
        }
        if (curr < least)
            least = curr;
    }
    cout << least << "\n";
}