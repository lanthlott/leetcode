class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        DFS(nums, 0);
        vector<vector<int>> vec;
        vec.assign(myset.begin(), myset.end());
        return vec;
    }

private:
    void DFS(vector<int>& nums, int begin)
    {
        if(temp.size() >= 2) myset.insert(temp);
        for(int i = begin; i < nums.size(); i++)
        {
            if(temp.empty() || temp.back() <= nums[i])
            { // һ��ʼ����������ţ������ҿ���û����Ĵ���һֱ������
                temp.push_back(nums[i]);
                DFS(nums, i + 1);
                temp.pop_back();
            }
        }
    }

private:
    vector<int> temp;
    set<vector<int>> myset;
};

// �������Ƶ�˼·��������ͨ����set��ʱȥ�ض�����ȫ��ɸѡ�������ٸ�ֵ��vector��Ч�ʴ�����
// class Solution {
// public:
//     vector<vector<int>> res;
//     vector<int> tmp;
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         solver(nums, 0);
//         return res;
//     }

//     void solver(vector<int>& nums, int i){
//         if(tmp.size() > 1) res.push_back(tmp);
//         unordered_set<int> used;
//         for(int j = i; j < nums.size(); j++){
//             int v = nums[j];
//             if(used.find(v) != used.end()) continue;
//             else{
//                 if(tmp.size() == 0 || v >= tmp.back()){
//                     used.insert(v);
//                     tmp.push_back(v);
//                     solver(nums, j+1);
//                     tmp.pop_back();
//                 }
//             }
//         }
//     }
    
// };

// ===========================  ��Ʊ���  ===============================
// class Solution {
// public:
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         vector<int> tmp;
//         vector<vector<int>> s;
//         dfs(nums, 0, tmp, s);
//         return s;
//     }

//     void dfs(vector<int>& nums, int idx, vector<int> &tmp, vector<vector<int>> &res) {
//         if (idx == nums.size()) {
//             if (tmp.size() >= 2) {
//                 res.push_back(tmp);
//             }
//             return;
//         }
//         if (tmp.empty() || tmp.back() <= nums[idx]) {
//             tmp.push_back(nums[idx]);
//             dfs(nums, idx + 1, tmp, res);
//             tmp.pop_back();
//         } 
//         if (tmp.empty() || tmp.back() != nums[idx]) {
//             dfs(nums, idx + 1, tmp, res);
//         }
//     }
// };