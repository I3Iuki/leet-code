#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

string s = "MMXXIX";

unordered_map<char, int> conversions = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

int main()
{
    bool first = true;
    int result = 0;
    int x = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        int cur = conversions[s[i]];

        if (first)
        {
            x += cur;
            first = false;
            continue;
        }

        int prev = conversions[s[i - 1]];

        if (prev > cur)
        {
            result += x;
            x = cur;
        }
        else if (prev == cur)
        {
            x += cur;
        }
        else
        {
            // prev < cur
            x = cur - x;
        }

    }
    result += x;

    cout << result << '\n';

    return result;
}