class Solution {
public:
    bool canJump(vector<int>& nums) {
        int right = nums.size() - 1;
        int left = right;
        while(left != 0)
        {
            left--;
            if(nums[left] >= right - left) right = left;
        }
        bool result = right == 0 ? true : false;
        return result;
    }
};