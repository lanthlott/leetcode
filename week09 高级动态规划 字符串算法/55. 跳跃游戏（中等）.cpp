class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left = nums.size() - 1, right = nums.size() - 1;
        while(left != 0) {
            left--;
            if(nums[left] >= right - left) {
                right = left;
            }
        }
        return 0 == right;
    }
};