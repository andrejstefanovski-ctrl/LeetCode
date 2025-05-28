class Solution {
public:
    void DFS(vector<vector<int>>& adjList, vector<bool>& visited, int start)
    {
        visited[start]=1;
        stack<int>s;
        s.push(start);
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            for (auto it:adjList[node])
            {
                if (!visited[it])
                {
                    visited[it]=true;
                    s.push(it);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>> adjList(stones.size());
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) 
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        vector<bool> visited(stones.size(), 0);
        int components=0;
        for (int i=0; i<stones.size(); i++)
        {
            if (!visited[i])
            {
                components++;
                DFS(adjList, visited, i);
            }
        }
        return n-components;
    }
};