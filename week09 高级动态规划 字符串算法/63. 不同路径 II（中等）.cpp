class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int size1 = obstacleGrid.size(), size2 = obstacleGrid[0].size();
        vector<vector<int>> vec(size1, vector<int>(size2, 0));
        for(int i = 0; i < size1; i++) {
            if(1 == obstacleGrid[i][0]) break;
            vec[i][0] = 1;
        }
        for(int i = 0; i < size2; i++) {
            if(1 == obstacleGrid[0][i]) break;
            vec[0][i] = 1;
        }
        for(int i = 1; i < size1; i++) {
            for(int j = 1; j < size2; j++) {
                vec[i][j] = 1 == obstacleGrid[i][j] ? 0 : vec[i - 1][j] + vec[i][j - 1];
            }
        }
        return vec[size1 - 1][size2 - 1];
    }
};