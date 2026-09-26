#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        int size = intervals.size();
        for (int i = 0; i < size - 1; ++i) {
            vector<int>& a = intervals[i];
            for (int j = i + 1; j < size; ++j) {
                vector<int>& b = intervals[j];  
                    if (
                        (find(b.begin(), b.end(), a[0]) != b.end() || find(b.begin(), b.end(), a[1]) != b.end()) ||
                        (a[0] < b[0] && b[0] < a[1]) || (b[0] < a[0] && a[0] < b[1])
                        ) {
                        count++;
                    }
            }
        }

        return count;
    }
};