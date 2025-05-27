class Solution {
public:
    void DFS(vector<bool>& visited, int node, vector<vector<int>>& rooms)
    {
        visited[node]=true;
        for (auto it : rooms[node])
        {
            if (!visited[it]) DFS(visited, it, rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,0);
        DFS(visited, 0, rooms);
        for (auto it:visited)
        {
            if (it==0) return 0;
        }
        return 1;
    }
};