class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curMax=0, maxTillNow=0, curMin=0, minTillNow=0;
        for (auto& it : nums)
        {
            curMax=max(it, curMax+it);
            curMin=min(it, curMin+it);
            maxTillNow=max(maxTillNow,curMax);
            minTillNow=min(minTillNow,curMin);
        }
        return max(maxTillNow,abs(minTillNow));
    }
};