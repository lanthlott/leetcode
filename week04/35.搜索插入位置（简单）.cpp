class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while(left < right)
        {
            mid = (right + left) / 2;
            // if(target == nums[mid]) return mid;
            if(target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        mid = target > nums[left] ? (left + 1) : left;
        return mid;
    }
};