class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ctr=n-1;
        vector<vector<int>> temp(n, vector<int>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                temp[j][ctr] = matrix[i][j];
            }
            ctr--;
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                matrix[i][j] = temp[i][j];
            }
        }
    }
};