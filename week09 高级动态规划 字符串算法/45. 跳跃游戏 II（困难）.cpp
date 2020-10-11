class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size() - 1, temp = 0, end = 0, res = 0;
        for(int i = 0; i < size; i++) {
            temp = max(temp, i + nums[i]);
            if(i == end) {
                res++;
                end = temp;
            }
        }
        return res;
    }
};