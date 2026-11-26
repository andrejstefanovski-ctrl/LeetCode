class Solution {
public:

    bool isValid(vector<vector<int>>& nums) {
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<nums[0].size(); j++) {
                if (nums[i][j] != INT_MIN) return false;
            }
        }
        return true;
    }
    int matrixSum(vector<vector<int>>& nums) {
        int sum=0, n=nums.size(), m=nums[0].size();
        //vector<int> track;
        while (!isValid(nums)) {
            int globalMax=INT_MIN;
            bool flag=false;
            for (int i=0; i<n; i++) {
                int localMax, ind_i=-1, ind_j=-1;
                for (int j=0; j<m; j++) {
                    if (j==0 || nums[i][j] > localMax) {
                        localMax = nums[i][j];
                        ind_i=i;ind_j=j;
                    }
                }
                nums[ind_i][ind_j]=INT_MIN;
                //track.push_back(localMax);
                globalMax = max(globalMax, localMax);
            }
            sum+=globalMax;
        }
        return sum;
    }
};