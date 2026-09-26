#include <vector>

using namespace std;

class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if (source[0] == target[0] && source[1] == target[1]) {
            return 0;
        } else if (source[0] == target[0] || source[1] == target[1] || max(target[0], source[0]) - min(target[0], source[0]) == max(target[1], source[1]) - min(target[1], source[1])) {
            return 1;
        } else {
            return 2;
        }
    }
}