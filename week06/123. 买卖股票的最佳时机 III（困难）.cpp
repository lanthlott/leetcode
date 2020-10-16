class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size < 2) return 0;
        int dp_01 = 0, dp_00 = 0, dp_10 = -prices[0], dp_11 = -prices[0], dp_02 = 0, dp_12 = -prices[0];
        for(int i = 0; i < size; i++) {
            dp_02 = max(dp_02, dp_12 + prices[i]);
            dp_12 = max(dp_12, dp_01 - prices[i]);
            dp_01 = max(dp_01, dp_11 + prices[i]);
            dp_11 = max(dp_11, dp_00 - prices[i]);
        }
        return dp_02;
    }
};