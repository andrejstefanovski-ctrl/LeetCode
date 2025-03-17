class Solution {
public:
    int numberOfSubstrings(string s) {
        int ctr=0, left=0;
        int n =s.size();
        unordered_map<char, int> m={{'a',0},{'b',0},{'c',0}};
        for (int right=0; right<n; right++)
        {
            m[s[right]]++;
            while (m['a']>0 && m['b']>0 && m['c']>0)
            {
                ctr += n-right;
                m[s[left]]--;
                left++;
            }
        }
        return ctr;
    }
};