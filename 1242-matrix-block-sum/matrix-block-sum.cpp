class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            int top = max(0, i - k);
            int bottom = min(n - 1, i + k);
            
            for (int j = 0; j < m; j++) {
                int left = max(0, j - k);
                int right = min(m - 1, j + k);

                int currSum = 0;
                for (int r = top; r <= bottom; r++) {
                    for (int c = left; c <= right; c++) {
                        currSum += mat[r][c];
                    }
                }
                ans[i][j] = currSum;
            }
        }
        return ans;
    }
};