// ==============================  Œª‘ÀÀ„  ==============================
// 3
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        if(n <= 0) return 0;
        while(n != 0) {
            res++;
            n &= n - 1;
        }
        return res;
    }
};