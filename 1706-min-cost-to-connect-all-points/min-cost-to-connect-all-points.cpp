class Solution {
public:
    struct Edge{
        int u,v,w;
        bool operator<(const Edge& other) const {
            return w < other.w;
        }
    };
    int Find(int u, vector<int>& parent)
    {
        if (parent[u] != u)
        {
            parent[u] = Find(parent[u], parent);
        }
        return parent[u];
    }
    void Union(int u, int v, vector<int>& parent)
    {
        int pu = Find(u, parent);
        int pv = Find(v, parent);
        if (pu != pv)
        {
            parent[pu]=pv;
        }
    }
    int Kruskal(int n, vector<Edge>& edges)
    {
        sort(edges.begin(), edges.end());
        vector<int> parent(n);
        for (int i=0; i<n; i++)
        {
            parent[i]=i;
        }
        int total=0;
        for (auto& edge:edges)
        {
            if (Find(edge.u, parent) != Find(edge.v, parent))
            {
                total += edge.w;
                Union(edge.u, edge.v, parent);
            }
        }
        return total;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<Edge> edges;
        for (int i=0; i<n-1; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                Edge ed;
                ed.u=i;
                ed.v=j;
                ed.w=abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                edges.push_back(ed);
            }
        }
        return Kruskal(n, edges);
    }
};