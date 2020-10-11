// ==============================  ±©Á¦±éÀú  ==============================
// 3
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size(), idx = 0;
        if(size < 2) return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(int i = 0; i < size; i++) {
            if(res[idx][1] >= intervals[i][0] && res[idx][1] < intervals[i][1]) {
                res[idx][1] = intervals[i][1];
            }
            else if(res[idx][1] < intervals[i][0]) {
                res.push_back({intervals[i][0], intervals[i][1]});
                idx++;
            }
        }
        return res;
    }
};