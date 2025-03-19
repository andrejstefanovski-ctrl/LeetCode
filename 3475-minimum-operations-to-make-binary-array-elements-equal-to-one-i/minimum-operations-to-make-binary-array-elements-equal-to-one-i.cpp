class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ctr=0;
        for (int i=0; i<=nums.size()-3; i++)
        {
            if (nums[i]==1) continue;
            else ctr++;
            for (int j=i; j<i+3; j++)
            {
                if (nums[j]==1) nums[j]=0;
                else nums[j]=1;
            }
        }
        for (auto it:nums)
        {
            if (it!=1) return -1;
        }
        return ctr;
    }
};