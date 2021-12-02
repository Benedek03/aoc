#include <iostream>
#include <string>

using namespace std;

int main()
{
    long int horizontal = 0;
    long int depth = 0;
    long int aim = 0;

    for (int i = 0; i < 1000; i++)
    {
        string instruction;
        int X;
        cin >> instruction >> X;
        if (instruction[0] == 'f')
        {
            horizontal += X;
            depth += X * aim;
        }
        else if (instruction[0] == 'd')
            aim += X;
        else if (instruction[0] == 'u')
            aim -= X;
    }
    cout << depth * horizontal << "\n";
}
