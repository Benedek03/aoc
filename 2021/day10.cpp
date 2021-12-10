#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int result1=0;
    vector<long> v;
    for (int i = 0; i < 106; i++)
    {
        char c;
        cin >> c;
        stack<char> s;
        while (c != 'n')
        {
            if (c == '(')
                s.push(c);
            else if (c == '[')
                s.push(c);
            else if (c == '{')
                s.push(c);
            else if (c == '<')
                s.push(c);

            else if (c == ')')
            {
                if (s.top() == '(')
                    s.pop();
                else
                {
                    result1 += 3;
                    break;
                }
            }
            else if (c == ']')
            {
                if (s.top() == '[')
                    s.pop();
                else
                {
                    result1 += 57;
                    break;
                }
            }
            else if (c == '}')
            {
                if (s.top() == '{')
                    s.pop();
                else
                {
                    result1 += 1197;
                    break;
                }
            }
            else if (c == '>')
            {
                if (s.top() == '<')
                    s.pop();
                else
                {
                    result1 += 25137;
                    break;
                }
            }
            cin >> c;
        }
        if (c != 'n')
            while (c != 'n')
                cin >> c;
        else if (s.size() > 0)
        {
            long curr = 0;
            while (!s.empty())
            {
                curr *= 5;
                if (s.top() == '(')
                {
                    s.pop();
                    curr += 1;
                }
                else if (s.top() == '[')
                {
                    s.pop();
                    curr += 2;
                }
                else if (s.top() == '{')
                {
                    s.pop();
                    curr += 3;
                }
                else if (s.top() == '<')
                {
                    s.pop();
                    curr += 4;
                }
            }
            v.push_back(curr);
        }
    }
    cout <<"part 1: "<< result1 << "\n";
    sort(v.begin(), v.end());
    cout <<"part 2: "<< v[v.size() / 2] << "\n";
}