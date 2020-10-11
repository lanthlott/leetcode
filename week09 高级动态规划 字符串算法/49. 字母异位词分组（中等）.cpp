// ==============================  ÅÅÐòºó¹þÏ£  ==============================
// 3
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> imap;
        int idx = 0;
        for(auto str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            if(imap.count(temp)) {
                res[imap[temp]].push_back(str);
            }
            else {
                imap[temp] = idx;
                vector<string> new1(1, str);
                res.push_back(new1);
                idx++;
            }
        }
        return res;
    }
};