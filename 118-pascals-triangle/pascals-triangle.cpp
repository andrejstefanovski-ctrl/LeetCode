class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> rows;
        rows.push_back({1});
        if (n==1) return rows;
        rows.push_back({1,1});
        if (n==2) return rows;
        for (int i=2; i<n; i++)
        {
            vector<int> temp(i+1, 1);
            for (int j=1; j<i; j++)
            {
                temp[j] = rows[i-1][j-1]+rows[i-1][j];
            }
            rows.push_back(temp);
        }
        return rows;
    }
};