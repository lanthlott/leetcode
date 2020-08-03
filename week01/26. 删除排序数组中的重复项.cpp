class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i = 0, j = 0;
        if (nums.size() == 0) return 0;
        int len = nums.size() - 1;
        for(; i < len;)
        {
            if(nums[i++] != nums[i])
            {
                nums[++j] = nums[i];
            }
        }
        j++;
        return j;
    }
}; 