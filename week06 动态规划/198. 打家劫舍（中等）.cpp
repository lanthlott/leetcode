class Solution {
public:
    int rob(vector<int>& nums) {
        if(0 == nums.size()) return 0;
        if(1 == nums.size()) return nums[0];
        vector<int> vec(nums.size(), 0);
        vec[0] = nums[0];
        vec[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++) {
            vec[i] = max(vec[i - 2] + nums[i], vec[i - 1]);
        }
        return vec[nums.size() - 1];
    }
};