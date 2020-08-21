class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if('1' == grid[i][j])
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

private:
    int count = 0;
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || '0' == grid[i][j]) return;
        grid[i][j] = '0';
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
    }
};