class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top=0, bottom=n-1, left=0, right=n-1, ctr=1;
        vector<vector<int>>matrix(n, vector<int>(n,0));
        while (top<=bottom && left<=right) {
            for (int i=left; i<=right; i++) {
                matrix[top][i]=ctr;
                ctr++;
            }
            top++;
            for (int i=top; i<=bottom; i++) {
                matrix[i][right]=ctr;
                ctr++;
            }
            right--;
            if (top <= bottom) {
                for (int i=right; i>=left; i--) {
                    matrix[bottom][i]=ctr;
                    ctr++;
                }
                bottom--;
            }
            if (left <= right) {
                for (int i=bottom; i>=top; i--) {
                    matrix[i][left]=ctr;
                    ctr++;
                }
                left++;
            }
        }
        return matrix;
    }
};