#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void run(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
    for (int i = 0; i < rowShift.size(); ++i) {
        int shift = rowShift[i];
        deque<int> row(grid[i].begin(), grid[i].end());
        for (int j = 0; j < shift; ++j) {
            int temp = row.front();
            row.pop_front();
            row.push_back(temp);
        }

        vector<int> asdf(row.begin(), row.end());
        
        grid[i] = asdf;
    }
    
    for (int i = 0; i < colShift.size(); ++i) {
        int shift = colShift[i];
        deque<int> col;

        for (int j = 0; j < n; j++)
        {
            col.push_back(grid[j][i]);
        }

        for (int j = 0; j < shift; ++j) {
            int temp = col.front();
            col.pop_front();
            col.push_back(temp);
        }

        for (int j = 0; j < n; j++)
        {
            grid[j][i] = col[j];
        }
    }

    for (const auto& row : grid) {
        for (const auto& column : row) {
            cout << column << ' ' << '\n';
        }
        cout << '\n';
    }
}

int main() {
    
}