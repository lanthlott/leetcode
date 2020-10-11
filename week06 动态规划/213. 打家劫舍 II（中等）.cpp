class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size(), res = 0;
        if(0 == size) return 0;
        if(1 == size) return nums[0];
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < size - 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        res = dp[size - 2];
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i = 2; i < size; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        res = max(res, dp[size - 1]);
        return res;
    }
};