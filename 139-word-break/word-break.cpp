class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j]) {
                    string word = s.substr(j, i - j);
                    for (string& w : wordDict) {
                        if (w == word) {
                            dp[i] = true;
                            break;
                        }
                    }
                }
                if (dp[i]) break;
            }
        }

        return dp[n];
    }
};
