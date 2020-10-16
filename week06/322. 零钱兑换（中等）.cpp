class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount + 1, amount + 1);
        res[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(i >= coins[j]) {
                    res[i] = min(res[i], res[i - coins[j]] + 1);
                }
            }
        }
        return res[amount] > amount ? -1 : res[amount];
    }
};