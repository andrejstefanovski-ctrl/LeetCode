class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        vector<vector<bool>> T(n+1, vector<bool>(m+1));
        T[0][0]=1;
        for (int j=1; j<=m; j++)
        {
            if (p[j-1]=='*')
            {
                T[0][j] = T[0][j-1];
            }
        }
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                if (p[j-1]=='*')
                {
                    T[i][j] = T[i][j-1] || T[i-1][j];
                }
                else if (p[j-1]=='?' || s[i-1]==p[j-1])
                {
                    T[i][j]=T[i-1][j-1];
                }
            }
        }
        return T[n][m];
    }
};