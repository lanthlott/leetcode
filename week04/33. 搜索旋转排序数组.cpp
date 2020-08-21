class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(nums[mid] >= target && target >= nums[left])
            {
                right = mid;
            }
            else if((nums[left] > nums[mid]) && ((target <= nums[mid] || target >= nums[left])))
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return nums[left] == target ? left : -1;
    }
};