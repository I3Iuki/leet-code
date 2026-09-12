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
        const int num = nums[i];
        if (bad.find(num) == bad.end())
        {
            // if not in good, put in good
            if (good.find(num) == good.end())
            {
                good[num] = {1, i, -1};
            }
            else
            {
                // if in good, see if its still good
                if (get<2>(good[num]) == -1)
                {
                    get<2>(good[num]) = i - get<1>(good[num]);
                }
                else if (get<0>(good[num]) + 1 > 3 || i - get<1>(good[num]) != get<2>(good[num]))
                {

                    good.erase(num);
                    bad.insert(num);
                }
                else
                {
                    get<0>(good[num]) += 1;
                    get<1>(good[num]) = i;
                }
            }
        }
    }

    int count = 0;

    for (auto &thing : good)
    {
        if (get<0>(thing) == 3)
        {
            count++;
        }
        else
        {
            cout << get<0>(thing) << '\n';
        }
    }

    return good.size();
}

int main()
{
    vector<int> test1 = {1, 8, 1, 5, 1, 5, 8, 5};
    vector<int> test2 = {8, 8, 8, 8};
    vector<int> test3 = {8, 6, 6, 8, 8};

    cout << run(test1) << '\n';
    // cout << run(test2) << '\n';
    // cout << run(test3) << '\n';
}

// prolem statement:
// You are given an integer array nums.

// An integer x is called special if:

// x appears exactly three times in nums.
// All three occurrences of x are equally spaced in nums. In other words, if all occurrences of x are at indices i1 < i2 < i3, then i2 - i1 = i3 - i2.
// Return the number of distinct special integers in nums.