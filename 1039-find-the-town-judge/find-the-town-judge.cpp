class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adjList(n);
        for (auto it:trust)
        {
            adjList[it[1]-1].push_back(it[0]-1);
        }
        bool t=true;
        for (int i=0; i<n; i++)
        {
            if (adjList[i].size()==n-1)
            {
                for (auto it:adjList)
                {
                    for (auto jt:it)
                    {
                        if (jt==i) {t=false; break;}
                    }
                }
                if (t) return i+1;
            }
        }
        return -1;
    }
};