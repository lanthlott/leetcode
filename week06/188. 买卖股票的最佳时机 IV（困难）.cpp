class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if(k > size / 2) return f(prices);
        if(size < 2) return 0;
        int dp_0[k + 1], dp_1[k + 1];
        for(int i = 0; i < k + 1; i++) {
            dp_0[i] = 0;
            dp_1[i] = -prices[0];
        }
        for(int i = 1; i < size; i++) {
            for(int j = k; j > 0; j--) {
                dp_0[j] = max(dp_0[j], dp_1[j] + prices[i]);
                dp_1[j] = max(dp_1[j], dp_0[j - 1] - prices[i]);
            }
        }
        return dp_0[k];
    }

private:
    int f(vector<int>& prices) {
        int size = prices.size();
        if(size < 2) return 0;
        int dp_0 = 0, dp_1 = -prices[0];
        for(int i = 1; i < size; i++) {
            int temp = dp_0;
            dp_0 = max(dp_0, dp_1 + prices[i]);
            dp_1 = max(dp_1, temp - prices[i]);
        }
        return dp_0;
    }
};