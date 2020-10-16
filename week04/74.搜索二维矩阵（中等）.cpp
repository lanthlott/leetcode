class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {        
        int M = matrix.size() - 1;
        if(M < 0) return false;
        int N = matrix[0].size() - 1;
        if(N < 0) return false;

        int raw = -1;
        for(int i = 0; i <= M; i++)
        {
            if(target >= matrix[i][0] && target <= matrix[i][N])
            {
                raw = i;
                break;
            } 
        }
        if(-1 == raw) return false;
        int left = 0, right = N;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(target <= matrix[raw][mid]) right =mid;
            else left = mid + 1;
        }
        return matrix[raw][left] == target ? true : false;
    }
};