class Solution {
public:
    void DFS(int start, vector<bool>& vis, vector<vector<int>>& adjList)
    {
        vis[start]=1;
        for (auto& it:adjList[start])
        {
            if (!vis[it])
            {
                DFS(it, vis, adjList);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adjList(n);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (isConnected[i][j]==1 && i!=j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<bool> vis(n,0);
        int ctr=0;
        for (int i=0; i<n; i++)
        {
            if (!vis[i])
            {
                ctr++;
                DFS(i, vis, adjList);
            }
        }
        return ctr;
    }
};