class Solution {
public:
    int climbStairs(int n) {
        vector<int> memoization={1,1};
        for (int i=2; i<=n; i++)
        {
            memoization.push_back(memoization[i-1]+memoization[i-2]);
        }
        return memoization[n];
    }
};