class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rowIndex;
        unordered_map<int, unordered_set<char>> colIndex;
        unordered_map<int, unordered_set<char>> gridIndex;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (rowIndex[i].count(board[i][j]) == false) {
                    rowIndex[i].insert(board[i][j]);
                }
                else {
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (colIndex[i].count(board[j][i]) == false) {
                    colIndex[i].insert(board[j][i]);
                }
                else {
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int box = (i / 3) * 3 + (j / 3);
                if (gridIndex[box].count(board[i][j]) == false) {
                    gridIndex[box].insert(board[i][j]);
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};
