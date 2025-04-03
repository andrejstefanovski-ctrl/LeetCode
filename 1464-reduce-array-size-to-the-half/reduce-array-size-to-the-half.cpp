class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        vector<int> weights;
        for (auto& [key, value] : freq) {
            weights.push_back(value);
        }

        sort(weights.rbegin(), weights.rend());

        int removed = 0, count = 0, half = arr.size() / 2;
        for (int w : weights) {
            removed += w;
            count++;
            if (removed >= half) return count;
        }
        return count;
    }
};
