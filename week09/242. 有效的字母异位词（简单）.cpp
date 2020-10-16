// ==============================  ¹şÏ£ÉıÎ¬  ==============================
// 3
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> map_s, map_t;
        for(int i = 0; i < s.size(); i++) {
            map_s[s[i]]++;
            map_t[t[i]]++;
        }
        unordered_map<char, int>::iterator iter = map_s.begin();
        while(iter != map_s.end()) {
            if(map_t.find(iter->first) == map_t.end() || map_t[iter->first] != iter->second) {
                return false;
            }
            iter++;
        }
        return true;
    }
};