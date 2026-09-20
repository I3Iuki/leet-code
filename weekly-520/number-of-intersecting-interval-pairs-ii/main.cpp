#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        long long count = 0;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        for (int i = 0; i < size; ++i) {
            int endpoint = intervals[i][1];

            auto it = upper_bound(intervals.begin() + i + 1, intervals.end(), endpoint, [](int target, const vector<int>& yeah) {
                return target < yeah[0];
            });
            int index = distance(intervals.begin() + i, it);

            count += index - 1;
        }

        return count;
    }
};