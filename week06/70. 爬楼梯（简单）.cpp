// ==============================  动态规划(循环)  ==============================
// 3
class Solution {
public:
    int climbStairs(int n) {
        if(n < 3) return n;
        int first = 1;
        int second = 2;
        int temp;
        for(int i = 3; i <= n; i++)
        {
            temp = first + second;
            first = second;
            second = temp;
        }
        return temp;
    }
};

// =============================  记忆递归  ==============================
// 3
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> vec(n + 1, 0);
        return dfs(n, vec);
    }

private:
    int dfs(int n, vector<int>& vec) {
        if(n <= 2) return n;
        if(vec[n] == 0) vec[n] = dfs(n - 1, vec) + dfs(n - 2, vec);
        return vec[n];
    }
};