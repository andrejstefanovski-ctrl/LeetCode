class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        unordered_map<int, int> count_map;
        int max_length = 0;

        for (int num : nums) {
            count_map[num]++;
        }

        for (auto& entry : count_map) {
            if (count_map.find(entry.first + 1) != count_map.end()) {
                max_length = max(max_length, entry.second + count_map[entry.first + 1]);
            }
        }

        return max_length;
    }
};
