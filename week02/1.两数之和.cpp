class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        map<int, int> hashmap;
        int a, b = nums.size();
        for(int i = 0; i < b; i++)
        {
            a = target - nums[i];
            for(int j = i + 1; j < b; j++)
            {
                if(nums[j] == a)
                {
                    return {i, j};
                }
            }            
        }
        return {0};
    }
};