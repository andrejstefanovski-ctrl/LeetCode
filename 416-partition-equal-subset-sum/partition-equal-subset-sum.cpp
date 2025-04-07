class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        vector<bool> canMakeSum(target + 1, false);
        canMakeSum[0] = true;
        for (int num : nums) 
        {
            for (int sum = target; sum >= num; --sum) 
            {
                if (canMakeSum[sum - num]) 
                {
                    canMakeSum[sum] = true;
                }
            }
        }
        return canMakeSum[target];
    }
};
