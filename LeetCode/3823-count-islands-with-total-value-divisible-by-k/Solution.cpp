class Solution {
public:
    void recursiveCheck(vector<vector<int>>& grid, int i, int j, long long& sum) {
        sum += grid[i][j];
        grid[i][j] = INT_MIN;

        if (i + 1 < grid.size() && grid[i+1][j] != 0 && grid[i+1][j] != INT_MIN) {
            recursiveCheck(grid, i+1, j, sum);
        }
        if (j + 1 < grid[i].size() && grid[i][j+1] != 0 && grid[i][j+1] != INT_MIN) {
            recursiveCheck(grid, i, j+1, sum);
        }
        if (i - 1 >= 0 && grid[i-1][j] != 0 && grid[i-1][j] != INT_MIN) {
            recursiveCheck(grid, i-1, j, sum);
        }
        if (j - 1 >= 0 && grid[i][j-1] != 0 && grid[i][j-1] != INT_MIN) {
            recursiveCheck(grid, i, j-1, sum);
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int ctr = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] != 0 && grid[i][j] != INT_MIN) {
                    long long sum = 0;
                    recursiveCheck(grid, i, j, sum);
                    if (sum % k == 0) {
                        ctr++;
                    }
                }
            }
        }
        return ctr;
    }
};