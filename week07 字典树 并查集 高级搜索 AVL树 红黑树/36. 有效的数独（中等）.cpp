// ==============================  剪枝 维护3个数组 ==============================
// 3
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(9, vector<int>(10, 0)), col(9, vector<int>(10,0)), box(9, vector<int>(10, 0));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if('.' == board[i][j]) continue;
                int idx = (i / 3) * 3 + j / 3;
                int temp = board[i][j] - '0';
                // if(temp == row[i][temp] || temp == col[j][temp] || temp == box[idx][temp]) return false;
                // if(temp & row[i][temp] || temp & col[j][temp] || temp & box[idx][temp]) return false;
                if(temp & (row[i][temp] | col[j][temp] | box[idx][temp])) return false;
                // 用位运算代替逻辑运算
                row[i][temp] = col[j][temp] = box[idx][temp] = temp;
            }
        }
        return true;
    }
};