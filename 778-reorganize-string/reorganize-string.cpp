class Solution {
public:
    static bool cmp(pair<char,int> a, pair<char,int> b) {
        return a.second > b.second;
    }

    string reorganizeString(string s) {
        int n=s.size();
        unordered_map<char, int> freq;
        for (char c : s) 
        {
            freq[c]++;
        }
        vector<pair<char, int>> m(freq.begin(), freq.end());
        sort(m.begin(), m.end(), cmp);
        int maxFreq = m[0].second;
        if (maxFreq > (n+1)/2) return "";
        string res(n, ' ');
        int i=0;
        for (auto [ch,count] : m)
        {
            while (count--)
            {
                res[i] = ch;
                i+=2;
                if (i>=n) i=1;
            }
        }
        return res;
    }
};
