class Solution {
public:
    int Dijkstra (int n, vector<vector<pair<int,int>>>& adjList)
    {
        const int MOD=1e9+7;
        vector<bool> visited(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,long long>> pq;
        pq.push({0,0});
        while (!pq.empty())
        {
            pair<long long, long long> state = pq.top();
            pq.pop();
            long long city=state.second;
            if (!visited[city])
            {
                visited[city]=1;
                for (auto& t : adjList[city])
                {
                    long long next=t.first, w=t.second;
                    if (dist[next] > dist[city]+w)
                    {
                        dist[next] = dist[city]+w;
                        pq.push({-dist[next], next});
                        ways[next]=ways[city];
                    }
                    else if (dist[next] == dist[city]+w)
                    {
                        ways[next] = (ways[next] + ways[city]) % MOD;
                    }
                }
            }
        }
        return ways[n-1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjList(n);
        for (int i=0; i<roads.size(); i++)
        {
            adjList[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adjList[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        return Dijkstra(n, adjList);
    }
};