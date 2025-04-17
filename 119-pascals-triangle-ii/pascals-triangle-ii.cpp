class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>> pascal;
        pascal.push_back({1});
        pascal.push_back({1,1});
        for (int i=2; i<=n; i++)
        {
            vector<int> temp(i+1, 1);
            for (int j=1; j<i; j++)
            {
                temp[j] = pascal[i-1][j-1]+pascal[i-1][j];
            }
            pascal.push_back(temp);
        }
        return pascal[n];
    }
};