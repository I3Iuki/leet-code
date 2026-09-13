#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

int run(vector<int> &nums)
{
    // good[int] = {frequency, last index, expected distance}
    unordered_map<int, tuple<int, int, int>> good;
    unordered_set<int> bad;

    for (auto i = 0; i < nums.size(); ++i)
    {
        int num = nums[i];
        if (bad.find(num) == bad.end())
        {
            if (good.find(num) != good.end())
            {
                int &freq = get<0>(good[num]);
                int &lastIndex = get<1>(good[num]);
                int &expectedDistance = get<2>(good[num]);

                if (freq <= 2 && ((expectedDistance == -1) || (i - lastIndex) == expectedDistance))
                {
                    if (expectedDistance == -1)
                    {
                        expectedDistance = (i - lastIndex);
                    }
                    ++freq;
                    lastIndex = i;
                }
                else
                {
                    good.erase(num);
                    bad.insert(num);
                }
            }
            else
            {
                good[num] = {1, i, -1};
            }
        }
    }

    int count = 0;

    for (auto &thing : good)
    {
        if (get<0>(thing.second) == 3)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    vector<int> test1 = {1, 8, 1, 5, 1, 5, 8, 5};
    vector<int> test2 = {8, 8, 8, 8};
    vector<int> test3 = {8, 6, 6, 8, 8};

    cout << run(test1) << '\n';
    cout << run(test2) << '\n';
    cout << run(test3) << '\n';
}

// prolem statement:
// You are given an integer array nums.

// An integer x is called special if:

// x appears exactly three times in nums.
// All three occurrences of x are equally spaced in nums. In other words, if all occurrences of x are at indices i1 < i2 < i3, then i2 - i1 = i3 - i2.
// Return the number of distinct special integers in nums.