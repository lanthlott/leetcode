// ==============================  Ë«ÏòBFS ÀûÓÃset  ==============================
// 3
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> iset, beginset, endset;
        int step = 0;
        for(int i = 0; i < wordList.size(); i++) {
            iset.insert(wordList[i]);
        }
        if(iset.find(endWord) == iset.end()) return 0;
        beginset.insert(beginWord);
        endset.insert(endWord);
        while(!beginset.empty()) {
            step++;
            unordered_set<string> nextset;
            for(auto s : beginset) {
                if(endset.find(s) != endset.end()) return step;
                iset.erase(s);
                for(int i = 0; i < s.size(); i++) {
                    string temp = s;
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        temp[i] = ch;
                        if(iset.find(temp) != iset.end()) {
                            nextset.insert(temp);
                        }
                    }
                }
            }
            beginset = nextset;
            if(beginset.size() > endset.size()) {
                swap(beginset, endset);
            }
        }
        return 0;
    }
};