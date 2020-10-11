// ==============================  Ë«Ö¸Õë  ==============================
// 1
// class Solution {
// public:
//     bool validPalindrome(string s) {
//         int left = 0, right = s.size() - 1;
//         while(left < right) {
//             if(s[left] != s[right]) {
//                 return f(s, left + 1, right) || f(s, left, right - 1);
//             }
//             left++;
//             right--;
//         }
//         return true;
//     }

// private:
//     bool f(const string &s, int left, int right) {
//         while(left < right) {
//             if(s[left] != s[right]) {
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;
//     }
// };

// ==============================  ¼«¼ò´úÂë  =============================
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        for(; left < right && s[left] == s[right]; left++, right--);
        return f(s, left + 1, right) || f(s, left, right - 1);
    }

private:
    bool f(const string &s, int left, int right) {
        for(; left < right && s[left] == s[right]; left++, right--);
        return left >= right;
    }
};