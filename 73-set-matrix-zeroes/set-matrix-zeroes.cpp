class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> coordinates;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix[i].size(); j++) {
                if (matrix[i][j]==0) coordinates.push_back({i, j});
            }
        }
        for (auto& it:coordinates) {
            int y=it.first, x=it.second;
            for (int i=0; i<matrix[0].size(); i++) {
                matrix[y][i]=0;
            }
            for (int j=0; j<matrix.size(); j++) {
                matrix[j][x]=0;
            }
        }
    }
};