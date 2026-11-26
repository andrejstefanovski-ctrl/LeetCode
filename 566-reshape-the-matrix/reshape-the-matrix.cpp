class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> ma(r, vector<int>(c,0));
        vector<int> allEl;
        if (n*m != r*c) return mat;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                allEl.push_back(mat[i][j]);
                cout << mat[i][j] << " ";
            }
        }
        cout << endl;
        int ind=0;
        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                ma[i][j] = allEl[ind];
                ind++;
            }
        }
        return ma;
    }
};