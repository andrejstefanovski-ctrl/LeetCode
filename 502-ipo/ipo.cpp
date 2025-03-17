class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> v(n);
        for (int i=0; i<n; i++)
        {
            v[i]={capital[i], profits[i]};
        }
        sort(v.begin(), v.end());
        int i=0;
        priority_queue<int> q;
        while (k--)
        {
            while (i<n && v[i].first <= w)
            {
                q.push(v[i].second);
                i++;
            }
            if (q.empty()) break;
            w+=q.top();
            q.pop();
        }
        return w;
    }
};