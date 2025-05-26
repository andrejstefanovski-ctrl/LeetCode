class Solution {
public:
    int Find(int u, vector<int>& parents)
    {
        if (u != parents[u])
        {
            parents[u] = Find(parents[u], parents);
        }
        return parents[u];
    }
    void Unite(int u, int v, vector<int>& parent)
    {
        int pu = Find(u, parent);
        int pv = Find(v, parent);
        if (pu != pv)
        {
            parent[pu]=pv;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>parent(n);
        for (int i=0; i<n; i++)
        {
            parent[i]=i;
        }
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<isConnected[i].size(); j++)
            {
                if (i != j && isConnected[i][j]==1)
                {
                    Unite(i, j, parent);
                }
            }
        }
        for (int i=0; i<n; i++)
        {
            parent[i] = Find(i, parent);
        }
        unordered_set<int> uniqueParents(parent.begin(), parent.end());
        return uniqueParents.size();
    }
};