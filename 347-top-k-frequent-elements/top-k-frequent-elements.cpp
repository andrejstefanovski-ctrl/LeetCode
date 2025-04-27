class Solution {
public:
    static bool cmp(pair<int,int>& p1, pair<int,int>& p2)
    {
        return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> f;
        for (int i=0; i<nums.size(); i++)
        {
            f[nums[i]]++;
        }
        vector<pair<int,int>> freq(f.begin(), f.end());
        sort(freq.begin(), freq.end(), cmp);
        vector<int> results;
        for (int i=0; i<k; i++)
        {
            results.push_back(freq[i].first);
        }
        return results;
    }
};