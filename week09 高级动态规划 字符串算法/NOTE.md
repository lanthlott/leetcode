# 每周总结可以写在这里
# 不同路径II的状态转移方程：
# 首先，左上角→右下角 和 右下角→ 左上角本质上是一样的，我们这里选择(0, 0)→(n - 1, n - 1)的方向。
# 如果没有障碍物，那么我们的DP方程可以很容易地写出来：
DP[i][j] = DP[i - 1][j] + DP[i][j - 1]；
现在有了障碍物，我们得到：
if(DP[i][j] == 障碍物) DP[i][j] = 0;
else {DP[i][j] = DP[i - 1][j] + DP[i][j - 1]
并且要特别关注初始条件，在初始的那一行中，在遇到障碍物之前，DP[i][j]都是1，遇到障碍物之后，障碍物及障碍物之后的值都要置0；初始第一列也是如此，于是有了如下的初始化代码：
for(int i = 0; i < size1; i++) {
            if(1 == obstacleGrid[i][0]) break;
            vec[i][0] = 1;
        }
        for(int i = 0; i < size2; i++) {
            if(1 == obstacleGrid[0][i]) break;
            vec[0][i] = 1;
        }
再加上DP方程，完整代码如下：
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