// ==============================  µÝ¹é  ==============================
// 1
class Solution {
public:
    bool isMatch(string s, string p) {
        return dfs(s, p, 0, 0);
        return false;
    }

private:
    bool dfs(string &s, string &p, int i, int j) {
        if(j == p.size()) return i == s.size();
        if(i == s.size()) {
            if((p.size() - j) % 2 == 1) return false;
            for(; j < p.size() - 1; j += 2) {
                if(p[j + 1] != '*') return false;
            }
            return true;
        }
        if(j < p.size() - 1 && p[j + 1] == '*') {
            if(p[j] != s[i] && '.' != p[j]) {
                return dfs(s, p, i, j + 2);
            }
            else {
                return dfs(s, p, i, j + 2) || dfs(s, p, i + 1, j);
            }
        }
        else {
            if(p[j] == s[i] || '.' == p[j]) {
                return dfs(s, p, i + 1, j + 1);
            }
            else {
                return false;
            }
        }
    }
};
// ==============================  ¼ò½à´úÂë  ==============================
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         if (p.empty()) return s.empty();            
//         bool first_match = (s[0] == p[0]) || (p[0] == '.');
//         if (p.size() >= 2 && p[1] == '*') {
//             if (s.empty())
//                 return isMatch(s, p.substr(2));
//             else
//                 return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));            
//         }
//         else {
//             if (s.empty())
//                 return false;
//             else {
//                 return first_match && isMatch(s.substr(1), p.substr(1));
//             }
//         }
//     }
// };