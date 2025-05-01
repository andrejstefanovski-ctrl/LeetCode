class Solution {
public:
    string toBin(int n) {
        string s;
        while (n != 0)
        {
            s += to_string(n%2);
            n/=2;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 0);
        dp[0]=0;
        if (n==0) return dp;
        dp[1]=1;
        if (n==1) return dp;
        for (int i=2; i<=n; i++)
        {
            int turcin=0;
            string x = toBin(i);
            for (int i=0; i<x.size(); i++)
            {
                if (x[i]=='1') turcin++;
            }
            dp[i]=turcin;
        }
        return dp;
    }
};