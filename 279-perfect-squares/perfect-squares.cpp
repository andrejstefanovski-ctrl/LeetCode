class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        int mini=INT_MAX;
        for (int i=n; i>0; i--)
        {
            double x = sqrt(i);
            int y = static_cast<int>(x);
            if (x==y)
            {
                v.push_back(i);
            }
        }
        vector<int> dp(n+1, INT_MAX);
        dp[0]=0;
        for (auto num : v)
        {
            for (int j=num; j<=n; j++)
            {
                if (dp[j-num]!=INT_MAX)
                {
                    dp[j] = min(dp[j], dp[j-num]+1);
                }
            }
        }
        return dp[n];
    }
};