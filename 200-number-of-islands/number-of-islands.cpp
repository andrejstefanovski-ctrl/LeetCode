class Solution {
public:
    void BFS(vector<vector<char>>& matrix, int node_x, int node_y, vector<vector<bool>>& visited)
{
    int m = matrix.size();
    int n = matrix[0].size();
    queue<pair<int, int>> q;
    q.push({node_x, node_y});
    visited[node_x][node_y] = true;

    vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions)
        {
            int new_x = x + dx;
            int new_y = y + dy;

            if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && !visited[new_x][new_y] && matrix[new_x][new_y] == '1')
            {
                visited[new_x][new_y] = true;
                q.push({new_x, new_y});
            }
        }
    }
}

    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.empty()) return 0;

        int ctr = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (grid[i][j] == '1' && !visited[i][j]) 
                {
                    BFS(grid, i, j, visited);
                    ctr++;
                }
            }
        }
        return ctr;
    }
};