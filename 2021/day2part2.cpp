#include <iostream>
#include <string>

using namespace std;

int main()
{
    int horizontal_position = 0, depth = 0, aim = 0;

    for (int i = 0; i < 1000; i++)
    {
        string instruction;
        int X;
        cin >> instruction >> X;
        if (instruction == string("down"))
            aim += X;
        else if (instruction == string("up"))
            aim -= X;
        else
        {
            horizontal_position += X;
            depth += X * aim;
        }
    }
    cout << depth * horizontal_position << "\n";
}
