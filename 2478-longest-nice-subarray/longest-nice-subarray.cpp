class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0, bitmask = 0, maxLen = 0;
        
        for (int r = 0; r < nums.size(); r++) {
            while ((bitmask & nums[r]) != 0) {
                bitmask ^= nums[l]; 
                l++;
            }
            
            bitmask |= nums[r];
            maxLen = max(maxLen, r - l + 1);
        }
        
        return maxLen;
    }
};
