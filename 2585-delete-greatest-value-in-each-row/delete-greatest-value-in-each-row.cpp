class Solution {
public:
    bool endIt(vector<vector<int>>& grid) {
        int ctr=0;
        int total = grid.size() * grid[0].size();
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j]==-1) ctr++;
            }
        }
        return total==ctr;
    }
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int result=0, n=grid.size(), m=grid[0].size();
        while (!endIt(grid)) {
            int maxVal=-1;
            for (int i=0; i<n; i++) {
                int maxi=-1, ind_maxi=-1;
                for (int j=0; j<m; j++) {
                    if (maxi < grid[i][j]) {
                        maxi=grid[i][j];
                        ind_maxi = j;
                    }
                }
                grid[i][ind_maxi]=-1;
                maxVal = max(maxVal, maxi);
            }
            result+=maxVal;
        }
        return result;
    }
};