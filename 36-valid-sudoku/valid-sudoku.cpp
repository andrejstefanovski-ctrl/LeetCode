class Solution {
public:
    bool lineCheck(vector<char>& line) {
        vector<char> v;
        for (auto& it:line) {
            if (it>='1' && it<='9') {
                if (v.empty()) {
                    v.push_back(it);
                    continue;
                }
                else {
                    for (int i=0; i<v.size(); i++) {
                        if (v[i] == it) {
                            return false;
                        }
                    }
                    v.push_back(it);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0; i<board.size(); i++) {
            if (!lineCheck(board[i])) {
                return false;
            }
        }
        for (int col=0; col<9; col++) {
            vector<char> curr;
            for (int row=0; row<9; row++) {
                curr.push_back(board[row][col]);
            }
            if (!lineCheck(curr)) {
                return false;
            }
        }
        for (int boxRow=0; boxRow<9; boxRow += 3) {
            for (int boxCol=0; boxCol<9; boxCol += 3) {
                vector<char> curr;
                for (int r=0; r<3; r++) {
                    for (int c=0; c<3; c++) {
                        curr.push_back(board[boxRow + r][boxCol + c]);
                    }
                }
                if (!lineCheck(curr)) {
                    return false;
                }
            }
        }
        return true;
    }
};