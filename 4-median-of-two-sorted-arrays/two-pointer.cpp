#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

vector<int> one = {1, 2};
vector<int> two = {3, 4};

int main()
{
    int size = one.size() + two.size();
    int half = ceil(size / 2.0);

    int p1 = 1, p2 = 1;

    while (p1 + p2 <= half)
    {
        if (one[p1] < two[p2] && p1 < one.size())
        {
            p1++;
        }
        else
        {
            p2++;
        }
    }

    p1--;
    p2--;

    cout << "Half: " << half << '\n';
    cout << one[p1] << '\n';
    cout << two[p2] << '\n';

    if (size % 2 == 0)
    {
        return round((static_cast<double>(one[p1] + two[p2]) / 2.0) * 100000.0) / 100000.0;
    }
    else
    {
        return min(one[p1], two[p2]);
    }
}