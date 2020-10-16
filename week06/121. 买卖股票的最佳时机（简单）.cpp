class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size < 2) return 0;
        int dp_0 = 0, dp_1 = -prices[0];
        for(int i = 1; i < size; i++) {
            int temp = dp_0;
            dp_0 = max(dp_0, dp_1 + prices[i]);
            dp_1 = max(dp_1, - prices[i]);
        }
        return dp_0;
    }
};