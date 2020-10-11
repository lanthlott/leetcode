class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        if(digits.size() == 0) return {};
        DFS(digits, 0);
        return vec;
    }

private:
    void DFS(string& digits, int begin)
    {
        if(s.size() == digits.size()) vec.push_back(s);
        for(int i = 0; i <  mymap[digits[begin]].size(); i++)
        {
            s = s + mymap[digits[begin]][i];
            DFS(digits, begin + 1);
            s.pop_back();
        }
        return;
    }

private:
    string s = "";
    vector<string> vec;
    map<char, string> mymap = {{'2', "abc"} ,
                               {'3', "def"} ,
                               {'4', "ghi"} ,
                               {'5', "jkl"} ,
                               {'6', "mno"} ,
                               {'7', "pqrs"},
                               {'8', "tuv"} ,
                               {'9', "wxyz"}};
};