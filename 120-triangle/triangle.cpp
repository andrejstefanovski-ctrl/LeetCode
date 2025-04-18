class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int n=v.size();
        vector<int>dp  = v[n-1];
        for (int i=n-2; i>=0; i--)
        {
            for (int j=0; j<=i; j++)
            {
                dp[j] = v[i][j] + min(dp[j+1], dp[j]);
            }
        }
        return dp[0];
    }
};