class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size(), size2 = word2.size();
        int dp[size1 + 1][size2 + 1];
        if(0 == size1 && 0 == size2) return 0;
        for(int i = 0; i <= size1; i++) {
            dp[i][0] = i;
        }
        for(int i = 0; i <= size2; i++) {
            dp[0][i] = i;
        }
        for(int i = 1; i <= size1; i++) {
            for(int j = 1; j <= size2; j++) {
                int temp = dp[i - 1][j - 1];
                if(word1[i - 1] == word2[j - 1]) {
                    temp -= 1;
                }
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), temp);
            }
        }
        return dp[size1][size2];
    }
};