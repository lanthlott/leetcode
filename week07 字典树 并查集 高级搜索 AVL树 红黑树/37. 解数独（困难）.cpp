// ==============================  DFS ºÙ÷¶ ªÿÀ›  ==============================
// 3
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }

private:
    bool dfs(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i ++) {
            for(int j = 0; j < 9; j++) {
                if('.' != board[i][j]) continue;
                for(char ch = '1'; ch <= '9'; ch++) {
                    if(valid(board, i, j, ch)) {
                        board[i][j] = ch;
                        if(dfs(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool valid(vector<vector<char>>& board, int row, int col, char ch) {
        for(int i = 0; i < 9; i++) {
            int irow = (row / 3) * 3 + i / 3;
            int icol = (col / 3) * 3 + i % 3;
            if(ch == board[row][i] || ch == board[i][col] || ch == board[irow][icol]) return false;
        }
        return true;
    }
};