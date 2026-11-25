class Solution {
public:
    vector<vector<int>> oneShift(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> result(n, vector<int>(m,0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (j==m-1 && i==n-1) {
                    result[0][0]=grid[i][j];
                }
                else if (j==m-1) {
                    result[i+1][0] = grid[i][j];
                }
                else {
                    result[i][j+1]=grid[i][j];
                }
            }
        }
        return result;
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        while (k--) {
            grid = oneShift(grid);
        }
        return grid;
    }
};