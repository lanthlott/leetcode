// ==============================  Ë«ÏòBFS ÀûÓÃset  ==============================
// 3
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> iset, startset, endset;
        int res = 0;
        for(int i = 0; i < bank.size(); i++) {
            iset.insert(bank[i]);
        }
        if(0 == bank.size() || iset.find(end) == iset.end()) return -1;
        startset.insert(start);
        endset.insert(end);
        while(!startset.empty()) {
            unordered_set<string> nextset;
            for(auto s : startset) {
                if(endset.find(s) != endset.end()) return res;
                iset.erase(s);
                for(int i = 0; i < s.size(); i++) {
                    string temp = s;
                    for(char ch = 'A'; ch <= 'Z'; ch++) {
                        temp[i] = ch;
                        if(iset.find(temp) != iset.end()) {
                            nextset.insert(temp);
                        }
                    }
                }
            }
            startset = nextset;
            if(startset.size() > endset.size()) {
                swap(startset, endset);
            }
            res++;
        }
        return -1;
    }
};