class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), prev(n, -1);
        int maxIdx = 0;

        for (int i=1; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                if (nums[i]%nums[j] == 0 && dp[j]+1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxIdx]) maxIdx = i;
        }

        vector<int> res;
        while (maxIdx != -1) 
        {
            res.push_back(nums[maxIdx]);
            maxIdx = prev[maxIdx];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
