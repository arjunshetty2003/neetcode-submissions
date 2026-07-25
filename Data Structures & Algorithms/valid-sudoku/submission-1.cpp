class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rowIndex;
        unordered_map<int, unordered_set<char>> colIndex;
        unordered_map<int, unordered_set<char>> boxIndex;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (!rowIndex[i].count(board[i][j])) {
                    rowIndex[i].insert(board[i][j]);
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
                if (!colIndex[j].count(board[i][j])) {
                    colIndex[j].insert(board[i][j]);
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
                int boxNumber = (i / 3) * 3 + (j / 3);
                if (!boxIndex[boxNumber].count(board[i][j])) {
                    boxIndex[boxNumber].insert(board[i][j]);
                }
                else {
                    return false;
                }
            }
        }

        return true;
    }
};
