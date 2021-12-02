#include <iostream>
#include <string>

using namespace std;

int main()
{
    int horizontal_position = 0, depth = 0;

    for (int i = 0; i < 1000; i++)
    {
        string instruction;
        int X;
        cin >> instruction >> X;
        if (instruction == string("forward"))
            horizontal_position += X;
        else if (instruction == string("down"))
            depth += X;
        else
            depth -= X;
    }
    cout << depth * horizontal_position << "\n";
}
