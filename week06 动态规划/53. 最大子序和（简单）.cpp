class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0], temp = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            temp = nums[i] + max(0, temp);
            res = max(res, temp);
        }
        return res;
    }
};