class Solution {
public:
    int countSubstrings(string s) {
        for(int i = 0; i < s.size(); i++)
        {
            f(s, i, i);
            f(s, i, i + 1);
        }
        return count;
    }

private:
    void f(string s, int i, int j)
    {
        while(i >= 0 && j < s.size() && s[i] == s[j]) // s[i] == s[j]������ں��治Ȼ��Խ�磡
        {
            count++;
            i--;
            j++;
        }
    }

private:
    int count = 0;
};