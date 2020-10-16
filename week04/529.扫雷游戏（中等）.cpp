class Solution {
public:
    vector<vector<char>> vec;
    int M, N;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        M = board.size();
        N = board[0].size();
        if(M == 0 || N == 0) return board;

        int i = click[0];
        int j = click[1];
        if(board[i][j] == 'M')
        {
            board[i][j] = 'X';
            return board; 
        }
        vec = board;

        dfs( i, j);
        return vec;
    }

private:
    void dfs(int i, int j)
    {
        int count = 0;
        if(i < 0 || i >= M || j < 0 || j >= N || vec[i][j] != 'E') return;
        if(vec[  i  ][  j  ] == 'M') {return;}
        if(vec[  i  ][  j  ] == 'E')
        {
            if(i >= 0 && i < M && (j - 1) >= 0 && (j - 1) < N && vec[  i  ][j - 1] == 'M') 
            {count+=1;}
            if(i >= 0 && i < M && (j + 1) >= 0 && (j + 1) < N && vec[  i  ][j + 1] == 'M') 
            {count+=1;}
            if((i - 1) >= 0 && (i - 1) < M && (j - 1) >= 0 && (j - 1) < N && vec[i - 1][j - 1] == 'M') 
            {count+=1;}
            if((i - 1) >= 0 && (i - 1) < M && j >= 0 && j < N && vec[i - 1][  j  ] == 'M') 
            {count+=1;}
            if((i - 1) >= 0 && (i - 1) < M && (j + 1) >= 0 && (j + 1) < N && vec[i - 1][j + 1] == 'M') 
            {count+=1;}
            if((i + 1) >= 0 && (i + 1) < M && (j - 1) >= 0 && (j - 1) < N && vec[i + 1][j - 1] == 'M') 
            {count+=1;}
            if((i + 1) >= 0 && (i + 1) < M && j >= 0 && j < N && vec[i + 1][  j  ] == 'M') 
            {count+=1;}
            if((i + 1) >= 0 && (i + 1) < M && (j + 1) >= 0 && (j + 1) < N && vec[i + 1][j + 1] == 'M') 
            {count+=1;}
            if(count == 0)
            {
                vec[  i  ][  j  ] = 'B';
                dfs(  i  , j - 1);
                dfs(   i  , j + 1);
                dfs( i - 1, j - 1);
                dfs( i - 1,   j  );
                dfs( i - 1, j + 1);
                dfs( i + 1, j - 1);
                dfs( i + 1,   j  );
                dfs( i + 1, j + 1);
            }
            else vec[i][j] = count + '0';
        }
    }
};