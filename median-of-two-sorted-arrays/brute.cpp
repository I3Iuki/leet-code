#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> nums1 = {1, 3};
vector<int> nums2 = {2};

int main()
{
    vector<int> combined;

    for (int num : nums1)
    {
        combined.push_back(num);
    }

    for (int num : nums2)
    {
        combined.push_back(num);
    }

    sort(combined.begin(), combined.end());

    int size = combined.size();
    int half = (size / 2);

    if (size % 2 == 0)
    {
        int one = combined[half];
        int two = combined[half - 1];
        cout << round(((one + two) / 2.0) * 100000) / 100000 << '\n';
    }
    else
    {
        cout << round(combined[half] * 100000) / 100000 << '\n';
    }
}