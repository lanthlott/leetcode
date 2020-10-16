# 每周总结可以写在这里
# 双向BFS代码模板如下：
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        // iset存储序列或列表的所有元素，begin 和 end两个set分别存储从前往后的扩散状态和从后往前的扩散状态；
        unordered_set<string> iset, startset, endset;

        // 这个是最终结果，初始值为0；
        int res = 0; 

        // 将列表所有元素填入iset，用于后续的查找
        for(int i = 0; i < bank.size(); i++) {
            iset.insert(bank[i]);
        }

        // 先判断一次endWord在不在list里面，不在直接返回false，提前结束
        if(0 == bank.size() || iset.find(end) == iset.end()) return -1;

        // 初始化前端的扩散状态和后端的扩散状态，一开始前端的扩散状态就是beginword，后端的扩散状态就是endword
        startset.insert(start);
        endset.insert(end);

        // 从前端开始，进行下一步扩散
        while(!startset.empty()) {
            unordered_set<string> nextset;
            for(auto s : startset) {
                if(endset.find(s) != endset.end()) return res;  // 如果前端的扩散列表中的元素能在后端的扩散列表中找到，扩散结束，返回结果
                iset.erase(s);  // 及时删除iset中已经扩散到的元素，以防向回扩散
                for(int i = 0; i < s.size(); i++) {
                    string temp = s;
                    for(char ch = 'A'; ch <= 'Z'; ch++) {
                        temp[i] = ch;  // 每次更换s中的一个字母，从a更换到z
                        if(iset.find(temp) != iset.end()) {
                            nextset.insert(temp);  // 如果更换一个字母之后的元素在iset中，说明这个元素是下一次扩散的内容，将它添加到nextset中
                        }
                    }
                }
            }
            startset = nextset; // 前端扩散完毕，同时我们得到了下一次要扩散的内容，用它替换掉上一次扩散的内容，形成新的startset
            if(startset.size() > endset.size()) {
                swap(startset, endset);  // 把前端和后端较小的那个放到前端来，以后我们只需要从前端遍历即可
            }
            res++; // 每扩散完一次，不要忘了res + 1哦
        }
        return -1; // 全部扩散完都没找到endword，返回false；
    }
};