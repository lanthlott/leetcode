// ==============================  DP  ==============================
// 1
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size(), len = 1;
        if(0 == size) return s;
        bool dp[s.size()][s.size()];
        memset(dp, false, sizeof(dp));
        string res = s.substr(0, 1);
        for(int  i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            if(i < size - 1 && s[i] == s[i + 1]){
                dp[i][i + 1] = true;
                res = s.substr(i, 2);
            }
        }
        for(int len = 3; len <= size; len++) {
            for(int i = 0; i < size - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                if(dp[i][j] && len > res.size()) {
                    res = s.substr(i, len);
                }
            }
        }
        return res;
    }
};

// ==============================  中心扩展法  ==============================
// 3
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int size = s.size(), left = 0, right = 0, len = 0;
//         for(int i = 0; i < size; i++) {
//             int len1 = f(s, i, i);
//             int len2 = f(s, i, i + 1);
//             if(len < max(len1, len2)) {
//                 len = max(len1, len2);
//                 left = i - (len - 1) / 2;
//                 right = i + len / 2;
//             }
//         }
//         string res = s.substr(left, right - left + 1);
//         return res;
//     }

// private:
//     int f(const string &s, int i, int j) {
//         int left = 0, right = 0;
//         while(i >= 0 && j < s.size() && s[i] == s[j]) {
//             i--;
//             j++;
//         }
//         left = i + 1;
//         right = j - 1;
//         return right - left + 1;
//     }
// };